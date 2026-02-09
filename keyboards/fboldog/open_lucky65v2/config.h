/*
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

/* QMK */
#define ENABLE_COMPILE_KEYCODE

/* USB */
/* #define USB_SUSPEND_WAKEUP_DELAY 1000 */

/*DCDC*/
#define CHRG_PIN C7
#define FULL_PIN C6

#define POWER_DCDC_EN_PIN B13

#define BATTERY_CAPACITY_LOW 30
#define BATTERY_CAPACITY_STOP 0

/* UART */
#define UART_DRIVER SD3
#define SD3_TX_PIN C10
#define SD3_RX_PIN C11

/* DEBOUNCE */
#define DEBOUNCE 8
#define HOLD_ON_OTHER_KEY_PRESS

/* Key Matrix */
// #define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

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
/*#define WS2812_DI_PIN B15*/
#define WS2812_SPI_DRIVER SPIDM2
#define WS2812_SPI_DIVISOR 32
/* old value => 24 */

#define RGB_MATRIX_LED_COUNT (67)
//#define RGB_MATRIX_STARTUP_MODE 13
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
// #define RGB_TRIGGER_ON_KEYDOWN


#define RGB_DRIVER_EN_PIN B12
