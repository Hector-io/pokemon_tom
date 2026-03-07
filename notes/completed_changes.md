

# TomGuy Version – Development Log

This file records **major completed changes and design decisions** for the Pokémon Emerald “TomGuy Version” project.  
Git commits track technical changes, but this document captures the **feature-level overview** of what has been implemented.

---

# Core Game Changes

## Player Configuration
- Player name is **forced to "Tom"**
- Player gender is **forced to male**
- The gender selection and naming screens still appear, but they do not affect the final player data.

Purpose:
- Ensures the player character is always consistent with the intended story experience.

---

# Title Screen

Title screen text changed from:

```
POKEMON EMERALD VERSION
```

to:

```
POKEMON TOMGUY VERSION
```

Current status:
- Functional
- Needs visual polish (alignment / graphic cleanup of the “TomGuy” text)

Future improvement:
- Tidy the font placement and spacing.

---

# Starter Pokémon Changes

Original Emerald starters replaced with:

| Original | New Starter |
|----------|-------------|
| Treecko  | Grookey     |
| Torchic  | Fuecoco     |
| Mudkip   | Totodile    |

Goal:
- Introduce more modern starters
- Create a fresh early-game experience.

---

# Wild Encounter Overhaul

All wild encounters across the entire game have been redesigned.

Details:
- Encounter tables were rebuilt in an **external Excel sheet**
- Pokémon from multiple generations have been introduced
- Routes were rebalanced to better suit the new starter lineup

Purpose:
- Make exploration feel completely new
- Prevent players from relying on standard Emerald encounter knowledge.

---

# Casino System (Major Feature)

A custom **multi-location casino system** has been implemented throughout Hoenn.

Core mechanics:
- Global shared **coin currency**
- Coin purchase NPCs
- Regional legendary prize vendors
- Item prize vendor
- Custom casino interior maps

---

## Coin Vendor

Players can purchase casino coins which are shared across all casino locations.

This allows:
- Any casino location to use the same currency
- Prize vendors to remain synchronized.

---

## Legendary Prize Vendors

Each casino location is planned to offer different legendary groups based on Pokémon regions.

Example regional layout:

| Region | Legendary Set |
|--------|---------------|
| Kanto  | Articuno, Zapdos, Moltres, Mewtwo |
| Johto  | Raikou, Entei, Suicune, Lugia, Ho‑Oh |
| Sinnoh | Lake Trio + Creation Trio |
| Unova  | Swords of Justice + Tao Trio |
| Kalos  | Xerneas, Yveltal, Zygarde |
| Alola  | Tapu Quartet + Solgaleo / Lunala / Necrozma |
| Galar  | Zacian, Zamazenta, Eternatus, Kubfu, Urshifu, Calyrex |
| Paldea | Koraidon, Miraidon + Treasures of Ruin |

---

## Mythical Prize Vendor

Separate vendor offering Mythical Pokémon such as:

- Mew
- Celebi
- Jirachi
- Deoxys
- Arceus

---

## Item Prize Vendor

Special items used for legendary transformations and fusions are available via casino prizes.

Items include:

- DNA Splicers
- N‑Solarizer
- N‑Lunarizer
- Reveal Glass
- Gracidea
- Rusted Sword
- Rusted Shield
- Reins of Unity
- Prison Bottle
- Adamant Orb
- Lustrous Orb
- Griseous Orb

Because of GBA menu limitations, this vendor uses a **two‑page menu system**.

---

# Custom Casino Maps

Custom casino interior maps were created for use across the region.

Design goal:
- Each PokéMart will contain a **hidden door in the back** leading to a casino interior.

Each casino contains:
- Coin vendor
- Legendary prize vendor
- NPCs
- Decorations
- Regional theme depending on location.

---

# Work Completed So Far

Major systems implemented and tested:

- Player character restriction system
- Title screen modification
- Starter Pokémon replacement
- Full wild encounter overhaul
- Casino map creation
- Casino NPC scripting
- Coin purchasing system
- Legendary prize system
- Item prize vendor
- Multi‑page menu workaround for GBA UI limitations


All systems compile and function correctly in-game.

---

# Casino Warp Integration

All casino entrances have now been connected to the overworld via warp events.

Entrances are located in the following towns:

| Location | Entrance Type |
|----------|---------------|
| Oldale | PokéMart back room doorway |
| Petalburg | PokéMart back room doorway |
| Rustboro | PokéMart back room doorway |
| Slateport | PokéMart back room doorway |
| Dewford | **House 2** – broken hole in the wall leading to the casino |
| Verdanturf | PokéMart back room doorway |
| Fallarbor | PokéMart back room doorway |
| Fortree | PokéMart back room doorway |
| Mossdeep | PokéMart back room doorway |
| Evergrande | New door placed next to the **Elite Four entrance** |

Design notes:
- Most towns access the casino through a hidden doorway in the back of the PokéMart.
- Dewford does not have a PokéMart, so the entrance was implemented as a **broken wall opening in House 2**.
- Evergrande's casino entrance is located beside the **Elite Four entrance**, providing a late‑game location for the final casino.

All entrances include:
- Warp from the town location → casino interior
- Warp from the casino interior → original location

---

# Next Planned Tasks

## Casino Integration
- Add door tiles to the back of all PokéMarts
- Create warp connections between PokéMarts and casinos

## Title Screen Polish
- Clean up the “TomGuy” title text

## Possible Future Improvements
- Unique casino decorations per location
- Additional NPC dialogue
- Casino ambience / slot machines