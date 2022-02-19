/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#include <stdio.h>

#include "keymap_bepo.h"

char wpm_str[30];

enum layers {
    _BEPO = 0,
    _LOWER,
    _RAISE,
};

#define BP_EA BP_E_ACUTE
#define BP_AG BP_AGRV
#define BP_EG BP_E_GRAVE
#define BP_DC BP_DCRC
#define BP_AP BP_APOS
#define BP_CO BP_COMM
#define BP_DT BP_DOT
#define LS KC_LSFT
#define BP_DOL BP_DOLLAR

#define MO_LOWER MO(_LOWER)
#define MO_RAISE MO(_RAISE)
#define LMSH_LWR LM(_LOWER, MOD_LSFT)
#define LMAL_LWR LM(_LOWER, MOD_RALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: BEPO
 *
 *  ,----------------------------------------------------.                                            ,-----------------------------------------------------.
 *  |   Tab  |    B   |   É   |    P   |    O   |    È   |                                            |    ^   |   V    |   D    |   L    |   J    |   Ç    |
 *  |--------+--------+-------+--------+--------+--------|                                            |--------+--------+--------+--------+--------+--------|
 *  |  Bksp  |    A   |   U   |    I   |    E   |    ,   |                                            |    C   |   T    |   S    |   R    |   N    |   M    |
 *  |--------+--------+-------+--------+--------+--------+------------------.      ,------------------+--------+--------+--------+--------+--------+--------|
 *  | LShift |    À   |   Y   |    X   |    .   |    K   | Escape  |LMSH_LWR|      |AltLower|  Raise  |    '   |   Q    |   G    |   H    |   F    | RShift |
 *  `-------------------------+--------+--------+--------+---------+--------|      |--------+---------+--------+--------+--------+--------------------------'
 *                            | Super  | LCtrl  |  LAlt  |  Space  | Lower  |      |  Ralt  |  Enter  | Escape |   Z    |   W    |
 *                            |        |        |        |         |        |      |        |         |        |        |        |
 *                            `---------------------------------------------'      `---------------------------------------------'
 */
    [_BEPO] = LAYOUT(
      KC_TAB , BP_B   , BP_EA , BP_P   , BP_O   , BP_EG  ,                    /* */                    BP_DC  , BP_V   , BP_D   , BP_L   , BP_J   , BP_CCED ,
      KC_BSPC, BP_A   , BP_U  , BP_I   , BP_E   , BP_CO  ,                    /* */                    BP_C   , BP_T   , BP_S   , BP_R   , BP_N   , BP_M    ,
      KC_LSFT, BP_AG  , BP_Y  , BP_X   , BP_DT  , BP_K   , KC_ESC  , LMSH_LWR,/* */ LMAL_LWR,MO_RAISE, BP_AP  , BP_Q   , BP_G   , BP_H   , BP_F   , KC_RSFT ,
                                KC_LGUI, KC_LCTL, KC_LALT, KC_SPACE, MO_LOWER,/* */ KC_RALT , KC_ENT , KC_ESC , BP_Z   , BP_W
    ),


/*
 * Lower Layer:
 *
 *  ,----------------------------------------------------.                                            ,-----------------------------------------------------.
 *  |   $    |   "    |   «   |   »    |   (    |   )    |                                            |   @    |    +   |   -    |   /    |   *    |   =    |
 *  |--------+--------+-------+--------+--------+--------|                                            |--------+--------+--------+--------+--------+--------|
 *  |        |        |       |        |        |        |                                            |CapsLock|  Left  |  Down  |   Up   | Right  |   %    |
 *  |--------+--------+-------+--------+--------+--------+------------------.      ,------------------+--------+--------+--------+--------+--------+--------|
 *  |        |        |       |        |        |        |    %    |PrintScr|      |        |         |        |        |        |        |        |        |
 *  `-------------------------+--------+--------+--------+---------+--------|      |--------+---------+--------+--------+--------+--------------------------'
 *                            |        |        |        |         |        |      |        |         |        |        |        |
 *                            |        |        |        |         |        |      |        |         |        |        |        |
 *                            `---------------------------------------------'      `---------------------------------------------'
 */
    [_LOWER] = LAYOUT(
      BP_DOL , BP_DQUO, BP_LGIL, BP_RGIL, BP_LPRN, BP_RPRN,                   /* */                   BP_AT  , BP_PLUS, BP_MINS,BP_SLASH, BP_ASTR, BP_EQL ,
      _______, _______, _______, _______, _______, _______,                   /* */                   KC_CAPS, KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, BP_PERC,
      _______, _______, _______, _______, _______, _______, BP_PERC, KC_PSCR, /* */ _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______
    ),

