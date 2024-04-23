/*---------------------------------------------------------------------------
 * Copyright (c) 2024 Arm Limited (or its affiliates).
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *      Name:    MyMain.c
 *      Purpose: Simple RTX Example
 *
 *---------------------------------------------------------------------------*/

#include "main.h"
#include "cmsis_os2.h"

/* Global variables*/
static uint32_t Seconds;

/*---------------------------------------------------------------------------
  app_thread: increment global variable Seconds every 1000ms
 *---------------------------------------------------------------------------*/
static __NO_RETURN void app_thread (void *argument) {
  (void)argument;

  for (;;) {
    osDelay(1000U);
    Seconds++;
  }
}

/*---------------------------------------------------------------------------
 * Application entry point
 *---------------------------------------------------------------------------*/
int32_t app_main (void) {

  osKernelInitialize();
  osThreadNew(app_thread, NULL, NULL);
  osKernelStart();

  return 0;
}
