/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* USB */
#define USB_SUSPEND_WAKEUP_DELAY 1000

/*DCDC*/
#define CHRG_PIN C7
#define FULL_PIN C6

#define POWER_DCDC_EN_PIN B13

#define BATTERY_CAPACITY_LOW 30
#define BATTERY_CAPACITY_STOP 0

/*
#define IM_MM_RGB_BLINK_INDEX_W2M 37
#define IM_MM_RGB_BLINK_INDEX_W2H 37

#define ENCODER_A_PINS { C8 }
#define ENCODER_B_PINS { C9 }
#define ENCODER_MAP_KEY_DELAY 1
#define ENCODER_RESOLUTION 2
*/

/* UART */
#define UART_DRIVER SD3
#define SD3_TX_PIN C10
#define SD3_RX_PIN C11


/* DEBOUNCE */
#define DEBOUNCE 8
#define HOLD_ON_OTHER_KEY_PRESS

/* Key Matrix */
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define MATRIX_ROWS 5
#define MATRIX_COLS 15
/*
// #define DIODE_DIRECTION ROW2COL
// #define MATRIX_COL_PINS \
//     { B0, B1, B2, B3, B4, B5, B6, B7, C12, D2, B10, B11, A10, A15, A9}
// #define MATRIX_ROW_PINS \
//     { A1, A2, A3, A4, A8 }
*/

/* SPI Config for LED Driver */
#define SPI_DRIVER SPIDQ
#define SPI_SCK_PIN A5
#define SPI_MOSI_PIN A7
#define SPI_MISO_PIN A6

/* Flash */
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN B14
#define WEAR_LEVELING_BACKING_SIZE (4 * 1024)
#define WEAR_LEVELING_LOGICAL_SIZE (WEAR_LEVELING_BACKING_SIZE / 2)
#define FEE_PAGE_COUNT (WEAR_LEVELING_BACKING_SIZE / FEE_PAGE_SIZE)

/* RGB Matrix */
#define WS2812_DI_PIN B15
#define WS2812_SPI_DRIVER SPIDM2
#define WS2812_SPI_DIVISOR 32
/* old value => 24 */

#define RGB_MATRIX_LED_COUNT (67)