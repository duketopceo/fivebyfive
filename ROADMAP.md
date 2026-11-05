# Roadmap

Program roadmap, 2026-10-11. Extends the open plan in
[`docs/plans/2026-09-22-001-fivebyfive-firmware-ci-plan.md`](docs/plans/2026-09-22-001-fivebyfive-firmware-ci-plan.md)
(units U1-U4 there keep their IDs). No hardware flashing is part of this pass.

Nothing here has been compiled: this machine has no QMK CLI or ARM GCC, so every firmware claim below is from reading the source.

## Now

### P1 - Fix keycodes that cannot compile (status: found, not fixed)
Evidence: `firmware/keymaps/vial/keymap.c` uses bare `F8` (Code layer, encoder row) and `F9` (Creator layer); QMK keycodes are `KC_F8` / `KC_F9`.
- **Difficulty:** easy. Two-token edit.
- **Feasibility:** none blocking; confirm with a real `qmk compile` (needs the devcontainer).
- **Simpler alternative:** none; it is already the minimal change.
- **Verification:** `qmk compile -kb fivebyfive -km vial` exits 0.

### P2 - Put `vial.json` where Vial looks for it (status: found, not fixed)
Evidence: `vial.json` sits in `firmware/`, but Vial's porting docs and community guides place it in the keymap folder (`keymaps/vial/`) next to `config.h` with `VIAL_KEYBOARD_UID`. Here the UID and unlock combo are in the keyboard-level `config.h`. See research doc for sources.
- **Difficulty:** easy to move, medium to prove (needs a build and the Vial GUI loading the definition, which needs a board or at least the web app with a sideload).
- **Feasibility:** upstream vial-qmk layout rules; changing the UID is forbidden by the plan (orphans saved layouts), so move the file, never the UID.
- **Simpler alternative:** keep one `vial.json` and delete the duplicate layout description in `info.json` only if QMK still needs it for `LAYOUT`; check before deleting.

### U1 / U2 (existing plan) - Firmware CI and config consistency checks
- **Difficulty:** medium. The devcontainer pins the toolchain; the work is the workflow plus a small script.
- **Feasibility:** public repo, so hosted Actions run. First green build depends on P1 and P2.
- **Simpler alternative:** drop `scripts/check-config.py` at first and rely on the compile for pin and layer mismatches; add the script only for the UID-unchanged check.

## Next

### P3 - Resolve fivebyfive vs Helm (open question from the plan)
Both READMEs should say whether the 5-key/5-knob board supersedes the 6-key/1-knob Helm or both live on.
- **Difficulty:** easy (a decision plus two sentences). **Feasibility:** owner decision only.
- **Simpler alternative:** one line in each README pointing at the other.

### U3 / U4 (existing plan) - Docs sync and profiles docs
- **Difficulty:** easy. **Feasibility:** U3 needs a real build at a recorded QMK commit.
- **Simpler alternative:** `profiles/*.json` duplicate what `keymap.c` already encodes; documenting them as "reference, not loaded by Vial" is cheaper than keeping two sources in sync. Consider generating them from `keymap.c` or deleting them.

### P4 - Single-switch bring-up record
`docs/BUILD_GUIDE.md` Stage 1 (one switch, one encoder) has no recorded result. Add a dated bring-up log to `docs/QA_CHECKLIST.md`.
- **Difficulty:** medium (needs the physical board). **Feasibility:** hardware on hand; flashing is the owner's step.

## Later

### P5 - Companion app (`desktop/`)
Currently a README-only blueprint (Tauri/Rust, modelled on TilePad).
- **Difficulty:** hard. **Feasibility:** Vial already covers remapping; a daemon is only needed for layer-aware OS actions.
- **Simpler alternative:** delete `desktop/` until a feature exists that Vial cannot do. Raw HID layer-change notifications are the likely first reason to build it.
