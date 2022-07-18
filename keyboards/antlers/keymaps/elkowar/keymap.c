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

#include QMK_KEYBOARD_H
#include <math.h>
#include "print.h"

enum my_keycodes { SNIPE = SAFE_RANGE, DRAG_SCRL };

enum layer_names { _BASE = 0, _GAME, _SYM, _NUM, _FUN, _MOUSE };

#define CT(x) LCTL_T((x))
#define LS(x) LSFT_T((x))

#define OSSFT OSM(MOD_LSFT)
#define LT_BSSYM LT(_SYM, KC_BSPC)
#define LT_NUMTAB LT(_NUM, KC_TAB)

#define HOME_A KC_A
#define HOME_S LS(KC_S)
#define HOME_D KC_D
#define HOME_F KC_F
#define HOME_J KC_J
#define HOME_K KC_K
#define HOME_L LS(KC_L)
#define HOME_SCLN KC_SCLN

#include "g/keymap_combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    [_LAYER] = LAYOUT(
        _______,     _______,  _______,  _______,  _______,   _______,                           _______,  _______,  _______,  _______,  _______,  _______, \
        _______,     _______,  _______,  _______,  _______,   _______,                           _______,  _______,  _______,  _______,  _______,  _______, \
        _______,     _______,  _______,  _______,  _______,   _______,                           _______,  _______,  _______,  _______,  _______,  _______, \
                                         _______,  _______,   _______, _______,        _______,  _______,  _______,  _______ \
    )
    */
    [_BASE] = LAYOUT(
        LT_NUMTAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,                              KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_PLUS, \
        CT(KC_ESC),  HOME_A,   HOME_S,   HOME_D,   HOME_F,    KC_G,                              KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN,KC_QUOT, \
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,                              KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_MINUS, RSFT_T(KC_ENT), \
                                         KC_LALT,  KC_LGUI,   KC_SPC,  KC_ENT,         OSSFT,    LT_BSSYM, XXXXXXX,  KC_RALT \
    ),
    [_GAME] = LAYOUT(
        LT_NUMTAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,                              KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_PLUS, \
        KC_LCTL,     KC_A,     KC_S,     KC_D,     KC_F,      KC_G,                              KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,                              KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_MINUS, RSFT_T(KC_ENT), \
                                         KC_LALT,  KC_LGUI,   KC_SPC,  KC_ENT,         OSSFT,    LT_BSSYM, KC_ESC,   KC_RALT \
    ),
    [_SYM] = LAYOUT(
        _______,     KC_CIRC,  KC_EXLM,  KC_DQUO,  KC_SLSH,   KC_BSLS,                           KC_GRV,   KC_LCBR,  KC_LBRC,  KC_RBRC,  KC_RCBR,  KC_ASTR,
        _______,     KC_HOME,  KC_DLR,   KC_LPRN,  KC_RPRN,   KC_END,                            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_AMPR,  KC_PERC,
        _______,     KC_AT,    KC_DEL,   KC_PIPE,  KC_QUES,   KC_TILD,                           KC_DEL,   KC_EQL,   KC_HASH,  KC_UNDS,  KC_PGUP,  KC_PGDN,
                                         _______,  _______,   MO(_FUN),_______,        _______,  _______,  _______,  _______ \
    ),
    [_NUM] = LAYOUT(
        _______,     _______,  _______,  _______,  _______,   _______,                           _______,  KC_7,     KC_8,     KC_9,     KC_COMMA, KC_PLUS, \
        _______,     KC_LSFT,  KC_LGUI,  KC_LCTL,  _______,   _______,                           _______,  KC_1,     KC_2,     KC_3,     KC_DOT,   _______, \
        _______,     _______,  _______,  _______,  _______,   _______,                           _______,  KC_4,     KC_5,     KC_6,     KC_MINUS, _______, \
                                         _______,  _______,   _______, _______,        KC_0,     KC_0,     _______,  _______ \
    ),
    [_FUN] = LAYOUT(
        _______,     KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,                             KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   DF(_BASE), \
        _______,     _______,  _______,  _______,  _______,   _______,                           _______,  _______,  _______,  KC_F11,   KC_F12,   _______, \
        _______,     _______,  _______,  _______,  _______,   _______,                           _______,  KC_INS,   KC_PSCR,  KC_SLCK,  KC_PAUSE, DF(_GAME), \
                                         _______,  _______,   _______, _______,        _______,  _______,  _______,  _______ \
    ),
    [_MOUSE] = LAYOUT(
        _______,     _______,  _______,  _______,  _______,   _______,                           KC_BTN2,  _______,  _______,  _______,  _______,  _______, \
        _______,     _______,  _______,  SNIPE,    DRAG_SCRL, _______,                           KC_BTN2,  DRAG_SCRL,_______,  _______,  _______,  _______, \
        _______,     _______,  _______,  _______,  _______,   KC_BTN3,                           KC_BTN3,  _______,  _______,  _______,  _______,  _______, \
                                         _______,  _______,   KC_BTN2, KC_BTN1,        KC_BTN1,  KC_BTN2,  KC_BTN3,  _______ \
    )

};
// clang-format on

