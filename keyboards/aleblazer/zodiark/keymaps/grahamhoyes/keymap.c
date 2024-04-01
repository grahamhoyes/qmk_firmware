/*
Copyright 2024 Graham Hoyes
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
    _GAME,
    _NUMPAD,
    _SYMBOL,
    _META,
};

enum custom_keycodes {
    KC_PRVWD = SAFE_RANGE,
    KC_NXTWD,
    // Ctrl by default, CMD in mac mode
    KC_CTRL_CMD,
};

typedef enum {
    // Super when tapped, switch between modes when double tapped
    TD_SUPER_SWITCH,
    // Spotlight search when tapped, switch between modes when double tapped
    TD_SPOTLIGHT_SWITCH,
} td_codes_t;

// Key overrides for programmer dvorak shifted numbers
const key_override_t pd_perc_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_PERC);
const key_override_t pd_7_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRACKET, KC_7);
const key_override_t pd_5_override = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_5);
const key_override_t pd_3_override = ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, KC_3);
const key_override_t pd_1_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_1);
const key_override_t pd_9_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQUAL, KC_9);
const key_override_t pd_circ_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_CIRC);
const key_override_t pd_0_override = ko_make_basic(MOD_MASK_SHIFT, KC_ASTR, KC_0);
const key_override_t pd_2_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_2);
const key_override_t pd_4_override = ko_make_basic(MOD_MASK_SHIFT, KC_PLUS, KC_4);
const key_override_t pd_6_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRACKET, KC_6);
const key_override_t pd_8_override = ko_make_basic(MOD_MASK_SHIFT, KC_EXLM, KC_8);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &pd_perc_override,
    &pd_7_override,
    &pd_5_override,
    &pd_3_override,
    &pd_1_override,
    &pd_9_override,
    &pd_circ_override,
    &pd_0_override,
    &pd_2_override,
    &pd_4_override,
    &pd_6_override,
    &pd_8_override,
    NULL
};

#ifdef POINTING_DEVICE_ENABLE
static bool is_scrolling = false;
#endif

/*
[] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ , _______
),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /** Base layers, intended to be set as default */

    [_BASE] = LAYOUT(
        KC_AMPR , KC_LBRACKET , KC_LCBR   , KC_RCBR           , KC_LPRN           , KC_EQUAL           ,                                                     KC_ASTR , KC_RPRN , KC_PLUS , KC_RBRACKET , KC_EXLM  , KC_GRAVE ,
        KC_TAB  , KC_SCOLON   , KC_COMMA  , KC_DOT            , KC_P              , KC_Y               , KC_AT   ,                     KC_BSLS             , KC_F    , KC_G    , KC_C    , KC_R        , KC_L     , KC_SLASH ,
        KC_ESC  , KC_A        , KC_O      , LT(_SYMBOL, KC_E) , LT(_NUMPAD, KC_U) , LT(_SYMBOL, KC_I)  , KC_HOME ,                     KC_END              , KC_D    , KC_H    , KC_T    , KC_N        , KC_S     , KC_MINUS ,
        KC_LSFT , KC_QUOTE    , KC_Q      , KC_J              , KC_K              , LT(_META, KC_X)    , KC_LALT , KC_MUTE , RGB_TOG , TD(TD_SUPER_SWITCH) , KC_B    , KC_M    , KC_W    , KC_V        , KC_Z     , KC_RSFT  ,
        KC_LCTL , KC_MEH      , KC_PC_CUT , KC_PC_COPY        , KC_PC_PASTE       ,                      KC_BSPC , KC_DEL  , KC_ENT  , KC_SPACE            ,           KC_LEFT , KC_DOWN , KC_UP       , KC_RIGHT , KC_RCTRL
    ),

    [_MAC] = LAYOUT(
        _______ , _______  , _______    , _______     , _______      , _______ ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______  , _______    , _______     , _______      , _______ , _______ ,                     _______                 , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______  , _______    , _______     , _______      , _______ , _______ ,                     _______                 , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______  , _______    , _______     , _______      , _______ , _______ , _______ , _______ , TD(TD_SPOTLIGHT_SWITCH) , _______ , _______ , _______ , _______ , _______ , _______ ,
        KC_LGUI , KC_LCTRL , KC_MAC_CUT , KC_MAC_COPY , KC_MAC_PASTE ,           _______ , _______ , _______ , _______                 ,           _______ , _______ , _______ , _______ , KC_RGUI
    ),

    [_GAME] = LAYOUT(
        _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                                                      _______ , KC_0    , KC_MINUS , KC_PLUS , _______ , _______ ,
        KC_TAB  , KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T     ,                     _______             , _______ , KC_7    , KC_8     , KC_9    , _______ , _______ ,
        KC_ESC  , KC_ESC  , KC_A    , KC_S    , KC_D    , KC_F    , KC_M     ,                     _______             , _______ , KC_4    , KC_5     , KC_6    , _______ , _______ ,
        KC_LSFT , KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_LALT  , KC_MUTE , RGB_TOG , TD(TD_SUPER_SWITCH) , _______ , KC_1    , KC_2     , KC_3    , _______ , _______ ,
        KC_LCTL , KC_LCTL , KC_I    , KC_B    , KC_LALT ,           KC_SPACE , KC_ENT  , KC_ENT  , _______             , _______ , _______ , _______  , _______ , _______
    ),

    /** Overlay layers*/

    [_NUMPAD] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______   , _______ , KC_KP_PLUS , KC_KP_ASTERISK , KC_KP_MINUS , _______     ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , KC_PGUP   , KC_7    , KC_8       , KC_9           , KC_KP_PLUS  , _______     ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , KC_PGDOWN , KC_4    , KC_5       , KC_6           , KC_KP_PLUS  , _______     ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_X      , KC_1    , KC_2       , KC_3           , KC_KP_ENTER , KC_KP_ENTER ,
        _______ , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ ,             KC_0    , KC_0       , KC_DOT         , KC_KP_ENTER , _______
    ),

    [_SYMBOL] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______  , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , KC_TILD  , KC_DLR  , KC_CIRC , KC_PERC , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , KC_GRAVE , KC_HASH , KC_AT   , KC_AMPR , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ ,           _______  , _______ , _______ , _______ , _______
    ),

    [_META] = LAYOUT(
        _______ , _______     , _______ , _______ , _______ , _______ ,                                         _______   , KC_F10  , KC_F11  , KC_F12  , _______ , _______ ,
        _______ , _______     , _______ , _______ , _______ , _______ , _______ ,                     _______ , KC_PGUP   , KC_F7   , KC_F8   , KC_F9   , _______ , _______ ,
        _______ , KC_CTRL_CMD , KC_LSFT , KC_LALT , _______ , _______ , _______ ,                     _______ , KC_PGDOWN , KC_F4   , KC_F5   , KC_F6   , _______ , _______ ,
        _______ , _______     , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______   , KC_F1   , KC_F2   , KC_F3   , _______ , _______ ,
        _______ , _______     , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ ,             _______ , _______ , _______ , _______ , _______
    ),

};

