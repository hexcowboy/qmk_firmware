#pragma once

#include "progmem.h"
#include "animation.c"

extern uint8_t is_master;
uint16_t oled_timer = 0;
// The oled_time is too small and will overflow, so use a suspend state
// to keep track of when the OLED should be turned off
bool oled_suspend = false;

// Initialize the OLED with 270 degree rotation
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// Renders the animation provided the frame (0-7)
void render_animation(uint8_t frame) {
    oled_write_raw_P(animation[frame], sizeof(animation[frame]));
}

// Runs continuously and determines render state for OLED
bool oled_task_user(void) {
    if (!rgb_matrix_is_enabled()) {
        oled_off();
    } else {
        if (!oled_suspend) {
            render_animation((timer_read() / 100) % 8);
        }
    }

    if (timer_elapsed(oled_timer) > OLED_TIMEOUT) {
        oled_suspend = true;
        oled_off();
    }

    return false;
}
