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

 #pragma once

 /* The way how "handedness" is decided (which half is which),
 see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
 for more options.
 */

 /* #define EE_HANDS */

 #define MASTER_LEFT

 #ifdef RGBLIGHT_ENABLE
 #    define RGBLIGHT_ANIMATIONS
 #    define RGBLIGHT_DEFAULT_SPD 12
 #endif

 #define TAPPING_TERM 200
 #define IGNORE_MOD_TAP_INTERRUPT
 #define PERMISSIVE_HOLD

 #ifdef RGB_MATRIX_ENABLE
 #    define RGB_DI_PIN D3
 #    define DRIVER_LED_TOTAL 74
 #    define RGB_DISABLE_WHEN_USB_SUSPENDED   // turn off effects when suspended
 #    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 70 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
 #    define RGB_MATRIX_KEYPRESSES
 #    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
 #    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
 #    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
 /* #    define ENABLE_RGB_MATRIX_MULTISPLASH */
 /* #define RGB_MATRIX_STARTUP_MODE       RGB_MATRIX_RAINDROPS */
 #    define RGB_MATRIX_SPLIT \
         { 37, 37 }
 #    define RGB_MATRIX_LED_COUNT DRIVER_LED_TOTAL

 #endif

 #define LUNA

 #if defined(OLED_FONT_H)
 #    undef OLED_FONT_H
 #endif

 #define OLED_FONT_H "keyboards/sofle/keymaps/wonderbeat/glcdfont.c"
