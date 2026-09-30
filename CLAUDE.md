# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A personal GitHub Pages site (kalmar.github.io) that serves Anton Romankov's CV, plus a `docs/` folder of personal practice code (LeetCode solutions, C++ examples). There is no build step, package manager, linter, or test suite — files are served as-is by GitHub Pages.

## Local preview

```bash
python3 -m http.server
```

Then open http://0.0.0.0:8000/. Pages fetch Markdown at runtime, so opening them via `file://` won't work.

## Architecture

- `summary.md` is the single source of truth for the resume content. Edit content there, never in HTML.
- `index.html` contains no content: on load it fetches `summary.md`, renders it with `marked` (jsDelivr CDN), then a small layout script reshapes the DOM. That script relies on these Markdown conventions in `summary.md`, so keep them:
  - `# Name`, then the tagline paragraph and the contacts paragraph (centered header); `---` is hidden.
  - `### Company · Title` immediately followed by `*Dates · Location*` becomes a two-row entry header (left/right aligned). The ` · ` separator is what splits left from right.
  - A paragraph that is entirely `*Stack: ...*` gets the small italic stack style.
  - The Technical Skills table has an empty header row, which is hidden.
- Printing (the "Save as PDF" button / Ctrl+P) produces the PDF; there's A4 print CSS in `index.html`. Preview the print output headlessly (needs a local server, see above):
  ```bash
  google-chrome --headless=new --no-pdf-header-footer --virtual-time-budget=8000 --print-to-pdf=/tmp/cv.pdf http://localhost:8000/
  ```
- Legacy, not linked from `index.html`: `cv.html` + `cv/*.md` (old detailed CV rendered via `<zero-md>`, styled by `index.css`) and `anton_romankov.cv.pdf` (old NovoResume export).

## docs/

Standalone scratch/practice files, not linked from the site:
- `docs/leetcode/*.py` — one LeetCode problem per file (named by problem slug), a `Solution` class followed by a top-level example call. Run with `python3 docs/leetcode/<file>.py`.
- `docs/cpp_by_examples/` — small single-file C++ demos; compile with e.g. `g++ -std=c++17 lambdas.cpp && ./a.out` (`a.out` is gitignored).
