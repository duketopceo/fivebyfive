# Quality Assurance & Testing Checklist

## Hardware Verification
- [ ] Multimeter continuity check: No shorts between `VBUS/3V3` and `GND`.
- [ ] Diode polarity: All 10 diodes face `COL2ROW` (cathode to row).
- [ ] No ghosting: Pressing combinations of 3+ keys does not register false keypresses.

## Firmware & Rotary Encoder Testing
- [ ] **Encoder 1 (Leftmost):** CCW, CW, and push switch trigger expected actions without jitter.
- [ ] **Encoder 2:** Quadrature signals clean; no missed detents.
- [ ] **Encoder 3 (Center):** Quadrature signals clean; no missed detents.
- [ ] **Encoder 4:** Quadrature signals clean; no missed detents.
- [ ] **Encoder 5 (Rightmost):** Quadrature signals clean; no missed detents.
- [ ] **Simultaneous Turn:** Turning two encoders simultaneously produces independent, non-blocking HID events.

## Vial Integration Testing
- [ ] Keyboard connects over WebHID on `vial.rocks` / desktop Vial.
- [ ] Real-time key remapping persists after unplugging/replugging device.
- [ ] Encoder CCW and CW remapping works dynamically without reflashing.
- [ ] All 5 layers switch reliably.
