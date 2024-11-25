/****************************************************************************
 * boards/arm/lpc17xx_40xx/lpc4088-devkit/include/board.h
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

#ifndef __BOARDS_ARM_LPC17XX_40XX_LPC4088_DEVKIT_INCLUDE_BOARD_H
#define __BOARDS_ARM_LPC17XX_40XX_LPC4088_DEVKIT_INCLUDE_BOARD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdbool.h>

#if defined(CONFIG_ARCH_IRQBUTTONS) && defined(CONFIG_LPC17_40_GPIOIRQ)
#  include <nuttx/irq.h>
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Clocking *****************************************************************/

/* NOTE:
 * The following definitions require lpc17_40_syscon.h.
 * It is not included here because the including C file may not have that
 * file in its include path.
 */

#define BOARD_XTAL_FREQUENCY       (12000000)            /* XTAL oscillator frequency */
#define BOARD_OSCCLK_FREQUENCY     BOARD_XTAL_FREQUENCY  /* Main oscillator frequency */
#define BOARD_RTCCLK_FREQUENCY     (32768)               /* RTC oscillator frequency */
#define BOARD_INTRCOSC_FREQUENCY   (4000000)             /* Internal RC oscillator frequency */
#define BOARD_WDTOSC_FREQUENCY     (500000)              /* WDT oscillator frequency */

/* This is the clock setup we configure for:
 *
 * SYSCLK = BOARD_OSCCLK_FREQUENCY = 12MHz -> Select Main oscillator for
 *          source
 * PLL0CLK = (10 * SYSCLK) / 1 = 120MHz -> PLL0 multipler=10, pre-divider=1
 * CCLCK = 120MHz  -> CCLK divider = 1
 */

#define LPC17_40_CCLK         120000000  /* 120Mhz */
#define BOARD_PCLKDIV         2          /* Peripheral clock = LPC17_40_CCLK/2 */
#define BOARD_PCLK_FREQUENCY (LPC17_40_CCLK / BOARD_PCLKDIV)

/* Select the main oscillator as the frequency source.
 *  SYSCLK is then the frequency of the main oscillator.
 *
 * If BOARD_XTAL_FREQUENCY > 15000000, then the SCS OSCRS bit (bit 4)
 * should also be set in the BOARD_SCS_VALUE.
 */

#undef CONFIG_LPC17_40_MAINOSC
#define CONFIG_LPC17_40_MAINOSC       1
#define BOARD_SCS_VALUE            SYSCON_SCS_OSCEN

/* Select the main oscillator and CCLK divider.
 * The output of the divider is CCLK.
 * The input to the divider (PLLCLK) will be determined by the PLL output.
 */

#define BOARD_CCLKSEL_DIVIDER      1
#define BOARD_CCLKSEL_VALUE        (BOARD_CCLKSEL_DIVIDER | SYSCON_CCLKSEL_CCLKSEL)

/* PLL0.  PLL0 is used to generate the CPU clock (PLLCLK).
 *
 *  Source clock:               Main oscillator
 *  PLL0 Multiplier value (M):  10
 *  PLL0 Pre-divider value (P): 1
 *
 *  PLL0CLK = (M * SYSCLK) = 120MHz
 */

#undef CONFIG_LPC17_40_PLL0
#define CONFIG_LPC17_40_PLL0          1
#define BOARD_CLKSRCSEL_VALUE      SYSCON_CLKSRCSEL_MAIN

#define BOARD_PLL0CFG_MSEL         10
#define BOARD_PLL0CFG_PSEL         1
#define BOARD_PLL0CFG_VALUE \
  (((BOARD_PLL0CFG_MSEL-1) << SYSCON_PLLCFG_MSEL_SHIFT) | \
   ((BOARD_PLL0CFG_PSEL-1) << SYSCON_PLLCFG_PSEL_SHIFT))

/* PLL1 : PLL1 is used to generate clock for the USB */

#undef  CONFIG_LPC17_40_PLL1
#define BOARD_PLL1CFG_MSEL        4
#define BOARD_PLL1CFG_PSEL        2
#define BOARD_PLL1CFG_VALUE \
  (((BOARD_PLL1CFG_MSEL-1) << SYSCON_PLLCFG_MSEL_SHIFT) | \
   ((BOARD_PLL1CFG_PSEL-1) << SYSCON_PLLCFG_PSEL_SHIFT))

#ifdef CONFIG_LPC17_40_EMC

/* EMC clock selection.
 *
 * The EMC clock should not be driven above 80MHz.
 * As a result the EMC uses the CPU clock divided by two.
 */

#  define BOARD_EMCCLKSEL_DIVIDER  2
#  define BOARD_EMCCLKSEL_VALUE    SYSCON_EMCCLKSEL_CCLK_DIV2
#  define LPC17_40_EMCCLK             (LPC17_40_CCLK / BOARD_EMCCLKSEL_DIVIDER)
#endif

