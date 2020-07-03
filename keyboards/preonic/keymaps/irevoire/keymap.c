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
  _BASE,
  _ARROW,
  _GAME,
  _META,
};

enum preonic_keycodes {
  BASE = SAFE_RANGE,
  ARROW,
  GAME,
  META,
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
 * |  =   | Ctrl | Alt  |Super |TT(Arr)|   Space    |Enter | Alt  |  [   |  ]   |C(Esc)|
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,        \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NUHS,        \
  KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,        \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,        \
  KC_EQL,  KC_LCTL, KC_LALT, KC_LGUI,MO(_ARROW),KC_SPC, KC_SPC,  KC_ENT,  KC_RALT, KC_LBRC, KC_RBRC, LCTL_T(KC_ESC)  \
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
  _______,   KC_PDOT,   KC_P1,     KC_P2,     KC_P3,     KC_P0,   XXXXXXX,   XXXXXXX, TG(_GAME),   XXXXXXX,   XXXXXXX,   KC_MUTE,  \
  _______,   _______,  _______,   _______, TO(_BASE),  _______,   _______,   _______,   _______,   XXXXXXX,   XXXXXXX,   KC_ESC    \
),

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |  Up  |   O  |   P  |  #   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   A  |   S  |   D  |   F  |   G  |   H  | Left | Down |Right |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  =   | Ctrl | Alt  |Super |  NO  |    Space    |Enter | Alt  |  [   |TG(GAM)|C(Esc)|
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_preonic_grid( \
  KC_ESC,    KC_1,      KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,        \
  KC_TAB,    KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_UP,   KC_O,    KC_P,    KC_NUHS,        \
  KC_BSPC,   KC_A,      KC_S,    KC_D,    KC_F,    KC_G,    KC_H, KC_LEFT,    KC_DOWN, KC_RIGHT,KC_SCLN, KC_QUOT,        \
  KC_LSFT,   KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,        \
  KC_EQL,    KC_LCTL,   KC_LALT, KC_LGUI,_______,  KC_SPC,  KC_SPC,  KC_ENT,  KC_RALT, KC_LBRC, TO(_BASE), LCTL_T(KC_ESC)  \
),

/* Meta
  ,-----------------------------------------------------------------------------------.
 * |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TG(META)|record|StpRec|PlayRec|  NO |      NO     |Speed+|Speed-|  NO  |RESET |MUSIC |
 * `-----------------------------------------------------------------------------------'
 */
[_META] = LAYOUT_preonic_grid( \
  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  \
  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  \
  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  \
  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  \
  TO(_META),   KC_LCTL,   KC_LALT,   KC_LGUI,   XXXXXXX,   XXXXXXX,   XXXXXXX,     KC_UP,   KC_DOWN,   XXXXXXX,     RESET,   MU_TOG    \
),

};

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
*/
