# fivebyfive design direction: Detent

Status: proposal, 2026-10-11. The owner signs off logos. This repo has no app UI; the "surfaces" are the README, the docs, the keymap/profile tables and the physical labelling.

## Direction
**Detent**: the click of an encoder between two positions. Matte graphite and warm paper, one amber accent that means "the one that is active". Quiet technical documentation, the feel of a printed key-legend sheet.

Research (local, no Refero MCP on this machine, so the fallback the skill allows): references were the Adafruit MacroPad and Stream Deck pages in `docs/research/`, and the existing family look of the owner's other repos. Reference lock: borrow the legend-sheet clarity (a labelled grid), reject Stream Deck's glossy LCD aesthetic and RGB-gamer styling.

Decision ledger: monospace for anything a machine reads (keycodes, pins); one accent used once per view; no gradients; keys are rounded squares, knobs are discs with a notch.

## Tokens
| Token | Light | Dark |
|---|---|---|
| paper / night | `#F3F1EC` | `#16181B` |
| ink | `#1B1D20` | `#E8E6E1` |
| muted | `#5A5D63` | `#A3A7AE` |
| accent (amber) | `#8A4B00` | `#FFB454` |

Contrast (WCAG, computed): ink on paper 14.96:1, muted on paper 5.85:1, accent on paper 6.03:1; ink on night 14.26:1, muted on night 7.37:1, accent on night 10.09:1. All pass AA for body text.

Type: JetBrains Mono (labels, keycodes, pins), system sans for prose.

## Glyphs and motion
Glyphs: squares (keys), notched discs (knobs), 2.2 px stroke weight, 2-unit corner radius. No motion: docs and firmware only. If a companion app arrives, a knob "tick" of 80 ms is the only animation.

## Surfaces
README (logo, layer table), `docs/` (legend tables with amber for the active layer), `hardware/` pinout tables, printed key legends (use the mark glyphs).

## Assets
`assets/brand/` (logo, dark logo, wordmark, previews, construction notes).