#if defined(CONFIG_LPC17_40_USBHOST) || (CONFIG_LPC17_40_USBDEV)

/* USB divider.
 * The output of the PLL is used as the USB clock
 *
 *  USBCLK = PLL1CLK = (SYSCLK * 4)  = 48MHz
 */

#  define BOARD_USBCLKSEL_DIVIDER  1
#  define BOARD_USBCLKSEL_VALUE    (SYSCON_USBCLKSEL_USBDIV_DIV1 | \
                                    SYSCON_USBCLKSEL_USBSEL_PLL1)
#endif

/* FLASH Configuration */

#undef  CONFIG_LPC17_40_FLASH
#define CONFIG_LPC17_40_FLASH         1

/* Flash access use 6 CPU clocks - Safe for any allowed conditions */

#define BOARD_FLASHCFG_VALUE       (SYSCON_FLASHCFG_TIM_5 | 0x03a)

/* Ethernet configuration */

#define ETH_MCFG_CLKSEL_DIV        ETH_MCFG_CLKSEL_DIV48

#ifdef CONFIG_LPC17_40_SDCARD

/* SDIO dividers.
 * Note that slower clocking is required when DMA is disabled in order to
 * avoid RX overrun/TX underrun errors due to delayed responses to
 * service FIFOs in interrupt driven mode.
 * SDCARD_CLOCK=PCLK/(2*(SDCARD_CLKDIV+1))
 */

#  define SDCARD_CLKDIV_INIT       74   /* 400Khz  */
#  define SDCARD_INIT_CLKDIV       (SDCARD_CLKDIV_INIT)

#  define SDCARD_NORMAL_CLKDIV     1    /* DMA ON:  SDCARD_CLOCK=15MHz */
#define SDCARD_SLOW_CLKDIV         14   /* DMA OFF: SDCARD_CLOCK=2MHz */

#  ifdef CONFIG_SDIO_DMA
#    define SDCARD_MMCXFR_CLKDIV   (SDCARD_NORMAL_CLKDIV)
#  else
#    define SDCARD_MMCXFR_CLKDIV   (SDCARD_SLOW_CLKDIV)
#  endif

#  ifdef CONFIG_SDIO_DMA
#    define SDCARD_SDXFR_CLKDIV    (SDCARD_NORMAL_CLKDIV)
#  else
#    define SDCARD_SDXFR_CLKDIV    (SDCARD_SLOW_CLKDIV)
#  endif
#endif

/* Set EMC delay values:
 *
 * CMDDLY: Programmable delay value for EMC outputs in command delayed
 *   mode.  The delay amount is roughly CMDDLY * 250 picoseconds.
 * FBCLKDLY: Programmable delay value for the feedback clock that controls
 *   input data sampling.  The delay amount is roughly (FBCLKDLY+1) * 250
 *   picoseconds.
 * CLKOUT0DLY: Programmable delay value for the CLKOUT0 output. This would
 *   typically be used in clock delayed mode.  The delay amount is roughly
 *  (CLKOUT0DLY+1) * 250 picoseconds.
 * CLKOUT1DLY: Programmable delay value for the CLKOUT1 output. This would
 *  typically be used in clock delayed mode.  The delay amount is roughly
 *  (CLKOUT1DLY+1) * 250 picoseconds.
 *
 * Optimal for NOR: {1,1,1,1}
 * Needed for NAND and SDRAM: {17,1,2,1}
 */

#ifdef CONFIG_LPC17_40_EMC
#if defined(CONFIG_LPC17_40_EXTNAND) || defined(CONFIG_LPC17_40_EXTDRAM)
#  define BOARD_CMDDLY             17
#  define BOARD_FBCLKDLY           17
#  define BOARD_CLKOUT0DLY         1
#  define BOARD_CLKOUT1DLY         1
#else
#  define BOARD_CMDDLY             1
#  define BOARD_FBCLKDLY           1
#  define BOARD_CLKOUT0DLY         1
#  define BOARD_CLKOUT1DLY         1
#endif
#endif

/* LED definitions **********************************************************/

/* If CONFIG_ARCH_LEDS is not defined, then the user can control the LEDs in
 * any way.  The following definitions are used to access individual LEDs.
 *
 * LED1 : Connected to P2[26]
 * LED2 : Connected to P2[27]
 *
 * These LEDs are connected to ground so a high output value will illuminate
 * them.
 */

/* LED index values for use with board_userled() */

#define BOARD_LED1                 0
#define BOARD_LED2                 1
#define BOARD_NLEDS                2

/* LED bits for use with board_userled_all() */

#define BOARD_LED1_BIT             (1 << BOARD_LED1)
#define BOARD_LED2_BIT             (1 << BOARD_LED2)

