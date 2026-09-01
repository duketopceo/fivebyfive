# Desktop Companion App (v2 Roadmap)

> **Status:** Deferred until physical v1 hardware and Vial layer workflows are validated.

## Architecture Blueprint (TilePad & Macro-Deck Reference)
- **Framework:** Tauri v2 + Rust
- **Frontend UI:** TypeScript + React / Tailwind CSS
- **Inter-Process Communication:** Local WebSocket / UNIX domain sockets
- **Native OS Bridges:**
  - **Linux / Omarchy:** Direct `hyprland` IPC via `/tmp/hypr/$HYPRLAND_INSTANCE_SIGNATURE/.socket2.sock`
  - **macOS:** Accessibility API & CoreGraphics keystroke synthesis
  - **Windows:** Win32 Raw Input API & virtual key dispatch
