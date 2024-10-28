#ifndef REGIONS_FRDM_K32L3A6_H
#define REGIONS_FRDM_K32L3A6_H


//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------
//------ With VS Code: Open Preview for Configuration Wizard -------------------

// <n> Auto-generated using information from packs
// <i> Device Family Pack (DFP):   NXP::K32L3A60_DFP@19.0.0
// <i> Board Support Pack (BSP):   NXP::FRDM-K32L3A6_BSP@19.0.0

// <h> ROM Configuration
// =======================
// <h> __ROM0 (is rx memory: PROGRAM_FLASH_cm4 from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x00000000
//   <i> Contains Startup and Vector Table
#define __ROM0_BASE 0x00000000
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x00100000
#define __ROM0_SIZE 0x00100000
// </h>

// </h>

// <h> RAM Configuration
// =======================
// <h> __RAM0 (is rw memory: FLEX_RAM from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x48000000
//   <i> Contains uninitialized RAM, Stack, and Heap
#define __RAM0_BASE 0x48000000
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x00001000
#define __RAM0_SIZE 0x00001000
// </h>

// <h> __RAM1 (is rw memory: SRAM_DTC_cm4 from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x20000000
#define __RAM1_BASE 0x20000000
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x00030000
#define __RAM1_SIZE 0x00030000
// </h>

// <h> __RAM2 (is rw memory: SRAM_ITC_cm4 from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x08000000
#define __RAM2_BASE 0x08000000
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x00010000
#define __RAM2_SIZE 0x00010000
// </h>

// </h>

// <h> Stack / Heap Configuration
//   <o0> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
//   <o1> Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
#define __STACK_SIZE 0x00000200
#define __HEAP_SIZE 0x00000C00
// </h>

// <n> Resources that are not allocated to linker regions
// <i> rw RAM:   USB_RAM from DFP:  BASE: 0x48010000  SIZE: 0x0800


#endif /* REGIONS_FRDM_K32L3A6_H */
