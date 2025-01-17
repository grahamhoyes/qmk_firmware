/*
Copyright 2021 Spencer Deven <splitlogicdesign@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#define EE_HANDS

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#ifdef OLED_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 400000
#endif

#define TAPPING_TERM 200

#undef RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD

#define ENCODER_DIRECTION_FLIP

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_WPM_ENABLE

#define POINTING_DEVICE_ROTATION_90

// #define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_LEFT
