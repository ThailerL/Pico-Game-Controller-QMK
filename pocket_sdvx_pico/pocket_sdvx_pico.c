// Copyright 2023 Thailer lietz (@ThailerL)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "pocket_sdvx_pico.h"

const int VOL_SPEED = 3;

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL,
    JOYSTICK_AXIS_VIRTUAL
};

int wrap(int value) {
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

    if (record->event.pressed) {
        switch (keycode) {
        case VOL_L_LEFT:
            current_VOL_L = wrap(current_VOL_L - VOL_SPEED);
            joystick_set_axis(0, current_VOL_L);
            return false;
        case VOL_L_RIGHT:
            current_VOL_L = wrap(current_VOL_L + VOL_SPEED);
            joystick_set_axis(0, current_VOL_L);
            return false;
        case VOL_R_LEFT:
            current_VOL_R = wrap(current_VOL_R - VOL_SPEED);
            joystick_set_axis(1, current_VOL_R);
            return false;
        case VOL_R_RIGHT:
            current_VOL_R = wrap(current_VOL_R + VOL_SPEED);
            joystick_set_axis(1, current_VOL_R);
            return false;
        default:
            break;
        }
    }

    return true;
}

void keyboard_post_init_kb(void) {
    debug_enable = true;
    debug_matrix = true;
    debug_keyboard = true;
    // debug_mouse = true;
}
