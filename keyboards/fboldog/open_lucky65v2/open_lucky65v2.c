#include "quantum.h"
#include "print.h"
#include "rgb_matrix.h"
#include "timer.h"

static void change_rgb_matrix_state(bool enable);
static void walk_red_leds(void);

#ifndef RGB_DRIVER_ENABLE_STATE
#    define RGB_DRIVER_ENABLE_STATE 1
#endif

#ifndef RGB_DRIVER_DISABLE_STATE
#    define RGB_DRIVER_DISABLE_STATE 1
#endif

#define MY_LED_COUNT RGB_MATRIX_LED_COUNT
#define WALK_DELAY 5000


// #ifdef CONSOLE_ENABLE
void keyboard_post_init_kb(void) {
    debug_enable   = true;
    // debug_matrix   = false;
    // debug_keyboard = false;

    keyboard_post_init_user();
}
// #endif  // CONSOLE_ENABLE

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }

#ifdef CONSOLE_ENABLE
    // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    // uprintf("kc: %s\n", get_keycode_string(keycode));
#endif

    switch (keycode) {
        case QK_RGB_MATRIX_TOGGLE:
            if(record->event.pressed) {
                uprint("RGB Matrix TOGGLE\n");
                change_rgb_matrix_state(!rgb_matrix_is_enabled());
                return true;
            }
            return false;
        case QK_RGB_MATRIX_ON:
            if(record->event.pressed) {
                uprint("RGB Matrix ON\n");
                change_rgb_matrix_state(true);
                return true;
            }
            return false;
        case QK_RGB_MATRIX_OFF:
            if(record->event.pressed) {
                uprint("RGB Matrix OFF\n");
                change_rgb_matrix_state(false);
                return true;
            }
            return false;
    }
  return true;
}

// pre init
void keyboard_pre_init_user(void) {
    //  eeconfig_init();
    //  eeconfig_update_rgb_matrix_default();
    //  rgb_matrix_enable_noeeprom();
    //  rgb_matrix_config.enable = true;
#ifdef RGB_DRIVER_EN_PIN
    setPinOutput(RGB_DRIVER_EN_PIN);
#endif
}

void keyboard_post_init_user(void) {
    writePin(RGB_DRIVER_EN_PIN, RGB_DRIVER_ENABLE_STATE);
    // rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    // rgb_matrix_set_color(0, RGB_OFF);
}


    static uint8_t  current    = 0;
    static uint16_t last_step  = 0;


void change_rgb_matrix_state(bool enable) {
    uprintf("rgb matrix enable => %b\n", enable);
    if (enable) {
        // writePin(RGB_DRIVER_EN_PIN, RGB_DRIVER_ENABLE_STATE);
        rgb_matrix_enable();
        // for (uint8_t i = 0; i < MY_LED_COUNT; i++) {
        //     rgb_matrix_set_color(i, RGB_OFF);
        // }
        // rgb_matrix_sethsv_noeeprom(HSV_WHITE);
        // rgb_matrix_set_color(0, RGB_RED);
    } else {
            // Turn all LEDs off
    for (uint8_t i = 0; i < MY_LED_COUNT; i++) {
        rgb_matrix_set_color(i, RGB_OFF);
    }
        // writePin(RGB_DRIVER_EN_PIN, RGB_DRIVER_DISABLE_STATE);
        rgb_matrix_disable();
    current = 0;
    last_step = 0;

    }
}

void walk_red_leds(void) {

    // Initialize timer on first run
    if (last_step == 0) {
        last_step = timer_read();
    }

    // Wait until WALK_DELAY ms have passed
    if (timer_elapsed(last_step) < WALK_DELAY) {
        return;
    }
    last_step = timer_read();

    // Turn current LED on in red
    uprintf("switching on: %d\n", current);
    rgb_matrix_set_color(current, RGB_BLUE);

    // Advance to next LED with wraparound
    current++;
    if (current >= MY_LED_COUNT) {
        current = 0;
    }
}

void matrix_scan_user(void) {
    if (rgb_matrix_is_enabled()) {
        walk_red_leds();
    }
}
