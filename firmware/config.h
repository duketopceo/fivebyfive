#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x5B5B
#define DEVICE_VER      0x0001
#define MANUFACTURER    LukeTopCEO
#define PRODUCT         FiveByFive Macropad

/* Key Matrix (2 Rows x 5 Cols)
 * Row 0: 5 Keys (K00 - K04)
 * Row 1: 5 Encoder Push Switches (K10 - K14)
 */
#define MATRIX_ROWS 2
#define MATRIX_COLS 5

#define MATRIX_ROW_PINS { GP0, GP1 }
#define MATRIX_COL_PINS { GP2, GP3, GP4, GP5, GP6 }
#define DIODE_DIRECTION COL2ROW

/* 5 Rotary Encoders (A, B pins) */
#define ENCODERS_PAD_A { GP7, GP9,  GP11, GP14, GP26 }
#define ENCODERS_PAD_B { GP8, GP10, GP12, GP15, GP27 }
#define ENCODER_RESOLUTION 4

/* Vial Configuration */
#define VIAL_KEYBOARD_UID {0x5B, 0x5B, 0x01, 0xA2, 0x4F, 0x8C, 0x3E, 0x91}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 4 }

/* Dynamic Keymap & EEPROM emulation on RP2040 Flash */
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 4095
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

/* Debounce */
#define DEBOUNCE 5
