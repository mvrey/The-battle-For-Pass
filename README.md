# The Battle for Pass

An isometric-inspired 2D RPG prototype created as a final project for ESAT's *Programación Avanzada* course (2015). Command a custom-built hero, clear six handcrafted Tiled maps, and reclaim the village of Pass from the Black Dragon and its minions.

![Intro screen](assets/background/intro_background.png)

---

# Compilation and Dependencies

This project depends on the MOMOS2D graphics engine, whose code can be downloaded from https://github.com/mvrey/MOMOS2D. The library located at https://github.com/mvrey/MOMOS2D/blob/2025/build/windows/debug/Momos2D.lib must be included.

For operating systems other than Windows x64, or for release builds, the engine code must be compiled manually.

---

## Overview

The Battle for Pass is a single-player RPG built with modern C++ (C++11) and the ESAT graphics/input toolkit. All content is self-contained and data-driven: levels, sprites, and battle backgrounds are imported from Tiled `.tmx` maps and sprite sheets under the `assets/` directory. The project ships with:

- Six sequential maps (village → boss hall) connected via portals.
- Smooth tile-to-tile movement with persistent player state per map.
- Nine handcrafted enemy archetypes plus the Black Dragon boss.
- A fully animated player character creator (4 races × 4 jobs) with unique stats, spells, and bust art.

---

## Feature Highlights

**Gameplay**
- Seamless world traversal with automatic loading screens while each map streams its tiles, portals, NPCs, and enemy placements.
- Tactical, turn-based combat featuring melee attacks, class-bound spells (Heal, Fire Sword, Blizzard), potion usage, and a flee system with probabilistic outcomes.
- Merchants and storytellers sprinkled across maps; press `B` near a vendor to purchase healing potions with in-game gold.
- Rest mechanic (`R`) that either fully restores HP/MP or spawns a surprise encounter, with increased risk under Hard Mode.
- Hard Mode toggle in the New Game screen that doubles enemy spawns during map loading and buffs foes just before battle resolution—ideal for showdowns once you master the base difficulty.

**Technical**
- Data-driven TMX importer that reads multiple tilesets per map, extracts sprite layers, and stores them as reusable `TileImage` matrices for fast draw calls.
- Custom `Grid` data structure (bidirectional linked nodes of `void*`) that tracks collisions, NPCs, enemies, and portals independently for each map.
- `Manager` singleton marshals screen transitions, keeps an array of preloaded maps, and persists player/map pointers between screens.
- Battle scenes automatically inherit themed backgrounds per map (`assets/background/battle_*.png`), giving each region its own ambience.
- Modular folder layout (`Character`, `Enemy`, `Item`, `Screen`, `Main`, `Spell`) mirrored between `include/` and `src/` for straightforward navigation and extension.

---

## Visual Tour

| Character Creator | Overworld HUD | Battle Scene |
| --- | --- | --- |
| ![Character creator](assets/background/main_background.png) | ![Stats overlay](assets/raw/stats.png) | ![Battle background](assets/background/battle_village.png) |

<sub>All art is provided in `assets/` with PSD sources (`assets/background/intro.psd`, `assets/raw/stats.psd`, etc.) for further iteration.</sub>

---

## Controls & Shortcuts

| Context | Input | Action |
| --- | --- | --- |
| Menus | Mouse | Click buttons / faces to configure your hero |
| Menus | Keyboard | Type to name your hero; `Delete` removes last character |
| Game | Arrow Keys | Move one tile (smoothly animated) |
| Game | `S` | Toggle stats overlay |
| Game | `R` | Rest (chance-based heal or ambush) |
| Game | `B` | Trade with merchant on adjacent tile |
| Game | `ESC` | Return to main menu |
| Battle | `Attack` button | Perform melee exchange |
| Battle | `S` / `Cast Spell` | Open spell palette and cast |
| Battle | `Use Potion` | Consume healing potion (no enemy counterattack) |
| Battle | `Flee` | Attempt escape (70% success) |

---

## Architecture at a Glance

```
assets/      # Visuals, maps, fonts, PSD sources, sprites, battle backdrops
docs/        # Monograph, PDF/Docx design brief, Doxygen output, mockups
include/     # C++ headers grouped by subsystem (Character, Main, Screen, etc.)
src/         # Matching implementation files
lib/         # TMX parser (tinyxml2-based) + compiled grid.lib
nbproject/   # NetBeans project files / generated makefiles
compile.bat  # Windows build script using MSVC + ESAT libraries
```

- **Character System**: `Character/`, `Race`, and `Job` combine to generate stats/spells at runtime. Neutral NPCs derive from `Friend`, while enemies inherit from `Foe`.
- **Screens**: Each game state (Intro, MainMenu, NewGame, Game, Battle, GameOver, GameWon) inherits from `Screen` and plugs into the central `Manager`.
- **Map Loading**: `Map::LoadFromFile` parses TMX layers (`Collisions`, `Enemies`, `Portals`, `NPCs`), caches tiles as sprites, and links portals directly to other `Map` instances for instant transitions.
- **Difficulty Hooks**: The Hard Mode flag propagates through `Manager` into `Map::LoadFromFile` (extra enemy placements) and `Battle` (enemy hardening), ensuring a single toggle amplifies the entire loop.

---

## Build & Run

### Windows (MSVC + ESAT)
1. Install the MOMOS2D locally and keep the folder beside the project as expected by `compile.bat`.
2. Open a *Developer Command Prompt for VS* so `cl` is on PATH.
3. From the repository root, run:
   ```bat
   compile.bat
   ```
   The script compiles the TMX parser sources, every game subsystem, and links against `MOMOS2D.lib`, `opengl32`, `user32`, `gdi32`, and `shell32`.
4. Launch `TheBattleForPass.exe` (output in the root). Window size defaults to 1366×768 (`include/config.h`).

Tips:
- Adjust window size or map count for debugging by editing `include/config.h` (`kWindowWidth`, `kWindowHeight`, `kNumMaps`, `kStartingMap`).
- If your ESAT install lives elsewhere, update the `-I ../../../ESAT_rev109/include` and library paths inside `compile.bat`.

### Linux / macOS (gcc/clang)
- The codebase was validated on macOS 10.9 with `g++`. Use the generated NetBeans makefiles:
  ```bash
  make CONF=Debug
  ```
- Provide replacements for `MOMOS2D` input/draw headers by compiling the engine from source https://github.com/mvrey/MOMOS2D

### Using NetBeans
- Open the `nbproject/` folder via NetBeans C/C++ Pack.
- Choose the desired configuration (Debug/Release) and build/run from the IDE, which invokes the same make targets described above.

---

## Documentation

- `docs/Monograph.pdf` & `docs/Monograph.docx`: Original project report detailing design goals, data structures, and gameplay manual.
- `docs/doxygen/index.html`: Generated API reference for every class, ideal for onboarding contributors.
- `docs/TODO`: Historical backlog of planned systems (save/load, multi-enemy combat, inventory expansion) that can inspire future milestones.

---

## Live Demo

Watch a gameplay slice on YouTube: [https://www.youtube.com/watch?v=DoxPsefKvhk](https://www.youtube.com/watch?v=DoxPsefKvhk)