void keyboard_post_init_user(void) {
    debug_enable = true;
}

#define MOUSE_LAYER_TIMEOUT 650
#define MOUSE_ROTATION_DEG 30
#define MOUSE_CPI 400

void pointing_device_init_user(void) {
    pointing_device_set_cpi(MOUSE_CPI);
}

report_mouse_t rotate_mouse_report(report_mouse_t report) {
    float rotation = MOUSE_ROTATION_DEG * 0.017453;
    report.x       = report.x * cos(rotation) - report.y * sin(rotation);
    report.y       = report.x * sin(rotation) + report.y * cos(rotation);
    return report;
}

void reset_mouse_report_motion(void) {
    report_mouse_t report = pointing_device_get_report();
    report.x              = 0;
    report.y              = 0;
    pointing_device_set_report(report);
}

static uint16_t mouse_layer_timer = 0;
static bool     drag_scroll       = false;
static bool     sniping_mode      = false;

report_mouse_t pointing_device_task_user(report_mouse_t report) {
    report = rotate_mouse_report(report);

    if (sniping_mode) {
        report.x = report.x / 2;
        report.y = report.y / 2;
    }
    if (drag_scroll) {
        report.h = report.x / 10;
        report.v = report.y / 10;
        report.x = 0;
        report.y = 0;
        return report;
    }

    // if mouse is moving, reset mouse layer timer
    if (report.x != 0 && report.y != 0) {
        mouse_layer_timer = timer_read();
        if (!layer_state_is(_MOUSE)) {
            layer_on(_MOUSE);
        }
    } else if (timer_elapsed(mouse_layer_timer) > MOUSE_LAYER_TIMEOUT && layer_state_is(_MOUSE)) {
        layer_off(_MOUSE);
    }

#ifdef CONSOLE_ENABLE
    pinnacle_data_t cirque_data = cirque_pinnacle_read_data();
    if (cirque_data.valid) {
        uprintf("trackpad: %d %d\n", cirque_data.touchDown, cirque_data.zValue);
    }
#endif

    return report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_BTN1 || keycode == KC_BTN2 || keycode == KC_BTN3 || keycode == DRAG_SCRL) {
        mouse_layer_timer = timer_read();
    } else if (layer_state_is(_MOUSE)) {
        mouse_layer_timer += MOUSE_LAYER_TIMEOUT;
        layer_off(_MOUSE);
    }

    switch (keycode) {
        case SNIPE:
            reset_mouse_report_motion();
            sniping_mode = record->event.pressed;
            return false;
        case DRAG_SCRL:
            reset_mouse_report_motion();
            drag_scroll = record->event.pressed;
            return false;
        default:
            return true;
    }
}
