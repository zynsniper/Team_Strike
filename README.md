# ⚔ TeamStrike

**TeamStrike** is a turn-based, command-line strategy game written in C, developed as part of a Systems Software Development University course. Players take control of a team of randomized characters and battle against AI opponents on a procedurally generated map, featuring character abilities and simple combat.

---

##  About the Project

Developed by a two-member team for the **CS2263: Systems Software Development** course, this project demonstrates core systems-level programming concepts including memory management, file I/O, structures, and dynamic allocation in C.

---

##  Features

-  **Randomized Map Generation**: Each game generates a unique map with the palace (`P`) always in the center.
-  **Randomized Character Stats**: Every character (player or AI) gets random HP and AD values per playthrough.
-  **Simple AI Logic**: AI units move toward the nearest player or palace, with specialized roles:
  - `X`: High Attack Damage
  - `D`: High Hit Points
-  **Player Abilities**:
  - **Berserker**: Double damage below 50% HP.
  - **Bulldozer**: Destroy obstacles (`O`) while moving.
-  **Save Game Functionality**: Game state can be saved into a `.txt` file capturing:
  - Team names
  - Character stats
  - Map and character positions
-  **Minimal Input Requirements**:
  - Choose a team name
  - Use `<WASD>` keys to move
  - Use `1–4` to select a character
  - Move into enemy tiles to attack

---
## ⚠️ Known Limitations
Partial implementation of the load system (missing character stat recovery)

Some intended features (e.g., advanced AI or linked lists) were not fully realized due to scope and time constraints

## 🧪 Debugging & Testing
Memory management tested with Valgrind

GitHub branches used to isolate and fix bugs (e.g., character death not updating map)

Extensive terminal-based testing
