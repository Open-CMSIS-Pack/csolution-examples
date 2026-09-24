/*
 * Copyright (c) 2026 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * Common stdout retargeting implementation for both the Secure and
 * Non-secure parts of the application.
 */

#include <stdint.h>

#include "retarget_stdout.h"

/* UART0 memory-mapped registers used for polling-based output. */
#define UART0_BASE 0x40004000U
#define UART0_DATA  (*(volatile uint32_t *)(UART0_BASE + 0x000U))
#define UART0_STATE (*(volatile uint32_t *)(UART0_BASE + 0x004U))
#define UART0_CTRL  (*(volatile uint32_t *)(UART0_BASE + 0x008U))
#define UART0_BAUDDIV (*(volatile uint32_t *)(UART0_BASE + 0x010U))

/* Status and control bits required by the transmit path. */
#define UART_TX_FULL (1UL << 0)
#define UART_TX_ENABLE (1UL << 0)

int stdout_putchar(int ch) {
  /* Initialize the UART on first use, preserving an existing setup. */
  if ((UART0_CTRL & UART_TX_ENABLE) == 0U) {
    UART0_BAUDDIV = 16U;
    UART0_CTRL = UART_TX_ENABLE;
  }

  /* Wait until the transmit FIFO has room for the next character. */
  while ((UART0_STATE & UART_TX_FULL) != 0U) {
  }

  UART0_DATA = (uint32_t)(uint8_t)ch;
  return ch;
}
