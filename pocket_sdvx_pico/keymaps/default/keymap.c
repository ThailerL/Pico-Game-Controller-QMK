// Copyright 2023 Thailer lietz (@ThailerL)
// SPDX-License-Identifier: GPL-3.0-or-later
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        JS_0, JS_1, JS_8, JS_2, JS_3,
              JS_4, TO(1),JS_5
    ),
    LAYOUT(
        KC_D, KC_F, KC_1, KC_J, KC_K,
              KC_C, TO(0),KC_M
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    { ENCODER_CCW_CW(VOL_L_LEFT, VOL_L_RIGHT), ENCODER_CCW_CW(VOL_R_LEFT, VOL_R_RIGHT) },
    { ENCODER_CCW_CW(KC_MS_LEFT, KC_MS_RIGHT), ENCODER_CCW_CW(KC_MS_DOWN, KC_MS_UP) }
};
