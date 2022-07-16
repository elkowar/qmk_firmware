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

enum layer_names { _BASE, _SYM, _NUM };

#define CT(x) LCTL_T((x))
#define LS(x) LSFT_T((x))

#define OSSFT OSM(MOD_LSFT)
#define LT_BSSYM LT(_SYM, KC_BSPC)
#define LT_NUMTAB LT(_NUM, KC_TAB)

// clang-format off
/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        QK_BOOT,  KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC, \
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,      KC_G,         KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT), \
                            KC_LCTRL, KC_LALT,  KC_LSFT,   KC_SPC,       KC_BSPC,  KC_RSFT,  KC_RGUI,  KC_RALT \
  )
};
*/
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        LT_NUMTAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,                              KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_PLUS, \
        CT(KC_ESC),  KC_A,     LS(KC_S), KC_D,     KC_F,      KC_G,                              KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,                              KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_MINUS, RSFT_T(KC_ENT), \
                                         KC_LALT,  KC_LGUI,   KC_SPC,  XXXXXXX,        OSSFT,    LT_BSSYM, XXXXXXX,  KC_RALT \
    ),
    [_SYM] = LAYOUT(
        _______,     KC_CIRC,  KC_EXLM,  KC_DQUO,  KC_SLSH,   KC_BSLS,                           KC_GRV,   KC_LCBR,  KC_LBRC,  KC_RBRC,  KC_RCBR,  KC_ASTR,
        _______,     KC_HOME,  KC_DLR,   KC_LPRN,  KC_RPRN,   KC_END,                            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_AMPR,  KC_PERC,
        _______,     KC_AT,    KC_DEL,   KC_PIPE,  KC_QUES,   KC_TILD,                           KC_DEL,   KC_EQL,   KC_HASH,  KC_UNDS,  KC_PGUP,  KC_PGDN,
                                         _______,  _______,   _______, _______,        _______,  _______,  _______,  _______ \
    ),
    [_NUM] = LAYOUT(
        _______,     _______,  _______,  _______,  _______,   _______,                           _______,  KC_7,     KC_8,     KC_9,     KC_COMMA, KC_PLUS, \
        _______,     KC_LSFT,  KC_LGUI,  KC_LCTL,  _______,   _______,                           _______,  KC_1,     KC_2,     KC_3,     KC_DOT,   _______, \
        _______,     _______,  _______,  _______,  _______,   _______,                           _______,  KC_4,     KC_5,     KC_6,     KC_MINUS, _______, \
                                         _______,  _______,   _______, _______,        KC_0,     KC_0,     _______,  _______ \
    )
};
