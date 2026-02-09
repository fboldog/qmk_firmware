#include "quantum.h"
#include "print.h"

#ifndef RGB_DRIVER_EN_STATE
#    define RGB_DRIVER_EN_STATE 1
#endif


#ifdef CONSOLE_ENABLE
void keyboard_post_init_kb(void) {
    debug_enable   = true;
    debug_matrix   = false;
    debug_keyboard = false;

    keyboard_post_init_user();
}
#endif  // CONSOLE_ENABLE

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }

#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    uprintf("kc: %s\n", get_keycode_string(keycode));
#endif

// switch (keycode) {
//       case QK_RGB_MATRIX_TOGGLE:
//         if(record->event.pressed) {
//             // eeconfig_update_rgb_matrix_default();
//             uprint("RGB Matrix Toggle pressed\n");
//         }
//         return false;
//   }
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
    writePin(RGB_DRIVER_EN_PIN, RGB_DRIVER_EN_STATE);
#endif

}

