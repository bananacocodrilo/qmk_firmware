/* Copyright 2019-2020 DMQ Design
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(/* Base */
                KC_F20, KC_F21, KC_F22, KC_TRNS,
                KC_F17, KC_F18, KC_F19, KC_TRNS,
                KC_F14, KC_F15, KC_F16, KC_TRNS,
                KC_F11, KC_F12, KC_F13
                ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU); // Volume
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) { /* Second encoder */

    if (clockwise) {
      tap_code(C(KC_MINS)); // Zoom in/out
    } else {
      tap_code(C(KC_EQL));
    }

  } else if (index == 2) { /* Third encoder */
    if (clockwise) {
      tap_code(KC_MS_WH_DOWN); // Scroll
    } else {
      tap_code(KC_MS_WH_UP);
    }
  }
    return true;
}
