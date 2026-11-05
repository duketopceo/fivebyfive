# Brand assets (proposal)

Status: proposal written 2026-10-11. The owner signs off logos.

- `logo.svg` / `logo-dark.svg`: the mark, 64x52 units. Top row: five rounded squares (the keys). Bottom row: five open rings (the encoders), each with a short notch line pointing up. The middle notch is amber: that is the single "active" detail.
- `wordmark.svg` / `wordmark-dark.svg`: mark plus the name set in a monospace face with `by` in amber. Wordmark text is converted to outlines (set in Liberation Mono Bold), so it renders the same everywhere.
- Construction: 9-unit squares and 4.5-unit-radius rings on a 12-unit pitch, 3.5-unit margin. Square corner radius 2. Stroke 2.2. No gradients, no raster.
- Colours: ink `#1B1D20` on paper, `#E8E6E1` on night; accent `#8A4B00` (6.0:1 on paper) / `#FFB454` (10.1:1 on night). See `DESIGN.md`.
- Previews: `preview/*.png`, rendered with `resvg` and optimised with `oxipng`.
