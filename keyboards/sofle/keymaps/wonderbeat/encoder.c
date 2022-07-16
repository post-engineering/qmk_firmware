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

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t temp_mod = get_mods();
    uint8_t temp_osm = get_oneshot_mods();
    bool    is_shift = (temp_mod | temp_osm) & MOD_MASK_SHIFT;
    bool    is_gui = (temp_mod | temp_osm) & MOD_MASK_GUI;
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }  else if(index == 1 && is_shift) {
        if (clockwise) {
            rgb_matrix_increase_speed();
        } else {
            rgb_matrix_decrease_speed();
        }
    } else if(index == 1 && is_gui)  {
        if (clockwise) {
            rgblight_increase_val();
        } else {
            rgblight_decrease_val();
        }
    } else if(index == 1) {
        if (clockwise) {
            tap_code(KC_BRMD);
        } else {
            tap_code(KC_BRK);
        }
    }
    return true;
}

#endif