/* If CONFIG_ARCH_LEDs is defined, then NuttX will control the two LEDs
 * on the LPC4088 OEM Board.
 * The following definitions describe how NuttX controls the LEDs:
 */

                                /* LED1 LED2 LED3 LED4                 */
#define LED_STARTED          0  /*  OFF  OFF  OFF  OFF                 */
#define LED_HEAPALLOCATE     1  /*  ON   OFF  OFF  OFF                 */
#define LED_IRQSENABLED      2  /*  OFF   ON  OFF  OFF                 */
#define LED_STACKCREATED     3  /*  ON    ON  OFF  OFF                 */
#define LED_INIRQ            4  /*  LED3 glows, on while in interrupt  */
#define LED_SIGNAL           4  /*  LED3 glows, on while in signal handler */
#define LED_ASSERTION        4  /*  LED3 glows, on while in assertion  */
#define LED_PANIC            4  /*  LED3 Flashes at 2Hz                */
#define LED_IDLE             5  /*  LED4 glows: ON while active
                                 *              OFF while sleeping
                                 */

/* Button definitions *******************************************************/

/* The LPC4088 Developer's Kit supports several buttons.
 * All have external pullup resistors.
 * When closed, the pins will be pulled to ground.
 * So the buttons will read "1" when open and "0" when closed.
 * All are capable of generating interrupts.
 *
 * USER1           -- Connected to P2[10]
 *
 * Joystick:
 *
 * JOY_A           -- Connected to P2[23]
 * JOY_B           -- Connected to P2[25]
 * JOY_C           -- Connected to P2[26]
 * JOY_D           -- Connected to P2[27]
 * JOY_CTR         -- Connected to P2[22]
 *
 * For the interrupting buttons, interrupts are generated on both edges
 * (press and release).
 */

#define BOARD_BUTTON_USER1         0

#define BOARD_JOYSTICK_A           1
#define BOARD_JOYSTICK_B           2
#define BOARD_JOYSTICK_C           3
#define BOARD_JOYSTICK_D           4
#define BOARD_JOYSTICK_CTR         5

#define NUM_BUTTONS                6

#define BOARD_BUTTON_USER1_BIT     (1 << BOARD_BUTTON_USER1)

#define BOARD_JOYSTICK_A_BIT       (1 << BOARD_JOYSTICK_A)
#define BOARD_JOYSTICK_B_BIT       (1 << BOARD_JOYSTICK_B)
#define BOARD_JOYSTICK_C_BIT       (1 << BOARD_JOYSTICK_C)
#define BOARD_JOYSTICK_D_BIT       (1 << BOARD_JOYSTICK_D)
#define BOARD_JOYSTICK_CTR_BIT     (1 << BOARD_JOYSTICK_CTR)

/* Alternate pin selections *************************************************/

/* UART0:
 *
 * TX    --- Connected to P0[2]
 * RX    --- Connected to P0[3]
 */

#define GPIO_UART0_TXD             GPIO_UART0_TXD_2
#define GPIO_UART0_RXD             GPIO_UART0_RXD_2

/* UART1:
 *
 * All pin options are controlled by jumpers on the board.
 * RXD is set with JP12, TXD is set with JP13, modem control lines are set
 * with JP11.
 *
 * RTS   --- Connected to P3[30]
 * RI    --- Connected to P3[22]
 * DSR   --- Connected to P3[20]
 * DCD   --- Connected to P3[19]
 * CTS   --- Connected to P3[18]
 * DTR   --- Connected to P3[21]
 * TXD   --- Connected to P3[16]
 * RXD   --- Connected to P3[17]
 */

#define GPIO_UART1_RTS             GPIO_UART1_RTS_4
#define GPIO_UART1_RI              GPIO_UART1_RI_3
#define GPIO_UART1_DSR             GPIO_UART1_DSR_3
#define GPIO_UART1_DCD             GPIO_UART1_DCD_3
#define GPIO_UART1_CTS             GPIO_UART1_CTS_4
#define GPIO_UART1_DTR             GPIO_UART1_DTR_3
#define GPIO_UART1_TXD             GPIO_UART1_TXD_3
#define GPIO_UART1_RXD             GPIO_UART1_RXD_3

/* MCI-SDIO:
 *
 * D0    --- Connected to P1[6]
 * D1    --- Connected to P1[7]
 * D2    --- Connected to P1[11]
 * D3    --- Connected to P1[12]
 * CLK   --- Connected to P1[2]
 * CMD   --- Connected to P1[3]
 */

