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
#include QMK_KEYBOARD_H

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

enum layers {
    _BASE,
    _MAC,
    _SHIFT,
    _NUMPAD,
};

enum custom_keycodes {
    KC_BASE = SAFE_RANGE,
    KC_MAC,
    KC_CSFT, // Custom shift
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

/*
[_MAC] = LAYOUT(
      _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ , _______
    ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
      KC_AMPR   , KC_LBRACKET            , KC_LCBR   , KC_RCBR    , KC_LPRN           , KC_EQUAL ,                                               KC_ASTR , KC_RPRN , KC_PLUS , KC_RBRACKET , KC_EXLM  , KC_GRAVE ,
      KC_TAB    , KC_SCOLON              , KC_COMMA  , KC_DOT     , KC_P              , KC_Y     , KC_AT     ,                       KC_BSLASH , KC_F    , KC_G    , KC_C    , KC_R        , KC_L     , KC_SLASH ,
      KC_ESC , KC_A                   , KC_O      , KC_E       , LT(_NUMPAD, KC_U) , KC_I     , KC_HOME   ,                       KC_END    , KC_D    , KC_H    , KC_T    , KC_N        , KC_S     , KC_MINUS ,
      MO(_SHIFT)  , MT(MOD_LSFT, KC_QUOTE) , KC_Q      , KC_J       , KC_K              , KC_X     , KC_LALT   , KC_MUTE   , RGB_TOG , KC_LGUI   , KC_B    , KC_M    , KC_W    , KC_V        , KC_Z     , KC_A  ,
      KC_LCTL   , KC_MEH                 , KC_PC_CUT , KC_PC_COPY , KC_PC_PASTE       ,            KC_BSPACE , KC_DELETE , KC_ENT  , KC_SPC    ,           KC_LEFT , KC_DOWN , KC_UP       , KC_RIGHT , KC_RCTRL
    ),

    [_MAC] = LAYOUT(
      _______ , _______  , _______    , _______     , _______      , _______ ,                                                _______ , _______ , _______ , _______ , _______ , _______ ,
      _______ , _______  , _______    , _______     , _______      , _______ , _______ ,                     _______        , _______ , _______ , _______ , _______ , _______ , _______ ,
      _______ , _______  , _______    , _______     , _______      , _______ , _______ ,                     _______        , _______ , _______ , _______ , _______ , _______ , _______ ,
      _______ , _______  , _______    , _______     , _______      , _______ , _______ , _______ , _______ , LGUI(KC_SPACE) , _______ , _______ , _______ , _______ , _______ , _______ ,
      KC_LGUI , KC_LCTRL , KC_MAC_CUT , KC_MAC_COPY , KC_MAC_PASTE ,           _______ , _______ , _______ , _______ ,                  _______ , _______ , _______ , _______ , KC_RGUI
    ),

    [_SHIFT] = LAYOUT(
      KC_PERC , KC_7    , KC_5    , KC_3    , KC_1    , KC_9    ,                                         KC_0    , KC_2    , KC_4    , KC_6    , KC_8    , KC_TILD ,
      _______ , _______ , _______ , _______ , _______ , _______ , KC_CIRC ,                     KC_PIPE , _______ , _______ , _______ , _______ , _______ , KC_QUES ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ , KC_UNDS ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ , _______
    ),

    [_NUMPAD] = LAYOUT(
      _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , KC_KP_PLUS , KC_KP_ASTERISK , KC_KP_MINUS , _______     ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , KC_7    , KC_8       , KC_9           , KC_KP_PLUS  , _______     ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , KC_4    , KC_5       , KC_6           , KC_KP_PLUS  , _______     ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_1    , KC_2       , KC_3           , KC_KP_ENTER , KC_KP_ENTER ,
      _______ , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ ,           KC_0    , KC_0       , KC_DOT         , KC_KP_ENTER , _______
    ),

	// [_QWERTY] = LAYOUT(
    //   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    //   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_LBRC,                       KC_RBRC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    //   KC_ADJUST, KC_A,  KC_S,    KC_D,    KC_F,    KC_G,  KC_MINS,                       KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_GRV, KC_MUTE,      RGB_TOG, KC_DEL,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    //   KC_LCTL, KC_LALT, KC_LGUI, LALT(KC_TAB), KC_LOWER,  KC_SPC,   KC_ENT,    KC_ENT,   KC_SPC,  KC_RAISE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    // ),

	// [_LOWER] = LAYOUT(
    //   _______, KC_F1, KC_F2, KC_F3, KC_F4,   KC_F5,                                KC_F6,   KC_F7,   KC_F8, KC_F9, KC_F10, KC_F11,
    //   KC_PSLS, KC_P7, KC_P8, KC_P9, KC_NLCK, _______, _______,                   _______, _______, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_F12,
    //   KC_CAPS, KC_P4, KC_P5, KC_P6, KC_NLCK, _______, _______,                   _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_NLCK,
    //   _______, KC_P1, KC_P2, KC_P3, _______, _______, _______, _______,  _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, _______,
    //   _______, KC_P0, KC_PDOT, KC_PENT, _______,     _______,  _______,   _______,    _______,   _______, KC_P0, KC_PDOT, KC_PENT, _______
    //   ),

	// [_RAISE] = LAYOUT(
    //   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    //   KC_PSLS, KC_P7, KC_P8, KC_P9, KC_NLCK, _______, _______,                    _______, _______, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_F12,
    //   KC_CAPS, KC_P4, KC_P5, KC_P6, KC_NLCK, _______, _______,                    _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_NLCK,
    //   _______, KC_P1, KC_P2, KC_P3, _______, _______, _______, _______,  _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, _______,
    //   _______, KC_P0, KC_PDOT, KC_PENT, _______,    _______,   _______,  _______,    _______,    _______, KC_P0, KC_PDOT, KC_PENT, _______
    //   ),

	// [_ADJUST] = LAYOUT(
    //   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    //   _______, _______, _______, _______, _______, _______, _______,                   _______, _______, EEP_RST, _______, _______, _______, KC_F12,
    //   _______, _______, _______, _______, _______, _______, _______,                   _______, _______, RGB_TOG, _______, _______, _______, _______,
    //   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,
    //   _______, _______, _______, _______, _______,      _______,     _______, _______,     _______,      RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD
    //   )

};
#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current layer
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("LAYER"), false);

    switch (get_highest_layer(default_layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _MAC:
            oled_write_ln_P(PSTR("Mac"), false);
            break;
        case _SHIFT:
            oled_write_ln_P(PSTR("Shift"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("Num"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_90;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;
        case KC_MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC);
            }
            return false;
        case KC_CSFT:
            if (record->event.pressed) {
                layer_on(_SHIFT);
            } else {
                layer_off(_SHIFT);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
              rgblight_step();
        } else {
           rgblight_step_reverse();
        }
    }
    return true;
}

#endif
