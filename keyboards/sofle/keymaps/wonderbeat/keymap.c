 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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
 #include "oled.c"
 #include "encoder.c"

 // Tap Dance Declarations
 enum { TD_UNDS_PIPE = 0, TD_LCBR_LBRC, TD_RCBR_RBRC, TD_NEXT_PLAY, SLSH_BSLS };

 // Tap Dance Definitions
 qk_tap_dance_action_t tap_dance_actions[] = {[TD_UNDS_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_PIPE), [TD_LCBR_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_LBRC), [TD_RCBR_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RCBR, KC_RBRC), [TD_NEXT_PLAY] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPLY), [SLSH_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS)};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * QWERTY
      * ,-----------------------------------------.                    ,-----------------------------------------.
      * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
      * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
      * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  '   |
      * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
      * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Bspc |
      * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
      * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
      * `-----------------------------------------/       /     \      \-----------------------------------------'
      *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
      *            |      |      |      |      |/       /         \      \ |      |      |      |      |
      *            `----------------------------------'           '------''---------------------------'
      */

     [0] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, /**/ KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT, KC_ESC, LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), KC_F, KC_G, /**/ KC_H, KC_J, LALT_T(KC_K), LCTL_T(KC_L), LSFT_T(KC_SCLN), KC_BSPC, TD(SLSH_BSLS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, /**/ TG(1), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(TD_UNDS_PIPE), TD(TD_LCBR_LBRC), TD(TD_RCBR_RBRC), MO(2), KC_LGUI, KC_ENT, /**/ KC_SPC, KC_RGUI, MO(3), KC_RALT, TD(TD_NEXT_PLAY)),
     /*
      * COLEMAK-DH
      * ,-----------------------------------------.                    ,-----------------------------------------.
      * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
      * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
      * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
      * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
      * | TAB  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
      * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
      * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
      * `-----------------------------------------/       /     \      \-----------------------------------------'
      *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
      *            |      |      |      |      |/       /         \      \ |      |      |      |      |
      *            `----------------------------------'           '------''---------------------------'
      */
     [1] = LAYOUT(_______, KC_1, KC_2, KC_3, KC_4, KC_5, /**/ KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, KC_Q, KC_W, KC_F, KC_P, KC_B, /**/ KC_J, KC_L, KC_U, KC_Y, KC_SCLN, _______, _______, KC_A, LSFT_T(KC_R), LCTL_T(KC_S), LALT_T(KC_T), /**/ KC_G, KC_M, KC_N, LALT_T(KC_E), LCTL_T(KC_I), LSFT_T(KC_O), _______, _______, KC_Z, KC_X, KC_C, KC_D, KC_V, _______, /**/ _______, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______),
     /* LOWER
      * ,-----------------------------------------.                    ,-----------------------------------------.
      * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
      * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
      * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
      * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
      * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
      * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
      * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
      * `-----------------------------------------/       /     \      \-----------------------------------------'
      *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
      *            |      |      |      |      |/       /         \      \ |      |      |      |      |
      *            `----------------------------------'           '------''---------------------------'
      */
     [2] = LAYOUT(_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12, _______, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, _______, KC_1, KC_2, KC_3, KC_4, KC_5, _______, _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
     /* RAISE
      * ,----------------------------------------.                    ,-----------------------------------------.
      * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
      * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
      * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
      * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
      * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
      * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
      * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
      * `-----------------------------------------/       /     \      \-----------------------------------------'
      *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
      *            |      |      |      |      |/       /         \      \ |      |      |      |      |
      *            `----------------------------------'           '------''---------------------------'
      */
     [3] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, KC_PSCR, KC_APP, XXXXXXX, XXXXXXX, KC_PGUP, _______, KC_UP, _______, _______, KC_BSPC, _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_BSPC, _______, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX, _______, _______, XXXXXXX, _______, XXXXXXX, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};

 #ifdef RGB_MATRIX_ENABLE
 // Physical Layout
 // Columns
 // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
 //                                           ROWS
 // 12 13 22 23 32 33       33 32 23 22 13 12  0
 //    02    03    04       04    03    02
 // 11 14 21 24 31 34       34 31 24 21 14 11  1
 //                01       01
 // 10 15 20 25 30 35       35 30 25 20 15 10  2
 //
 // 09 16 19 26 29 36       36 29 26 19 16 09  3
 //
 //     08 17 18 27 28     28 27 18 17 08      4
 //  (08)  07    06    05       05    06    07  (08)
 //
 led_config_t g_led_config = {{{12, 13, 22, 23, 32, 33}, {11, 14, 21, 24, 31, 34}, {10, 15, 20, 25, 30, 35}, {9, 16, 19, 26, 29, 36}, {8, 17, 18, 27, 28, NO_LED}, {48, 49, 58, 59, 68, 69}, {47, 50, 57, 60, 67, 70}, {46, 51, 56, 61, 66, 71}, {45, 52, 55, 62, 65, 72}, {44, 53, 54, 63, 64, NO_LED}},
                              {
                                  // Left side underglow
                                  {96, 40},
                                  {16, 20},
                                  {48, 10},
                                  {80, 18},
                                  {88, 60},
                                  {56, 57},
                                  {24, 60},
                                  {10, 60},
                                  // Left side Matrix
                                  {32, 57},
                                  {0, 48},
                                  {0, 36},
                                  {0, 24},
                                  {0, 12},
                                  {16, 12},
                                  {16, 24},
                                  {16, 36},
                                  {16, 48},
                                  {48, 55},
                                  {64, 57},
                                  {32, 45},
                                  {32, 33},
                                  {32, 21},
                                  {32, 9},
                                  {48, 7},
                                  {48, 19},
                                  {48, 31},
                                  {48, 43},
                                  {80, 59},
                                  {96, 64},
                                  {64, 45},
                                  {64, 33},
                                  {64, 21},
                                  {64, 9},
                                  {80, 10},
                                  {80, 22},
                                  {80, 34},
                                  {80, 47},

                                  // Right side underglow
                                  {128, 40},
                                  {208, 20},
                                  {176, 10},
                                  {144, 18},
                                  {136, 60},
                                  {168, 57},
                                  {200, 60},
                                  {210, 60},
                                  // Right side Matrix
                                  {192, 57},
                                  {224, 48},
                                  {224, 36},
                                  {224, 24},
                                  {224, 12},
                                  {208, 12},
                                  {208, 24},
                                  {208, 36},
                                  {208, 48},
                                  {176, 55},
                                  {160, 57},
                                  {192, 45},
                                  {192, 33},
                                  {192, 21},
                                  {192, 9},
                                  {176, 7},
                                  {176, 19},
                                  {176, 31},
                                  {176, 43},
                                  {144, 59},
                                  {128, 64},
                                  {160, 45},
                                  {160, 33},
                                  {160, 21},
                                  {160, 9},
                                  {144, 10},
                                  {144, 22},
                                  {144, 34},
                                  {144, 47},
                              },
                              {LED_FLAG_NONE,      LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
                               LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT}};
 #endif

 void keyboard_post_init_rgb_light(void) {
 #ifdef RGBLIGHT_ENABLE
     rgblight_sethsv_pink();
     /* rgblight_setrgb(RGB_ORANGE); */
     rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 1);
 #endif

 #ifdef RGB_MATRIX_ENABLE
     /* rgblight_mode(RGB_MATRIX_JELLYBEAN_RAINDROPS); */
     rgb_matrix_mode(RGB_MATRIX_SOLID_MULTISPLASH);
 #endif
 }

 #ifdef RGB_MATRIX_ENABLE
 layer_state_t layer_state_set_user(layer_state_t state) {
     switch (get_highest_layer(state)) {
         case 1:
             rgb_matrix_sethsv(HSV_AZURE);
             break;
         case 2:
             rgb_matrix_sethsv(HSV_GREEN);
             rgb_matrix_mode(RGB_MATRIX_PIXEL_FRACTAL);
             break;
         default: //  for any other layers, or the default layer
             rgb_matrix_mode(RGB_MATRIX_SOLID_MULTISPLASH);
             break;
     }
     return state;
 }
 #endif

 void keyboard_post_init_user(void) {
     keyboard_post_init_rgb_light();
 }
