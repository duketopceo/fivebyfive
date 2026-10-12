# Plan: fivebyfive → 10/10

**Date:** 2026-09-22 · **Status:** proposed · **Depth:** lightweight
**Origin:** repo scorecard pass — engineering rigor 7, docs 5.

## Problem frame

FiveByFive (5-key + 5-knob, RP2040, Vial-QMK) is the better-documented sibling: it has a
devcontainer with the QMK CLI + ARM GCC toolchain, `BUILD_GUIDE.md`, `FLASHING.md`, and
a `QA_CHECKLIST.md`. But nothing **verifies** any of it — the firmware may not compile
at HEAD, and the QA checklist is a manual doc that can drift from `config.h` / `vial.json`.

## Scope

**In:** firmware build CI via the devcontainer, config-consistency checks, docs sync,
profiles documentation.
**Out:** new keymaps/layers, hardware changes, changes to the Vial UID.

## Implementation units

### U1 — Firmware build CI
**Files:** `.github/workflows/firmware.yml` (new)
- Build the firmware in the existing devcontainer image on push + PR touching
  `firmware/`; fail the workflow on compile error.
**Test scenarios:** a PR that breaks `keymap.c` or `config.h` → workflow fails.

### U2 — Config consistency checks
**Files:** `scripts/check-config.py` (new) or extend `.github/workflows/firmware.yml`
- Automated cross-checks: encoder pins in `config.h` match `vial.json` encoder config;
  layer count in `keymap.c` matches `vial.json` layout; Vial UID unchanged.
**Test scenarios:** each check fails with a message naming the two files that disagree.

### U3 — Docs sync
**Files:** `docs/FLASHING.md`, `docs/BUILD_GUIDE.md` (verify/extend)
- Record the tested QMK commit/version the guide was validated against; re-validate on
  QMK bumps.
**Test scenarios:** n/a — review criterion: the flashing steps work verbatim at the
recorded QMK version.

### U4 — Profiles documentation
**Files:** `README.md` (extend)
- Document `profiles/` (`desk.json`, `omarchy_hyprland.json`, …): what each is for and
  how to load it via Vial.
**Test scenarios:** n/a.

## Key decisions

- CI builds **in the devcontainer** — the toolchain is already pinned there, so CI and
  local builds can't drift.
- Vial UID stays stable across builds (changing it orphans saved layouts).
- U1 before U2: a green build is the prerequisite for consistency checks to mean anything.

## Assumptions / open questions

- Relationship to `helm-qmk-macropad`: does fivebyfive supersede Helm, or are both
  maintained? Record the answer in both READMEs (same question, asked once).
