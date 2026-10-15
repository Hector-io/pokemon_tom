# Pokémon TOMGUY Version

A personal Pokémon Emerald ROM hack made for Tom. It is built from the
[pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion)
decompilation project, currently based on expansion 1.15.0.

This repository contains the game's source code and development assets. It is
not an official Pokémon product and is not affiliated with Nintendo, Game
Freak, Creatures, or The Pokémon Company.

## Current project state

The game is an in-progress remix of Pokémon Emerald rather than a finished
release. The notable changes currently in the source are:

- The player is always **TOM** and male.
- The starter choices are **Turtwig**, **Torchic**, and **Totodile**.
- Wild encounters have been rebuilt with Pokémon from later generations.
- Rusturf Tunnel contains a level 20 static **Dracovish** encounter. It can be
  retried unless it is caught.
- A shared-coin casino network has been added across Hoenn, with regional
  legendary, Mythical, and special-item prize vendors.
- Steven's visual assets have been replaced with Hector's, and Drake's artwork
  has been replaced with Jack's.
- Followers and reusable TMs are enabled.

The overworld and battle debug menus are deliberately enabled while the game is
in development. Disable them before sharing a release build.

## Build

The build process and toolchain requirements are inherited from
`pokeemerald-expansion`. Follow the local [installation guide](INSTALL.md), then
run the following from the repository root:

```sh
make
```

The resulting ROM is `pokeemerald.gba`. Build products are intentionally
ignored by Git.

## Project guide

| Location | Purpose |
| --- | --- |
| [`assets_source/`](assets_source/) | Editable or reference art and candidate music sources. These files are not build inputs. |
| [`notes/`](notes/) | The current project plan, implemented-feature record, character plan, and encounter-planning sheet. |
| [`data/`](data/), [`graphics/`](graphics/), [`src/data/`](src/data/) | Maps, event scripts, graphics, encounters, trainers, and other game content. |
| [`sound/`](sound/) | Audio assets used by the game. |
| [`docs/`](docs/), [INSTALL.md](INSTALL.md), [FEATURES.md](FEATURES.md) | Upstream expansion documentation retained for engine reference. |

For the active project plan, start with the [notes index](notes/README.md):

- [Current implementation](notes/completed_changes.md)
- [Unfinished work](notes/todo.md)
- [Character, gym, and Elite Four plan](notes/character_plan.md)

## Credits and source material

This project uses `pokeemerald-expansion`; please retain the upstream credit in
[CREDITS.md](CREDITS.md). `assets_source/` includes third-party reference and
source material. Keep the original attribution with an asset and confirm that
it may be redistributed before using it in a public release.
