#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE
#   include "oled.c"
#endif

#ifdef RGB_MATRIX_ENABLE
#   include "rgb.c"
#endif

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _GAME,
    _GAME_RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_P,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LGUI, KC_LSFT,     KC_SPC,   MO(1),   MO(2)
                                      //`--------------------------'  `--------------------------'
  ),

    [_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    S(KC_GRV), S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                      S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_GRAVE,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LALT,S(KC_BSLS),S(KC_EQL),KC_MINS,S(KC_MINS),KC_EQL,                      KC_QUOT, KC_LBRC, KC_RBRC,  KC_DOT, KC_BSLS,KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LGUI, KC_LSFT,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_HUD, RGB_HUI, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, RGB_VAD, RGB_VAI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_SAD, RGB_SAI, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, RGB_SPD, RGB_SPI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          RGB_TOG, KC_BTN2, KC_BTN1,   RGB_RMOD, RGB_MOD, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAME] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_E,    KC_W,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_F,    KC_A,    KC_S,    KC_D,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_P,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  MO(_GAME_RAISE), KC_LCTL,  KC_SPC,     KC_SPC,   MO(1),   MO(2)
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAME_RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    TG(_GAME), XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_Y,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6,    KC_H,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX,    KC_7,    KC_8,    KC_9,    KC_N,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Only run when a key is pressed to avoid running on release as well
    if (record->event.pressed) {
        oled_write_ln_P(PSTR("process_record_user"), false); // debug

        /* if (rgb_matrix_is_enabled()) { */
        /*     // Reset the OLED clock to prevent from suspending */
        /*     oled_timer = timer_read(); */
        /*     oled_suspend = false; */
        /* } */

        /* // Save the RGB state */
        /* eeconfig_save_user(keycode); */
    } else {
        oled_clear();
    }

    return true;
}
