/* Copyright 2022 ElKowar
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

#include "config_common.h"

#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// many things are specified in info.json

#define UNUSED_PINS \
    {}

/* set to 0 if debouncing is not needed */
#define DEBOUNCE 5

#define QMK_KEYS_PER_SCAN 4
#define USB_POLLING_INTERVAL_MS 1

// enter bootloader mode via double-tapping reset (should be default)
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET              // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 300U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U  // Specify a optional status led which blinks when entering the bootloader

/*
 * CIRQUE STUFF
 */

#define POINTING_DEVICE_ROTATION_270

#define CIRQUE_PINNACLE_ATTENUATION ADC_ATTENUATE_2X // # down to 1X
#define CIRQUE_PINNACLE_TAPPING_TERM 200
#define POINTING_DEVICE_TASK_THROTTLE_MS 10 // maybe lower?
#define CIRQUE_PINNACLE_SPI_CS_PIN GP21
//#define CIRQUE_PINNACLE_TOUCH_DEBOUNCE default unclear

// define the SPI pinout to match the board
#define SPI_DRIVER SPID0

#undef SPI_SCK_PIN
#define SPI_SCK_PIN GP22

#undef SPI_MISO_PIN
#define SPI_MISO_PIN GP20

#undef SPI_MOSI_PIN
#define SPI_MOSI_PIN GP23



/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
