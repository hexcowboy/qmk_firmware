typedef union {
    uint32_t raw;
    struct {
        bool rgb_layer_change :1;
    };
} user_config_t;

user_config_t user_config;

// Restore RGB settings from EEPROM
void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

// Initialize default RGB settings
void eeconfig_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_sethsv(
        RGB_MATRIX_STARTUP_HUE,
        RGB_MATRIX_STARTUP_SAT,
        RGB_MATRIX_STARTUP_VAL
    );
    rgb_matrix_mode(RGB_MATRIX_STARTUP_MODE);
    rgb_matrix_set_speed(RGB_MATRIX_STARTUP_SPD);
}

// Save RGB settings when changed
void eeconfig_save_user(uint16_t keycode) {
    switch (keycode) {
        // For any of the RGB key codes (see quantum_keycodes.h, L400 for reference)
        case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT:
            eeconfig_update_user(user_config.raw);
            break;
    }
}
