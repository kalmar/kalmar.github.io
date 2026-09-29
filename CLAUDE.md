# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A personal GitHub Pages site (kalmar.github.io) that serves Anton Romankov's CV, plus a `docs/` folder of personal practice code (LeetCode solutions, C++ examples). There is no build step, package manager, linter, or test suite — files are served as-is by GitHub Pages.

## Local preview

```bash
python3 -m http.server
```

Then open http://0.0.0.0:8000/. (`cv.html` fetches Markdown at runtime, so it won't work over `file://`.)

## Architecture

- `index.html` is the main resume: a self-contained, single-column, one-page A4 resume (in the style of sweresume.app / "Jake's Resume") with content and styles inline. Edit content directly in the HTML. It must stay one page when printed — check with:
  ```bash
  google-chrome --headless=new --no-pdf-header-footer --virtual-time-budget=5000 --print-to-pdf=/tmp/cv.pdf "file://$PWD/index.html" && pdfinfo /tmp/cv.pdf | grep Pages
  ```
- `cv.html` is the older compact view that renders `cv/*.md` (personal + experience) client-side via the `<zero-md>` web component, styled by `index.css`. The `cv/*.md` files are the old, more detailed CV (with references) and are no longer used by `index.html`.
- `anton_romankov.cv.pdf` is the downloadable CV linked from `index.html`. It is a static file and is not generated automatically — regenerate it from `index.html` with the command above if content changes.

## docs/

Standalone scratch/practice files, not linked from the site:
- `docs/leetcode/*.py` — one LeetCode problem per file (named by problem slug), a `Solution` class followed by a top-level example call. Run with `python3 docs/leetcode/<file>.py`.
- `docs/cpp_by_examples/` — small single-file C++ demos; compile with e.g. `g++ -std=c++17 lambdas.cpp && ./a.out` (`a.out` is gitignored).
