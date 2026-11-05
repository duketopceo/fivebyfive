# Landscape: encoder-heavy QMK/Vial macropads

Written 2026-10-11 from one round of web searches plus the repo source. Thin by design: this is a firmware repo. Claims marked "vendor" come from a vendor's own page.

## Who else is here
- **Elgato Stream Deck.** Vendor comparison page frames macropads as programmable mechanical keys that send shortcuts, versus LCD keys with per-app plugins; it also notes static keycaps give no on-device layer indication. [Elgato](https://www.elgato.com/us/zh/explorer/products/stream-deck/stream-deck-vs-macropad-whats-the-difference/) (vendor).
- **Adafruit MacroPad RP2040.** 12 keys, OLED, speaker, one rotary encoder; QMK has a community port, 3x4 layout. [QMK readme](https://git.poz.pet/poz/qmk_firmware/raw/branch/master/keyboards/adafruit/macropad/readme.md), [CircuitPython board page](https://circuitpython.org/blinka/adafruit_macropad_rp2040/).
- **DIY QMK/Vial pads.** Typical builds add one or two encoders and sometimes an OLED for layer display; Vial is described as a GUI on top of QMK for remapping without compiling. [example 4-key + encoder pad](https://www.lectronz.com/products/macropad-little-big-scroll-4-v2).
- **Vial itself.** Porting docs treat a keymap folder named `vial` as "already ported" and a `vial.json` layout as the keyboard definition. [Vial porting guide](https://get.vial.today/docs/porting-to-vial.html).

## What they do better
- Stream Deck and Adafruit show state on a screen; fivebyfive has no display, so the active layer is invisible.
- Established boards ship a tested build; this repo has never been shown to compile (no CI).

## What users expect
Remap in a browser without compiling, visible layer state, a documented build, a released UF2.

## What is unique here
Five full-size encoders with push switches on one pad (five-knob is beyond the one-to-four seen above, per the sources searched), five layers pre-mapped for desk, code, Hyprland, audio and video, and Linux/Hyprland (Omarchy) as a first-class target.

## Findings from reading the code
- `firmware/keymaps/vial/keymap.c`: `F8` and `F9` should be `KC_F8` / `KC_F9`.
- `firmware/vial.json` is outside the `keymaps/vial/` folder where the Vial docs and guides put it.
- Layer state is invisible; the cheapest fix is the first key row (`TO(_DESK)`..`TO(_CREATOR)`), which already doubles as a layer selector, plus an optional status LED later.
