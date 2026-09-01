# Wiring Diagram & Hand-Wire Guide

```text
               [ USB-C / Controller (RP2040) ]
                            │
   Row 0 (GP0) ───[|>|]─ K1 ─[|>|]─ K2 ─[|>|]─ K3 ─[|>|]─ K4 ─[|>|]─ K5
                            │        │        │        │        │
   Row 1 (GP1) ───[|>|]─ E1 ─[|>|]─ E2 ─[|>|]─ E3 ─[|>|]─ E4 ─[|>|]─ E5 (Push Switches)
                            │        │        │        │        │
      Columns:             GP2      GP3      GP4      GP5      GP6

   -------------------------------------------------------------------------
   Rotary Encoders Quadrature Connections:
   E1: Pin A -> GP7  | Common -> GND | Pin B -> GP8
   E2: Pin A -> GP9  | Common -> GND | Pin B -> GP10
   E3: Pin A -> GP11 | Common -> GND | Pin B -> GP12
   E4: Pin A -> GP14 | Common -> GND | Pin B -> GP15
   E5: Pin A -> GP26 | Common -> GND | Pin B -> GP27
```

### Important Steps:
1. **Diode Direction (`COL2ROW`):**
   - Solder the **Anode** (non-band side) to the switch pin.
   - Solder the **Cathode** (black line band) to the Row wire.
2. **Common Ground for Encoders:**
   - Connect the center pin of all 5 encoders to a common ground bus wired to RP2040 `GND`.