#define GPIO_SD_DAT0               GPIO_SD_DAT0_2
#define GPIO_SD_DAT1               GPIO_SD_DAT1_1
#define GPIO_SD_DAT2               GPIO_SD_DAT2_1
#define GPIO_SD_DAT3               GPIO_SD_DAT3_1
#define GPIO_SD_CLK                GPIO_SD_CLK_2
#define GPIO_SD_CMD                GPIO_SD_CMD_2

/* Ethernet:
 * MDC   --- Connected to P1[16]
 * MDIO  --- Connected to P1[17]
 */

#define GPIO_ENET_MDC     GPIO_ENET_MDC_1
#define GPIO_ENET_MDIO    GPIO_ENET_MDIO_1

/* External LCD is currently untested.
 * These pins will probably need to be updated before using the LCD.
 */

#if 0
/* LCD R:
 *
 * VD0   --- Connected to P0[4]
 * VD1   --- Connected to P0[5]
 * VD2   --- Connected to P4[28]
 * VD3   --- Connected to P4[29]
 * VD4   --- Connected to P2[6]
 * VD5   --- Connected to P2[7]
 * VD6   --- Connected to P2[8]
 * VD7   --- Connected to P2[9]
 */

#define GPIO_LCD_VD0                GPIO_LCD_VD0_1
#define GPIO_LCD_VD1                GPIO_LCD_VD1_1
#define GPIO_LCD_VD2                GPIO_LCD_VD2_2
#define GPIO_LCD_VD3                GPIO_LCD_VD3_3
#define GPIO_LCD_VD4                GPIO_LCD_VD4_1
#define GPIO_LCD_VD5                GPIO_LCD_VD5_1
#define GPIO_LCD_VD6                GPIO_LCD_VD6_2
#define GPIO_LCD_VD7                GPIO_LCD_VD7_2

/* LCD G:
 *
 * VD8    --- Connected to P0[6]
 * VD9    --- Connected to P0[7]
 * VD10   --- Connected to P1[20]
 * VD11   --- Connected to P1[21]
 * VD12   --- Connected to P1[22]
 * VD13   --- Connected to P1[23]
 * VD14   --- Connected to P1[24]
 * VD15   --- Connected to P1[25]
 */

#define GPIO_LCD_VD8                GPIO_LCD_VD8_1
#define GPIO_LCD_VD9                GPIO_LCD_VD9_1
#define GPIO_LCD_VD10               GPIO_LCD_VD10_1
#define GPIO_LCD_VD11               GPIO_LCD_VD11_1
#define GPIO_LCD_VD12               GPIO_LCD_VD12_1
#define GPIO_LCD_VD13               GPIO_LCD_VD13_1
#define GPIO_LCD_VD14               GPIO_LCD_VD14_1
#define GPIO_LCD_VD15               GPIO_LCD_VD15_1

/* LCD B:
 *
 * VD16   --- Connected to P0[8]
 * VD17   --- Connected to P0[9]
 * VD18   --- Connected to P2[12]
 * VD19   --- Connected to P2[13]
 * VD20   --- Connected to P1[26]
 * VD21   --- Connected to P1[27]
 * VD22   --- Connected to P1[28]
 * VD23   --- Connected to P1[29]
 *
 * DCLK   --- Connected to P2[2]
 * LP     --- Connected to P2[5]
 * FP     --- Connected to P2[3]
 * ENAB_M --- Connected to P2[4]
 * PWR    --- Connected to P2[0]
 */

/* XPT2046 Touchscreen:
 *
 * -------------- -------------------- ------------ -------------------------
 * XTPT2046       Module               Module
 *                Signal               Connector    Connector
 * -------------- -------------------- ------------ -------------------------
 * Pin 11 PENIRQ\ PENIRQ (pulled high) PORT3 Pin 1  P2.15 PENIRQ
 * Pin 12 DOUT    MISO                 PORT3 Pin 4  P1.18 MISO1
 *                                                 (Also USB HOST UP LED)
 * Pin 13 BUSY    BUSY (pulled high)   PORT3 Pin 9  P2.14 BUSY
 * Pin 14 DIN     MOSI                 PORT3 Pin 3  P0.13 MOSI1
 *                                                 (Also USB Device up LED
 *                                                  and SD CD pin)
 * Pin 15 CS\     SSEL (pulled high)   PORT3 Pin 6  P1.8  GPIO
 *                                                 (Also RMII_CRS_DV)
 * Pin 16 DCLK    SCK                  PORT3 Pin 5  P1.19 SCK1
 * -------------- -------------------- ------------ -------------------------
 */

#define GPIO_SSP1_MISO   GPIO_SSP1_MISO_3
#define GPIO_SSP1_MOSI   GPIO_SSP1_MOSI_2
#define GPIO_SSP1_SCK    GPIO_SSP1_SCK_2

#endif
#endif /* __BOARDS_ARM_LPC17XX_40XX_LPC4088_DEVKIT_INCLUDE_BOARD_H */