static uint8_t get_next_base_layer(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _BASE:
            return _MAC;
        case _MAC:
            return _GAME;
        case _GAME:
            return _BASE;
        default:
            return _BASE;
    }
}

static uint8_t get_os_mode(void) {
    return get_highest_layer(default_layer_state);
}

#ifdef OLED_ENABLE


static void print_oled_left(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);

    switch (get_os_mode()) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _MAC:
            oled_write_ln_P(PSTR("Mac"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    // Print current layer
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _MAC:
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("Numpad"), false);
            break;
        case _SYMBOL:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case _META:
            oled_write_ln_P(PSTR("Meta"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    // Print WPM
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("WPM"), false);
    char wpm_buffer[4] = { 0 };
    itoa(get_current_wpm(), wpm_buffer, 10);
    oled_write_ln(wpm_buffer, false);
}

static void print_oled_right(void) {
    // Print WPM
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("   WPM"), false);
    oled_write_P(PSTR("   "), false);
    char wpm_buffer[4] = { 0 };
    itoa(get_current_wpm(), wpm_buffer, 10);
    oled_write_ln(wpm_buffer, false);

    #ifdef POINTING_DEVICE_ENABLE
    // Print Scrolling
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("   SCRL"), false);
    if (is_scrolling) {
        oled_write_ln_P(PSTR("   y"), false);
    } else {
        oled_write_ln_P(PSTR("   n"), false);
    }
    #endif
    
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_90;
    } else {
        return OLED_ROTATION_270;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        // print_status_narrow();
        print_oled_left();
    } else {
        // render_logo();
        print_oled_right();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CTRL_CMD: {
            // Control in normal mode, cmd in mac mode
            uint16_t code = get_os_mode() == _MAC ? KC_LGUI : KC_LCTL;
            if (record->event.pressed) {
                register_code(code);
            } else {
                unregister_code(code);
            }
            return false;
        }
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
            return false;
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
            return false;
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

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_MORE_TAPS,
} td_state_t;

