Inherits from [luke-agents/AGENTS.md](https://github.com/duketopceo/luke-agents/blob/main/AGENTS.md). This file specializes; it does not replace.

# fivebyfive — 5 Keys + 5 Rotary Encoders Macropad (RP2040 + QMK/Vial)

## Project Overview
- **Hardware v1:** 5 Cherry-MX / Choc mechanical switches + 5 EC11 rotary encoders (with push buttons) driven by an RP2040 MCU (Raspberry Pi Pico or RP2040-Zero).
- **Firmware:** QMK with Vial support for on-the-fly cross-platform configuration (no custom daemon required).
- **Target OS:** Linux (Omarchy / Hyprland), macOS, and Windows.
- **Future v2:** Rust + Tauri v2 companion app (inspired by TilePad).

## Invariants & Rules
1. **Physical verification before software bloat:** Get 1 switch + 1 knob working in Vial first, then expand to 5 keys + 5 knobs.
2. **Standard QMK/Vial compatibility:** Ensure `vial.json` and encoder maps adhere strictly to upstream Vial specifications.
3. **Cross-platform first:** Encoder actions must operate via standard USB HID keycodes and consumer media controls.


## Code graph index (optional accelerator)

This repo may be indexed by `codebase-memory-mcp` (CBM) on an agent's local
machine — `.codebase-memory/` is gitignored. If your harness exposes CBM
tools (`search_graph`, `trace_path`, `get_architecture`, `detect_changes`),
prefer them for structural questions — symbol lookup, caller/callee traces,
impact analysis — instead of grep/read loops. Reindex after large refactors
(`index_repository`); treat `.codebase-memory/graph.db.zst` as a local cache
artifact, never commit it.
