<p align="center">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="assets/brand/wordmark-dark.svg">
    <img alt="fivebyfive" src="assets/brand/wordmark.svg" height="52">
  </picture>
</p>

Firmware for a 5-key, 5-knob USB macropad on RP2040, built for QMK and Vial. Five layers are pre-mapped for desk, code, Hyprland, audio and video work.

> **Status: unverified firmware.** The source has not been shown to compile or run on a board. A review of the keymap found two likely compile errors (`F8`, `F9`) and a `vial.json` outside the keymap folder; see [ROADMAP.md](ROADMAP.md). Logo is a proposal pending owner sign-off.

## What is in the box
- 5 mechanical switches (matrix row 0) and 5 EC11 encoders with push switches (matrix row 1), on an RP2040 (Pico, RP2040-Zero or XIAO RP2040 per [`hardware/pinout.md`](hardware/pinout.md)).
- QMK with Vial for live remapping; encoder maps per layer; 5 dynamic-keymap layers.

| Layer | Name | Keys |
|---|---|---|
| 0 | Desk | jump to layers 0-4 |
| 1 | Code | format, go to definition, quick fix, terminal, git |
| 2 | Omarchy | Hyprland workspaces 1-5 |
| 3 | Audio | transport, record, solo, mute, loop |
| 4 | Creator | cut, ripple delete, snapping, blade, export |

Encoder rotation and press per layer: [`firmware/keymaps/vial/keymap.c`](firmware/keymaps/vial/keymap.c) and [`profiles/`](profiles/).

## How it works
```text
5 keys + 5 encoders -> RP2040 (QMK, Vial) -> USB HID keycodes and media keys -> any OS
                                  ^
                       vial.rocks / Vial app edits the keymap live
```
Encoders send standard HID and consumer-control codes, so no host daemon is needed.

## Repository layout
```text
firmware/   QMK + Vial keyboard definition (config.h, rules.mk, info.json, vial.json, keymaps/vial)
hardware/   pinout, wiring, BOM
enclosure/  case notes
profiles/   per-layer encoder presets (reference)
docs/       build guide, flashing, QA checklist, plans, research
desktop/    blueprint for a possible v2 companion app (not started)
assets/brand/  logo proposal
```

## Quick start
1. Open the repo in the Dev Container (QMK CLI and ARM GCC): `devcontainer up --workspace-folder .`
2. Build and flash following [`docs/BUILD_GUIDE.md`](docs/BUILD_GUIDE.md) and [`docs/FLASHING.md`](docs/FLASHING.md): hold BOOTSEL while plugging in USB, then copy the `.uf2` to the `RPI-RP2` drive.
3. Remap at [vial.rocks](https://vial.rocks) in a Chromium browser, or with the Vial app.

Bring up one switch and one encoder first (Stage 1 of the build guide) before wiring all ten controls.

## Roadmap
[ROADMAP.md](ROADMAP.md). Design direction: [DESIGN.md](DESIGN.md). Market notes: [docs/research/](docs/research/2026-10-10-landscape.md).

## Contributing
Issues and PRs welcome. Keep the Vial UID unchanged, and keep encoder actions on standard HID keycodes. See [AGENTS.md](AGENTS.md).

## Acknowledgments
- [`vial-kb/vial-qmk`](https://github.com/vial-kb/vial-qmk), [`qmk/qmk_firmware`](https://github.com/qmk/qmk_firmware)
- [`BlueDragonGXX/12KEMP`](https://github.com/BlueDragonGXX/12KEMP) (project anatomy), [`Squalius-cephalus/silli18`](https://github.com/Squalius-cephalus/silli18) (RP2040 encoder notes), [`TilePad/tilepad-desktop`](https://github.com/tilePad/tilepad-desktop) (future companion architecture)

## License
Firmware: GPL-2.0 / GPL-3.0, consistent with QMK. Hardware and docs: MIT / CERN-OHL-P. See [LICENSE](LICENSE).