/*
 * Raise Layer:
 *
 *  ,----------------------------------------------------.                                            ,-----------------------------------------------------.
 *  |        |        |   7   |    8   |   9    |        |                                            |        |   F7   |   F8   |   F9   |  F10   |  F13   |
 *  |--------+--------+-------+--------+--------+--------|                                            |--------+--------+--------+--------+--------+--------|
 *  |        |        |   4   |    5   |   6    |        |                                            |        |   F4   |   F5   |   F6   |  F11   |  F14   |
 *  |--------+--------+-------+--------+--------+--------+------------------.      ,------------------+--------+--------+--------+--------+--------+--------|
 *  |        |        |   1   |    2   |   3    |   0    |         |        |      |        |         |        |   F1   |   F2   |   F3   |  F12   |  F15   |
 *  `-------------------------+--------+--------+--------+---------+--------|      |--------+---------+--------+--------+--------+--------------------------'
 *                            |        |        |        |         |        |      |        |         |        |        |        |
 *                            |        |        |        |         |        |      |        |         |        |        |        |
 *                            `---------------------------------------------'      `---------------------------------------------'
 *
 */
    [_RAISE] = LAYOUT(
      RGB_M_R, RGB_M_K, KC_P7  , KC_P8  , KC_P9  , _______,                   /* */                   _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 ,  KC_F13 ,
      RGB_M_SW,RGB_M_G, KC_P4  , KC_P5  , KC_P6  , _______,                   /* */                   _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 ,  KC_F14 ,
      RGB_M_SN,RGB_M_B, KC_P1  , KC_P2  , KC_P3  , KC_P0  , _______, _______, /* */ _______, _______, _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 ,  KC_F15 ,
                                 _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______
    ),

// /*
//  * Template Layer:
//  *
//  *  ,----------------------------------------------------.                                            ,-----------------------------------------------------.
//  *  |        |        |       |        |        |        |                                            |        |        |        |        |        |        |
//  *  |--------+--------+-------+--------+--------+--------|                                            |--------+--------+--------+--------+--------+--------|
//  *  |        |        |       |        |        |        |                                            |        |        |        |        |        |        |
//  *  |--------+--------+-------+--------+--------+--------+------------------.      ,------------------+--------+--------+--------+--------+--------+--------|
//  *  |        |        |       |        |        |        |         |        |      |        |         |        |        |        |        |        |        |
//  *  `-------------------------+--------+--------+--------+---------+--------|      |--------+---------+--------+--------+--------+--------------------------'
//  *                            |        |        |        |         |        |      |        |         |        |        |        |
//  *                            |        |        |        |         |        |      |        |         |        |        |        |
//  *                            `---------------------------------------------'      `---------------------------------------------'
//  *
//  */
//    [_TEMPLATE] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                   /* */                   _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                   /* */                   _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______
//     ),
//
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, 12);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

#include "bongo_cat.h"
#include "rust.h"

void oled_task_user(void) {
    if (is_keyboard_master()) {
        bongo_render_anim();
        // oled_set_cursor(7,6);
     // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        rust_render_anim();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	keystroke_timestamp = timer_read32();
	return true;
}

#endif
