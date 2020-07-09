/* Copyright 2019 Thomas Campistron
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
#include "muse.h"

enum preonic_layers {
  _BEPO,
  _AZERTY,
  _ARROW,
};

enum preonic_keycodes {
  BEPO = SAFE_RANGE,
  AZERTY,
  ARROW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  #   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  =   | Ctrl | Alt  |Super |MO(Arr)|   Space    |Enter | Alt  |  [   |  ]   |C(Esc)|
 * `-----------------------------------------------------------------------------------'
 */
[_BEPO] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,        \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NUHS,        \
  KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,        \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,        \
  KC_EQL,  KC_LCTL, KC_LALT, KC_LGUI,MO(_ARROW),KC_SPC, KC_SPC,  KC_ENT,  KC_RALT, KC_LBRC, KC_RBRC, LCTL_T(KC_ESC)  \
),

[_AZERTY] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_3,    KC_1,    KC_2,    KC_5, KC_MINS,    KC_6,    KC_7,    KC_6,    KC_9,    KC_BSLS,   KC_EQL,        \
  KC_TAB,  KC_B,    KC_2,    KC_P,    KC_O,    KC_7, KC_LBRC,    KC_V,    KC_D,    KC_L,       KC_J,     KC_9,        \
  KC_BSPC, KC_Q,    KC_U,    KC_I,    KC_E,    KC_M,    KC_C,    KC_T,    KC_S,    KC_R,       KC_N,  KC_SCLN,        \
  KC_LSFT, KC_0,    KC_Y,    KC_X, KC_COMM,    KC_K, KC_QUOT,    KC_A,    KC_G,    KC_H,       KC_F,  KC_RSFT,        \
  KC_EQL,  KC_LCTL, KC_LALT, KC_LGUI,MO(_ARROW),KC_SPC, KC_SPC,  KC_ENT,  KC_RALT, KC_W,       KC_Z,  LCTL_T(KC_ESC)  \
),

/* Arrow
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |Brigh+|   7  |   8  |   9  |  NO  |  NO  |  NO  |  NO  | Lock |  NO  | Vol+ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |Brigh-|   4  |   5  |   6  |  NO  |Caplok| Left | Down |  Up  |Right | Vol- |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |  .   |   1  |   2  |   3  |   0  |  NO  |  NO  |  NO  |  NO  |  NO  | Mute |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   =  | Ctrl | Alt  |Super | BASE |    Space    |Enter |Option|  NO  |  NO  |Escape|
 * `-----------------------------------------------------------------------------------'
 */
[_ARROW] = LAYOUT_preonic_grid( \
  KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,   KC_F10,    KC_F11,    KC_F12,   \
  _______,   KC_BRIU,   KC_P7,     KC_P8,     KC_P9,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_LOCK,   XXXXXXX,   KC_VOLU,  \
  _______,   KC_BRID,   KC_P4,     KC_P5,     KC_P6,   XXXXXXX,   KC_CAPS,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  KC_VOLD,  \
  _______,   KC_PDOT,   KC_P1,     KC_P2,     KC_P3,     KC_P0,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_MUTE,  \
  _______,   _______,  _______,   _______,  _______,   _______,   KC_LEAD,   _______,   _______,   XXXXXXX,   XXXXXXX,   KC_ESC    \
),

};

LEADER_EXTERNS();

void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leading = false;
		leader_end();

		// leader -> r -> r
		SEQ_TWO_KEYS(KC_L, KC_L) {
			reset_keyboard();
		}
		// from bepo: leader -> k -> A
		SEQ_TWO_KEYS(KC_B, KC_A) {
			default_layer_set(_AZERTY);
		}
		// from azerty: leader -> k -> b
		SEQ_TWO_KEYS(KC_K, KC_B) {
			default_layer_set(_BEPO);
		}
	}
}
