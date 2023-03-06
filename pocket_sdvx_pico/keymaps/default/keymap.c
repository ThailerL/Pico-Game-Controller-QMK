// Copyright 2023 Thailer lietz (@ThailerL)
// SPDX-License-Identifier: GPL-3.0-or-later
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        JS_0, JS_1, JS_8, JS_2, JS_3,
             JS_4 , JS_6, JS_5
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    { ENCODER_CCW_CW(VOL_L_LEFT, VOL_L_RIGHT), ENCODER_CCW_CW(VOL_R_LEFT, VOL_R_RIGHT) }
};
