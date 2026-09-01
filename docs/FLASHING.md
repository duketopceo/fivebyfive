# Flashing & Firmware Compilation Guide

## Step 1: Build Firmware
Using the pre-configured devcontainer or QMK CLI:

```bash
# Set Vial-QMK target keyboard directory
# In vial-qmk repository:
qmk compile -kb fivebyfive -km vial
```

The build will generate:
`fivebyfive_vial.uf2`

## Step 2: Flash onto RP2040
1. Unplug the RP2040 USB cable.
2. Hold down the **BOOTSEL** button on the RP2040 board.
3. Plug the USB cable into your computer while holding BOOTSEL, then release.
4. An external drive named `RPI-RP2` will mount automatically.
5. Drag and drop `fivebyfive_vial.uf2` onto the `RPI-RP2` drive.
6. The RP2040 will automatically reboot and start running Vial firmware immediately.

## Step 3: Open Vial UI
- Visit [https://vial.rocks](https://vial.rocks) in a WebHID-enabled browser (Chrome/Edge/Chromium).
- Or install the standalone Vial desktop app (`vial` package on Arch/Omarchy: `yay -S vial-appimage`).
- The 5 keys and 5 encoders will appear instantly for live remapping.
