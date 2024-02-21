;/*
; * Copyright (c) 2023 Arm Limited
; *
; * Licensed under the Apache License, Version 2.0 (the "License");
; * you may not use this file except in compliance with the License.
; * You may obtain a copy of the License at
; *
; *     http://www.apache.org/licenses/LICENSE-2.0
; *
; * Unless required by applicable law or agreed to in writing, software
; * distributed under the License is distributed on an "AS IS" BASIS,
; * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; * See the License for the specific language governing permissions and
; * limitations under the License.
; */

/* Linker script to configure memory regions. */
/* This file will be run trough the pre-processor. */

#include "region_defs.h"

#define __STACKSEAL_SIZE (8)

MEMORY
{
  FLASH (rx)  : ORIGIN = S_CODE_START, LENGTH = S_CODE_SIZE
  RAM   (rwx) : ORIGIN = S_DATA_START, LENGTH = S_DATA_SIZE
}

/* Linker script to place sections and symbol values. Should be used together
 * with other linker script that defines memory regions FLASH and RAM.
 * It references following symbols, which must be defined in code:
 *   Reset_Handler : Entry of reset handler
 *
 * It defines following symbols, which code can use without definition:
 *   __exidx_start
 *   __exidx_end
 *   __copy_table_start__
 *   __copy_table_end__
 *   __zero_table_start__
 *   __zero_table_end__
 *   __etext
 *   __data_start__
 *   __preinit_array_start
 *   __preinit_array_end
 *   __init_array_start
 *   __init_array_end
 *   __fini_array_start
 *   __fini_array_end
 *   __data_end__
 *   __bss_start__
 *   __bss_end__
 *   __end__
 *   end
 *   __HeapBase
 *   __HeapLimit
 *   __StackLimit
 *   __StackTop
 *   __stack
 *   __Vectors_End
 *   __Vectors_Size
 */
ENTRY(Reset_Handler)

SECTIONS
{
	.text :
    {
        KEEP(*(.vectors))
        PROVIDE(__Vectors_End = .);
        PROVIDE(__end__ = .);

        *(.text*)

        KEEP(*(.init))
        KEEP(*(.fini))

        /* .ctors */
        *crtbegin.o(.ctors)
        *crtbegin?.o(.ctors)
        *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
        *(SORT(.ctors.*))
        *(.ctors)

        /* .dtors */
         *crtbegin.o(.dtors)
         *crtbegin?.o(.dtors)
         *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
         *(SORT(.dtors.*))
         *(.dtors)

        *(.rodata*)

        KEEP(*(.eh_frame*))
    } > FLASH
	PROVIDE(__Vectors_Size = __Vectors_End - __Vectors);


#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
	/*
     * Place the CMSE Veneers (containing the SG instruction) after the code, in a
     * separate 32 bytes aligned region so that the SAU can programmed to just set
     * this region as Non-Secure Callable. The maximum size of this executable
     * region makes it only used the space left over by the ER_CODE region
     * so that you can rely on code+veneer size combined will not exceed the
     * S_CODE_SIZE value. We also substract from the available space the
     * area used to align this section on 32 bytes boundary (for SAU conf).
     */
    .gnu.sgstubs : ALIGN(32)
    {
        *(.gnu.sgstubs*)
    } > FLASH
    . = ALIGN(32);
    Image$$ER_CODE_CMSE_VENEER$$Base = ADDR(.gnu.sgstubs);
    Image$$ER_CODE_CMSE_VENEER$$Limit = .;
    Image$$ER_CODE_CMSE_VENEER$$Length = Image$$ER_CODE_CMSE_VENEER$$Limit - Image$$ER_CODE_CMSE_VENEER$$Base;

    /* Make sure veneers fit into code memory */
    ASSERT(((S_CODE_START + S_CODE_SIZE) > Image$$ER_CODE_CMSE_VENEER$$Limit), "Veneer region does not fit into code memory")
#endif

	.data : ALIGN(4)
    {
        *(vtable)
        *(.data*)

        . = ALIGN(4);
        /* preinit data */
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP(*(.preinit_array))
        PROVIDE_HIDDEN (__preinit_array_end = .);

        . = ALIGN(4);
        /* init data */
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        PROVIDE_HIDDEN (__init_array_end = .);

        . = ALIGN(4);
        /* finit data */
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array))
        PROVIDE_HIDDEN (__fini_array_end = .);

        KEEP(*(.jcr*))
        . = ALIGN(4);
        /* All data end */
        PROVIDE(__data_end = .);

    } > RAM AT> FLASH
	PROVIDE(__data_start = ADDR(.data));
	PROVIDE(__data_source = LOADADDR(.data));
	PROVIDE(__data_size = __data_end - __data_start);

	/* Thread local initialized data. */
	.tdata :  {
		*(.tdata .tdata.* .gnu.linkonce.td.*)
		PROVIDE(__data_end = .);
		PROVIDE(__tdata_end = .);
	} >RAM AT>FLASH :tls
	PROVIDE(__tls_base = ADDR(.tdata));
	PROVIDE(__tls_align = MAX(ALIGNOF(.tdata),ALIGNOF(.tbss)));
	PROVIDE(__arm32_tls_tcb_offset = MAX(8, __tls_align));
	PROVIDE(__arm64_tls_tcb_offset = MAX(16, __tls_align));

	.bss : ALIGN(4)
    {
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        PROVIDE(__bss_end = .);
    } > RAM
	PROVIDE(__bss_start = ADDR(.bss));
	PROVIDE(__bss_size = __bss_end - __bss_start);

	.tbss (NOLOAD) : {
		*(.tbss .tbss.* .gnu.linkonce.tb.*)
		*(.tcommon)
		PROVIDE(__tls_end = .);
		PROVIDE(__tbss_end = .);
	} >RAM AT>RAM :tls

	.stack : ALIGN(8)
    {
        PROVIDE(__StackLimit = .);
        KEEP(*(.stack*))
        . += STACK_SIZE - __STACKSEAL_SIZE;
        PROVIDE(__StackTop = .);
    } > RAM

    .msp_stack_seal_res :
    {
        . += __STACKSEAL_SIZE;
    } > RAM
    PROVIDE(__StackSeal = ADDR(.msp_stack_seal_res));

    .heap : ALIGN(8)
    {
        PROVIDE(__end__ = .);
        PROVIDE(end = .);
        PROVIDE(__HeapBase = .);
        . += HEAP_SIZE;
        PROVIDE(__HeapLimit = .);
        PROVIDE(__heap_limit = .); /* Add for _sbrk */
    } > RAM

    /* Set stack top to end of the used RAM section, and stack limit move down by
     * size of stack_dummy section */
    PROVIDE(__stack = __StackTop);
	PROVIDE(__stack_limit = __stack - STACK_SIZE);

	/* Check if data + heap + stack exceeds RAM limit */
	ASSERT(__StackTop <= (S_DATA_START + S_DATA_SIZE), "Secure RAM region overflowed")
}
