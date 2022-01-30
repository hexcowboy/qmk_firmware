#pragma once

#include "progmem.h"
#include "animation.c"

extern uint8_t is_master;
static uint16_t oled_timer = 0;
/* bool oled_suspend = false; */

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_animation(uint8_t frame) {
    oled_write_raw_P(animation[frame], sizeof(animation[frame]));
}

bool oled_task_user(void) {
    // Disable the OLED if:
    //   - The timer has just passed the limit
    //   - RGB mode is disabled
    if (timer_elapsed(oled_timer) > OLED_TIMEOUT) {
        oled_off();
    }

    if (!rgb_matrix_is_enabled()) {
        oled_off();
    } else {
        render_animation((timer_read() / 100) % 8);
    }
    return false;
}
