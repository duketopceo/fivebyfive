# FiveByFive — 5-Key + 5-Knob Macropad (RP2040 + QMK/Vial)

A compact, highly-functional physical macropad featuring **5 mechanical switches** and **5 rotary encoders** (with push switches), driven by an RP2040 microcontroller and running **Vial-QMK** firmware for instant, cross-platform remapping.

---

## 📐 Project Anatomy

```text
fivebyfive/
├── .devcontainer/  # Ready-to-use container with QMK CLI & ARM GCC toolchain
├── firmware/       # QMK + Vial keyboard definition (RP2040)
│   ├── config.h    # Pin assignments, matrix definition, Vial UID
│   ├── rules.mk    # RP2040 flags, ENCODER_MAP_ENABLE, VIAL_ENABLE
│   ├── info.json   # Layout visual positioning
│   ├── vial.json   # Real-time Vial layout & encoder configuration
│   └── keymaps/
│       └── vial/   # 5 default layers (Desk, Code, Omarchy, Audio, Creator)
├── hardware/       # Pinout specs, wiring diagrams, Bill of Materials (BOM)
├── enclosure/      # Case 3D printing specs and dimensions
├── profiles/       # Layer presets for Desk, Coding, Omarchy/Hyprland, Audio, Video
├── docs/           # Build guide, RP2040 UF2 flashing steps, QA checklist
└── desktop/        # Blueprint for future v2 Tauri/Rust companion
```

---

## 🚀 Quick Start

### 1. Build Firmware with Dev Container
Open this repository in your Dev Container (or using `@devcontainers/cli`):

```bash
devcontainer up --workspace-folder .
```

### 2. Flash RP2040
1. Hold **BOOTSEL** while plugging the USB cable into the RP2040.
2. Drag and drop the compiled `.uf2` binary into the `RPI-RP2` drive.

### 3. Configure via Vial
Open [https://vial.rocks](https://vial.rocks) in any Chromium browser or launch the Vial app to remap keys and rotary actions in real time.

---

## 📚 Acknowledgments & References
- [`vial-kb/vial-qmk`](https://github.com/vial-kb/vial-qmk) — Live remapping, layers, macros, and encoder maps.
- [`qmk/qmk_firmware`](https://github.com/qmk/qmk_firmware) — Canonical QMK keyboard firmware.
- [`BlueDragonGXX/12KEMP`](https://github.com/BlueDragonGXX/12KEMP) — Macropad structure and project anatomy reference.
- [`Squalius-cephalus/silli18`](https://github.com/Squalius-cephalus/silli18) — RP2040 rotary encoder implementation notes.
- [`TilePad/tilepad-desktop`](https://github.com/tilePad/tilepad-desktop) — Architecture reference for future v2 Tauri/Rust desktop companion.

---

## 📄 License
Firmware portions are licensed under **GPL-2.0 / GPL-3.0** consistent with QMK. Hardware and documentation are licensed under **MIT / CERN-OHL-P**.
