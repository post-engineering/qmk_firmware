/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)

// Tap Dance Declarations
enum { TD_UNDS_PIPE = 0, TD_LCBR_LBRC, TD_RCBR_RBRC, TD_NEXT_PLAY, SLSH_BSLS };

// Home mod row (kinda)
// Home mod row (kinda)
tap_dance_action_t tap_dance_actions[] = {[TD_UNDS_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_PIPE), [TD_LCBR_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_LBRC), [TD_RCBR_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RCBR, KC_RBRC), [TD_NEXT_PLAY] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPLY), [SLSH_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS)};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_ESC,LSFT_T(KC_A),LCTL_T(KC_S),LALT_T(KC_D),KC_F,KC_G,     KC_H,KC_J,LALT_T(KC_K), LCTL_T(KC_L), LSFT_T(KC_SCLN), KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       TD(SLSH_BSLS), KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(TD_UNDS_PIPE),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                            KC_RGUI, LOWER,       RAISE,  KC_RGUI,  TD(TD_NEXT_PLAY),
                                                    KC_ENT,       KC_SPC,    KC_RALT
//                            ╰───────────────────────────╯ ╰──────────────────╯
  /*                                  KC_LGUI, KC_SPC,   LOWER,      RAISE,  KC_ENT, */
  /*                                          KC_LALT, KC_BSPC,    KC_DEL */
  /* //                            ╰───────────────────────────╯ ╰──────────────────╯ */
  ),

  [LAYER_LOWER] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_MOD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_LBRC,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_TOG, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,  QK_BOOT,    KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                           _______, XXXXXXX,    _______,    _______, _______,
                                                    _______,    _______,    KC_P0
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PGUP, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RGUI, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    QK_BOOT, EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______,            KC_BTN3,    _______, _______,
                                           _______,            KC_BTN1,    KC_BTN2
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
