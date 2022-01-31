#pragma once

#include "progmem.h"
#include "animation.c"

extern uint8_t is_master;
uint16_t oled_timer = 0;
bool oled_suspend = false;

// Initialize the OLED with 270 degree rotation and half brightness
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_set_brightness(3);
    return OLED_ROTATION_270;
}

// Renders the animation provided the frame (0-7)
void render_animation(uint8_t frame) {
    oled_write_raw_P(animation[frame], sizeof(animation[frame]));
}

// Runs continuously and determines render state for OLED
bool oled_task_user(void) {
    if (timer_elapsed(oled_timer) > OLED_TIMEOUT) {
        oled_suspend = true;
    }

    if (rgb_matrix_is_enabled()) {
        if (get_current_wpm() > 0) {
            oled_suspend = false;
            oled_timer = 0;
        }
    }

    if (rgb_matrix_is_enabled() && !oled_suspend) {
        render_animation((timer_read() / 100) % 8);
    } else {
        if (is_oled_on()) {
            oled_clear();
            oled_off();
        }
    }

    return false;
}
