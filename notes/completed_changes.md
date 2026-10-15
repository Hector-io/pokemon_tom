# Current implementation

This is a record of project-level changes that are present in the source tree.
It is deliberately a status document, not a substitute for testing a new ROM
build.

## Game identity

- New games force the player name to **TOM** and the player gender to male.
  The original naming and gender-selection scenes still appear, but their
  choices are overwritten during new-game setup.
- The title screen reads **Pokémon TOMGUY Version**. The replacement graphic is
  functional, although its alignment and finish still need a polish pass.
- The starter choices are **Turtwig**, **Torchic**, and **Totodile**.

## World and encounter changes

- Wild encounter tables across the game have been overhauled using the
  encounter-planning workbook as a reference.
- Littleroot Town contains early evolution-item pickups, including Water,
  Shiny, Sun, Leaf, Moon, and Fire Stones, plus Razor Fang and Razor Claw.
- Hoenn fossil Pokémon have been replaced with **Archen** and **Tyrunt**.
- Rusturf Tunnel has a level 20 static **Dracovish** encounter. It plays a cry
  and reaction animation before battle. A defeated, fled-from, or otherwise
  uncaught Dracovish remains available for another attempt; catching it sets a
  dedicated flag and removes the overworld encounter permanently.

## Casino network

Ten custom casino interiors are connected to the following locations. They use
the game's shared coin balance, retain slot and roulette interactions, and
provide a coin vendor plus a region-specific prize vendor.

| Entrance location | Prize theme |
| --- | --- |
| Oldale Town | Kanto legendaries |
| Petalburg City | Johto legendaries |
| Rustboro City | Sinnoh legendaries |
| Slateport City | Unova legendaries |
| Dewford Town | Kalos legendaries |
| Verdanturf Town | Alola legendaries |
| Fallarbor Town | Galar legendaries |
| Fortree City | Paldea legendaries |
| Mossdeep City | Mythical Pokémon |
| Ever Grande City | Legendary transformation and fusion items |

Most entrances are in the back of a PokéMart. Dewford uses House 2, and the
Ever Grande entrance is beside the Elite Four entrance. The Ever Grande item
vendor uses a two-page menu for DNA Splicers, N-Solarizer, N-Lunarizer, Reveal
Glass, Gracidea, Rusted Sword and Shield, Reins of Unity, Prison Bottle, and
the Adamant, Lustrous, and Griseous Orbs.

## Visual work

- Steven's overworld sprite, trainer front sprite, trainer back sprite, and
  palette have been replaced with Hector-themed artwork.
- Drake's overworld artwork has been replaced with Jack-themed artwork.
- Editable/source versions of title, trainer, and overworld artwork are kept in
  [`assets_source/`](../assets_source/).

## Development settings

- The overworld and battle debug menus are enabled.
- HGSS-style overworld followers are enabled.
- TMs are reusable.

These settings are useful while developing. The debug menus are a release
checklist item and should be disabled before a public build is shared.
