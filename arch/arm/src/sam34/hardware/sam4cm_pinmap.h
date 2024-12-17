/****************************************************************************
 * arch/arm/src/sam34/hardware/sam4cm_pinmap.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_ARM_SRC_SAM34_HARDWARE_SAM4CM_PINMAP_H
#define __ARCH_ARM_SRC_SAM34_HARDWARE_SAM4CM_PINMAP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "chip.h"
#include "sam_gpio.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* GPIO pin definitions *****************************************************/

/* Alternate Pin Functions.
 *
 * Alternative pin selections are provided with a numeric suffix like _1, _2,
 * etc. Drivers, however, will use the pin selection without the numeric
 * suffix. Additional definitions are required in the board.h file.  For
 * example, if we wanted the programmable clock output PCK0 on PA6, then the
 * following definition should appear in the board.h header file for that
 * board:
 *
 * #define GPIO_PCK0 GPIO_PCK0_1
 *
 * The driver will then automatically configure PA6 as the PCK0 pin.
 */

/* WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!!
 * Additional effort is required to select specific GPIO options such as
 * frequency, open-drain/push-pull, and pull-up/down!  Just the basics are
 * defined for most pins in this file.
 */

/* 12-bit Analog-to-Digital Converter (ADC) */

#define GPIO_ADC0_AD0     (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN12)
#define GPIO_ADC0_AD1     (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN4)
#define GPIO_ADC0_AD2     (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN5)
#define GPIO_ADC0_AD3     (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN13)

/* Programmable Clock Output */

#define GPIO_PCK0_1       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN6)
#define GPIO_PCK0_2       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN13)
#define GPIO_PCK1_1       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN17)
#define GPIO_PCK1_2       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN21)
#define GPIO_PCK2_1       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN18)
#define GPIO_PCK2_2       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN31)
#define GPIO_PCK2_3       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN3)

/* Pulse Width Modulation (PWM) */

#define GPIO_PWM0_FI      (GPIO_PERIPHC | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN9)
#define GPIO_PWM0_H_1     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN0)
#define GPIO_PWM0_H_2     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN0)
#define GPIO_PWM0_H_3     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN11)
#define GPIO_PWM0_H_4     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN23)
#define GPIO_PWM0_H_5     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN18)
#define GPIO_PWM0_L_1     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN19)
#define GPIO_PWM0_L_2     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN5)
#define GPIO_PWM0_L_3     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN0)
#define GPIO_PWM0_L_4     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN13)
#define GPIO_PWM1_H_1     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN1)
#define GPIO_PWM1_H_2     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN1)
#define GPIO_PWM1_H_3     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN12)
#define GPIO_PWM1_H_4     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN24)
#define GPIO_PWM1_H_5     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN19)
#define GPIO_PWM1_L_1     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN15)
#define GPIO_PWM1_L_2     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN12)
#define GPIO_PWM1_L_3     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN20)
#define GPIO_PWM1_L_4     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN1)
#define GPIO_PWM2_H_1     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN2)
#define GPIO_PWM2_H_2     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN13)
#define GPIO_PWM2_H_3     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN25)
#define GPIO_PWM2_H_4     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN4)
#define GPIO_PWM2_H_5     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN20)
#define GPIO_PWM2_L_1     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN30)
#define GPIO_PWM2_L_2     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN13)
#define GPIO_PWM2_L_3     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN2)
#define GPIO_PWM2_L_4     (GPIO_PERIPHC | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN16)
#define GPIO_PWM3_H_1     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN14)
#define GPIO_PWM3_H_2     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN7)
#define GPIO_PWM3_H_3     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN14)
#define GPIO_PWM3_H_4     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN21)
#define GPIO_PWM3_H_5     (GPIO_PERIPHC | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN17)
#define GPIO_PWM3_L_1     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN22)
#define GPIO_PWM3_L_2     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN3)
#define GPIO_PWM3_L_3     (GPIO_PERIPHC | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN15)

/* Static Memory Controller (SMC) */