typedef struct {
    bool is_pressed_action;
    td_state_t state;
} td_tap_t;

td_state_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    return TD_MORE_TAPS;
}

// Should be the same size as td_codes_t
td_tap_t dance_states[3];

// Super Switch: Single tap or hold for super, double tap to activate mac mode
void dance_super_switch_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_states[TD_SUPER_SWITCH].state = dance_step(state);

    switch (dance_states[TD_SUPER_SWITCH].state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            register_code16(KC_LGUI);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code16(KC_LGUI);
            register_code16(KC_LGUI);
            break;
        case TD_DOUBLE_TAP:
            // set_single_persistent_default_layer(_MAC);
            set_single_persistent_default_layer(get_next_base_layer());
            break;
        default:
            break;
    }
}

void dance_super_switch_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (dance_states[TD_SUPER_SWITCH].state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(KC_LGUI);
            break;
        default:
            break;
    }

    dance_states[TD_SUPER_SWITCH].state = TD_NONE;
}

// Spotlight Base: Single tap for spotlight search, double tap to activate base mode
void dance_spotlight_switch_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_states[TD_SPOTLIGHT_SWITCH].state = dance_step(state);

    switch(dance_states[TD_SPOTLIGHT_SWITCH].state) {
        case TD_SINGLE_TAP:
            register_code16(LGUI(KC_SPACE));
            break;
        case TD_DOUBLE_TAP:
            set_single_persistent_default_layer(get_next_base_layer());
            break;
        default:
            break;
    }
}

void dance_spotlight_switch_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch(dance_states[TD_SPOTLIGHT_SWITCH].state) {
        case TD_SINGLE_TAP:
            unregister_code16(LGUI(KC_SPACE));
            break;
        default:
            break;
    }

    dance_states[TD_SPOTLIGHT_SWITCH].state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SUPER_SWITCH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_super_switch_finished, dance_super_switch_reset),
    [TD_SPOTLIGHT_SWITCH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_spotlight_switch_finished, dance_spotlight_switch_reset),
};

#ifdef POINTING_DEVICE_ENABLE
void set_scrolling(bool scroll) {
    is_scrolling = scroll;

    if (is_scrolling) {
        pointing_device_set_cpi(1000);
    } else {
        pointing_device_set_cpi(25000);
    }
}

static uint16_t trackball_debounce_timer;
static bool trackball_debounce = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (mouse_report.buttons) {
        if (trackball_debounce) {
            if (timer_elapsed(trackball_debounce_timer) > 500) {
                trackball_debounce = false;
            }
        }

        if (!trackball_debounce) {
            set_scrolling(!is_scrolling);
            trackball_debounce = true;
            trackball_debounce_timer = timer_read();
        }
           
    }
    mouse_report.buttons = 0;

    if (is_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = mouse_report.y = 0;
    }
    
    return mouse_report;
}
#endif

void keyboard_post_init_user(void) {
    #ifdef POINTING_DEVICE_ENABLE
    set_scrolling(true);
    #endif
}