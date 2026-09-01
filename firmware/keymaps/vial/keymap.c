#include QMK_KEYBOARD_H

enum layers {
    _DESK = 0,
    _CODE,
    _OMARCHY,
    _AUDIO,
    _CREATOR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Desk Mode
     * Keys: Switch to Layer 0, Layer 1, Layer 2, Layer 3, Layer 4
     * Encoder Buttons: Mute Audio, Play/Pause, Middle Click, Zoom Reset, Display Sleep
     */
    [_DESK] = LAYOUT(
        TO(_DESK), TO(_CODE), TO(_OMARCHY), TO(_AUDIO), TO(_CREATOR),
        KC_MUTE,   KC_MPLY,   KC_BTN3,      C(KC_0),    KC_BRID
    ),

    /* Layer 1: Code Mode
     * Keys: Format, GoTo Def, Quick Fix, Terminal Toggle, Git Commit
     * Encoder Buttons: Run Build, Next Error, Git Diff, Zoom Reset, Toggle Sidebar
     */
    [_CODE] = LAYOUT(
        A(S(KC_F)), KC_F12,    C(KC_DOT),   C(KC_GRAVE), C(S(KC_G)),
        C(S(KC_B)), F8,        A(KC_F7),    C(KC_0),     C(KC_B)
    ),

    /* Layer 2: Omarchy / Hyprland Mode
     * Keys: Hyprland Workspace 1-5
     * Encoder Buttons: Toggle Floating, Fullscreen, Kill Window, Toggle Split, Launch Terminal
     */
    [_OMARCHY] = LAYOUT(
        G(KC_1),     G(KC_2),   G(KC_3),    G(KC_4),     G(KC_5),
        G(KC_V),     G(KC_F),   G(KC_Q),    G(KC_J),     G(KC_ENT)
    ),

    /* Layer 3: Audio Production Mode
     * Keys: Play/Pause, Record, Solo, Mute, Loop Toggle
     * Encoder Buttons: Playhead to Start, Split Clip, Add Marker, Reset Gain, Metronome
     */
    [_AUDIO] = LAYOUT(
        KC_SPACE,    KC_R,      KC_S,       KC_M,        KC_L,
        KC_HOME,     C(KC_E),   KC_M,       KC_0,        KC_K
    ),

    /* Layer 4: Creator / Video Mode
     * Keys: Cut, Ripple Delete, Snapping, Blade Tool, Export
     * Encoder Buttons: In-Point, Out-Point, Fit to Window, Keyframe, Record OBS
     */
    [_CREATOR] = LAYOUT(
        C(KC_K),     S(KC_DEL), KC_N,       KC_B,        C(KC_M),
        KC_I,        KC_O,      S(KC_Z),    KC_K,        F9
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    /* Layer 0: Desk (Volume, Media Track, Vertical Scroll, Browser Zoom, Screen Brightness) */
    [_DESK] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
        ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP),
        ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)),
        ENCODER_CCW_CW(KC_BRID, KC_BRIU)
    },

    /* Layer 1: Code (Workspace Nav, Tab Switch, Terminal Scroll, Font Zoom, Git Hunk Nav) */
    [_CODE] = {
        ENCODER_CCW_CW(C(A(KC_LEFT)), C(A(KC_RGHT))),
        ENCODER_CCW_CW(C(KC_PGUP), C(KC_PGDN)),
        ENCODER_CCW_CW(C(S(KC_PGUP)), C(S(KC_PGDN))),
        ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)),
        ENCODER_CCW_CW(A(KC_UP), A(KC_DOWN))
    },

    /* Layer 2: Omarchy (Workspace Focus, Window Resize, Focus Window, Move Window, Master Split) */
    [_OMARCHY] = {
        ENCODER_CCW_CW(G(C(KC_LEFT)), G(C(KC_RGHT))),
        ENCODER_CCW_CW(G(A(KC_LEFT)), G(A(KC_RGHT))),
        ENCODER_CCW_CW(G(KC_LEFT), G(KC_RGHT)),
        ENCODER_CCW_CW(G(S(KC_LEFT)), G(S(KC_RGHT))),
        ENCODER_CCW_CW(G(KC_MINS), G(KC_EQL))
    },

    /* Layer 3: Audio (Input Gain, Output Volume, Timeline Scrub, Marker Scrub, Track Select) */
    [_AUDIO] = {
        ENCODER_CCW_CW(C(KC_VOLD), C(KC_VOLU)),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_LEFT, KC_RGHT),
        ENCODER_CCW_CW(KC_UP, KC_DOWN),
        ENCODER_CCW_CW(S(KC_UP), S(KC_DOWN))
    },

    /* Layer 4: Creator (OBS Scene, Source Transform, Timeline Zoom, Frame-by-Frame, Speed) */
    [_CREATOR] = {
        ENCODER_CCW_CW(C(A(KC_F1)), C(A(KC_F2))),
        ENCODER_CCW_CW(A(KC_LEFT), A(KC_RGHT)),
        ENCODER_CCW_CW(A(KC_MINS), A(KC_EQL)),
        ENCODER_CCW_CW(KC_LEFT, KC_RGHT),
        ENCODER_CCW_CW(S(KC_J), S(KC_L))
    }
};
#endif