#define GPIO_SMC_A0       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN18)
#define GPIO_SMC_A1       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN19)
#define GPIO_SMC_A2       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN20)
#define GPIO_SMC_A3       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN21)
#define GPIO_SMC_A4       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN22)
#define GPIO_SMC_A5       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN23)
#define GPIO_SMC_A6       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN24)
#define GPIO_SMC_A7       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN25)
#define GPIO_SMC_A8       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN26)
#define GPIO_SMC_A9       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN27)
#define GPIO_SMC_A10      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN28)
#define GPIO_SMC_A11      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN29)
#define GPIO_SMC_A12      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN30)
#define GPIO_SMC_A13      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN31)
#define GPIO_SMC_A14      (GPIO_PERIPHC | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN18)
#define GPIO_SMC_A15      (GPIO_PERIPHC | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN19)
#define GPIO_SMC_A16      (GPIO_PERIPHC | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN20)
#define GPIO_SMC_A17      (GPIO_PERIPHC | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN0)
#define GPIO_SMC_A18      (GPIO_PERIPHC | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN1)
#define GPIO_SMC_A19      (GPIO_PERIPHC | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN23)
#define GPIO_SMC_A20      (GPIO_PERIPHC | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN24)
#define GPIO_SMC_A21      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN16)
#define GPIO_SMC_A22      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN17)
#define GPIO_SMC_A23      (GPIO_PERIPHC | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN25)
#define GPIO_SMC_D0       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN0)
#define GPIO_SMC_D1       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN1)
#define GPIO_SMC_D2       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN2)
#define GPIO_SMC_D3       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN3)
#define GPIO_SMC_D4       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN4)
#define GPIO_SMC_D5       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN5)
#define GPIO_SMC_D6       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN6)
#define GPIO_SMC_D7       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN7)
#define GPIO_SMC_NANDALE  (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN16)
#define GPIO_SMC_NANDCLE  (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN17)
#define GPIO_SMC_NANDOE   (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN9)
#define GPIO_SMC_NANDWE   (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN10)
#define GPIO_SMC_NCS0     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN14)
#define GPIO_SMC_NCS1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN15)
#define GPIO_SMC_NCS2     (GPIO_PERIPHC | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN22)
#define GPIO_SMC_NCS3     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN12)
#define GPIO_SMC_NRD      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN11)
#define GPIO_SMC_NWAIT    (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN13)
#define GPIO_SMC_NWE      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN8)

/* Serial Peripheral Interface (SPI) */

#define GPIO_SPI0_MISO    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN12)
#define GPIO_SPI0_MOSI    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN13)
#define GPIO_SPI0_NPCS0   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN11)
#define GPIO_SPI0_NPCS1_1 (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN31)
#define GPIO_SPI0_NPCS1_2 (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN14)
#define GPIO_SPI0_NPCS1_3 (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN9)
#define GPIO_SPI0_NPCS1_4 (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN4)
#define GPIO_SPI0_NPCS2_1 (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN10)
#define GPIO_SPI0_NPCS2_2 (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN30)
#define GPIO_SPI0_NPCS2_3 (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN2)
#define GPIO_SPI0_NPCS3_1 (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN22)
#define GPIO_SPI0_NPCS3_2 (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN3)
#define GPIO_SPI0_NPCS3_3 (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN5)
#define GPIO_SPI0_SPCK    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN14)

/* Synchronous Serial Controller (SSC) */

#define GPIO_SSC_RD       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN18)
#define GPIO_SSC_RF       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN20)
#define GPIO_SSC_RK       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN19)
#define GPIO_SSC_TD       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN17)
#define GPIO_SSC_TF       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN15)
#define GPIO_SSC_TK       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN16)

/* Timer/Counters (TC) */

