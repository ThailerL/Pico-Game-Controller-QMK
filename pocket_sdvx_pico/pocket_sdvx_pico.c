// Copyright 2023 Thailer lietz (@ThailerL)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "pocket_sdvx_pico.h"
const int VOL_SPEED = 3;
const pin_t led_matrix_pins[MATRIX_ROWS][MATRIX_COLS] = {
    { GP5,    GP7,  GP21,   GP9,  GP11 },
    { NO_PIN, GP13, NO_PIN, GP15, NO_PIN }
};

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
};

void keyboard_post_init_kb(void) {
    for (int row = 0; row < MATRIX_ROWS; row++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            pin_t pin = led_matrix_pins[row][col];
            if (pin != NO_PIN) {
                setPinOutput(pin);
            }
        }
    }
}

int wrap_joystick_value(int value) {
    const int max = (1 << (JOYSTICK_AXIS_RESOLUTION - 1)) - 1;
    const int min = -max;
    if (value < min) {
        return max - (min - value) + 1;
    } else if (value > max) {
        return min + value - max - 1;
    }
    return value;
}

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }

    static int16_t current_VOL_L = 0;
    static int16_t current_VOL_R = 0;

    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;
    pin_t pin = led_matrix_pins[row][col];
    if (pin != NO_PIN) {
        if (record->event.pressed) {
            writePinHigh(pin);
        } else {
            writePinLow(pin);
        }
    }

    if (record->event.pressed) {
        switch (keycode) {
        case VOL_L_LEFT:
            current_VOL_L = wrap_joystick_value(current_VOL_L - VOL_SPEED);
            joystick_set_axis(0, current_VOL_L);
            return false;
        case VOL_L_RIGHT:
            current_VOL_L = wrap_joystick_value(current_VOL_L + VOL_SPEED);
            joystick_set_axis(0, current_VOL_L);
            return false;
        case VOL_R_LEFT:
            current_VOL_R = wrap_joystick_value(current_VOL_R - VOL_SPEED);
            joystick_set_axis(1, current_VOL_R);
            return false;
        case VOL_R_RIGHT:
            current_VOL_R = wrap_joystick_value(current_VOL_R + VOL_SPEED);
            joystick_set_axis(1, current_VOL_R);
            return false;
        default:
            break;
        }
    }

    return true;
}
