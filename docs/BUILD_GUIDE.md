# Build & Assembly Guide

## Staged Milestone Protocol

### Stage 1: Breadboard Single-Control Verification (Do this first!)
1. Wire **1 Switch** to Row 0 (`GP0`) and Col 0 (`GP2`).
2. Wire **1 Encoder** (Pins A/B to `GP7`/`GP8`, Common to `GND`, Push to Row 1 (`GP1`) & Col 0 (`GP2`)).
3. Flash the firmware `.uf2`.
4. Open [vial.rocks](https://vial.rocks) (or desktop Vial app).
5. Verify the key registers and the encoder rotations trigger CCW/CW actions cleanly.

### Stage 2: Solder Remaining Components
1. Solder Rows 0 and 1 with 1N4148 diodes (`COL2ROW`).
2. Solder Columns 0 through 4 across switches and encoder push pins.
3. Wire encoder quadrature lines (E1 through E5) to the designated RP2040 GPIOs.
4. Route common ground bus across all 5 encoder center pins.

### Stage 3: Housing Assembly
1. Mount switches and encoders into the 3D printed top plate.
2. Fasten heatset brass inserts into bottom case housing.
3. Secure the RP2040 in the mounting bay with USB-C port aligned.
4. Close housing with M2/M3 screws and attach rubber feet.
