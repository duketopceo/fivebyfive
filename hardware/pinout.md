# RP2040 Pinout Specification

## Microcontroller Options
- **Raspberry Pi Pico** (RP2040)
- **Waveshare RP2040-Zero** / **Seeed XIAO RP2040** (compact form-factor)

## Matrix Mapping (2 Rows x 5 Columns)
| Pin | Role | Connection |
|---|---|---|
| **GP0** | Row 0 | Mechanical Switches (K1, K2, K3, K4, K5) |
| **GP1** | Row 1 | Encoder Push Switches (E1_SW, E2_SW, E3_SW, E4_SW, E5_SW) |
| **GP2** | Col 0 | Switch 1 & Encoder 1 Push Pin |
| **GP3** | Col 1 | Switch 2 & Encoder 2 Push Pin |
| **GP4** | Col 2 | Switch 3 & Encoder 3 Push Pin |
| **GP5** | Col 3 | Switch 4 & Encoder 4 Push Pin |
| **GP6** | Col 4 | Switch 5 & Encoder 5 Push Pin |

*Note: Diodes (1N4148) are placed in `COL2ROW` orientation: Cathode (black band) facing the Row pins.*

## Rotary Encoders Quadrature Lines (EC11)
Each EC11 encoder has 3 pins on one side (A, Ground, B) and 2 pins on the opposite side (Push Switch).

| Encoder | Pin A (Signal) | Common Ground | Pin B (Signal) | Push Button Matrix Coordinate |
|---|---|---|---|---|
| **Encoder 1 (Leftmost)** | `GP7` | GND | `GP8` | Row 1, Col 0 (`1,0`) |
| **Encoder 2** | `GP9` | GND | `GP10` | Row 1, Col 1 (`1,1`) |
| **Encoder 3 (Center)** | `GP11` | GND | `GP12` | Row 1, Col 2 (`1,2`) |
| **Encoder 4** | `GP14` | GND | `GP15` | Row 1, Col 3 (`1,3`) |
| **Encoder 5 (Rightmost)**| `GP26`| GND | `GP27` | Row 1, Col 4 (`1,4`) |