#define GPIO_TC0_TCLK     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN4)
#define GPIO_TC0_TIOA     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN0)
#define GPIO_TC0_TIOB     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN1)
#define GPIO_TC1_TCLK     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN28)
#define GPIO_TC1_TIOA     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN15)
#define GPIO_TC1_TIOB     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN16)
#define GPIO_TC2_TCLK     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN29)
#define GPIO_TC2_TIOA     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN26)
#define GPIO_TC2_TIOB     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN27)
#define GPIO_TC3_TCLK     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN25)
#define GPIO_TC3_TIOA     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN23)
#define GPIO_TC3_TIOB     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN24)
#define GPIO_TC4_TCLK     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN28)
#define GPIO_TC4_TIOA     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN26)
#define GPIO_TC4_TIOB     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN27)
#define GPIO_TC5_TCLK     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN31)
#define GPIO_TC5_TIOA     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN29)
#define GPIO_TC5_TIOB     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN30)

/* Two Wire Interface (TWI) */

#define GPIO_TWI0_CK      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN4)
#define GPIO_TWI0_D       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN3)
#define GPIO_TWI1_CK      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN5)
#define GPIO_TWI1_D       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN4)

/* Universal Asynchronous Receiver Transceiver (UART) */

#define GPIO_UART0_RXD    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN4)
#define GPIO_UART0_TXD    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN5)
#define GPIO_UART1_RXD    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN1)
#define GPIO_UART1_TXD    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN0)

/* Universal Synchronous Asynchronous Receiver Transmitter (USART) */

#define GPIO_USART0_CTS   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN8)
#define GPIO_USART0_RTS   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN7)
#define GPIO_USART0_RXD   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN5)
#define GPIO_USART0_SCK   (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN2)
#define GPIO_USART0_TXD   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN6)

#define GPIO_USART1_CTS   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN25)
#define GPIO_USART1_DCD   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN26)
#define GPIO_USART1_DSR   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN28)
#define GPIO_USART1_DTR   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN27)
#define GPIO_USART1_RI    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN29)

#define GPIO_USART1_RTS   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN24)
#define GPIO_USART1_RXD   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN21)
#define GPIO_USART1_SCK   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN23)
#define GPIO_USART1_TXD   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN22)

/* Segment LCD Controller (SLCDC) */

/* TODO: add rest of segment pins */

#define GPIO_SLCDC_COM0   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN0)
#define GPIO_SLCDC_COM1   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN1)
#define GPIO_SLCDC_COM2   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN2)
#define GPIO_SLCDC_COM3   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN3)
#define GPIO_SLCDC_COM4   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN4)
#define GPIO_SLCDC_COM5   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN5)

#define GPIO_SLCDC_SEG0   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN6)
#define GPIO_SLCDC_SEG1   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN7)
#define GPIO_SLCDC_SEG2   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN8)
#define GPIO_SLCDC_SEG3   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN9)
#define GPIO_SLCDC_SEG4   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN10)
#define GPIO_SLCDC_SEG5   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN11)
#define GPIO_SLCDC_SEG6   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN12)
#define GPIO_SLCDC_SEG7   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN13)
#define GPIO_SLCDC_SEG8   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN14)
#define GPIO_SLCDC_SEG9   (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN15)
#define GPIO_SLCDC_SEG10  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN16)
#define GPIO_SLCDC_SEG11  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN17)
#define GPIO_SLCDC_SEG12  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN18)
#define GPIO_SLCDC_SEG13  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN19)
#define GPIO_SLCDC_SEG14  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN20)
#define GPIO_SLCDC_SEG15  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN21)
#define GPIO_SLCDC_SEG16  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN22)
#define GPIO_SLCDC_SEG17  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN23)
#define GPIO_SLCDC_SEG18  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN24)
#define GPIO_SLCDC_SEG19  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN25)
#define GPIO_SLCDC_SEG20  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN26)
#define GPIO_SLCDC_SEG21  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN27)
#define GPIO_SLCDC_SEG22  (GPIO_PERIPHD | GPIO_PORT_PIOA | GPIO_PIN28)

/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************
 * Public Data
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_ARM_SRC_SAM34_HARDWARE_SAM4S_PINMAP_H */
