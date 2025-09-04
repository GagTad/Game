# 🎮 Tetris++

A C++ implementation of the classic **Tetris** game using the **Raylib** graphics library.

## 🧱 Features

- Classic Tetris gameplay
- Realistic movement and rotation
- Upcoming block preview
- Score system
- Level-up mechanism (based on score)
- Special **Bomb Block** that destroys nearby tiles
- Smooth user interface with custom pixel font

---

## 🎮 Controls

| Key        | Action                      |
|------------|-----------------------------|
| ⬅️ Left     | Move block left            |
| ➡️ Right    | Move block right           |
| ⬇️ Down     | Move block down            |
| ⬆️ Up       | Rotate block clockwise     |
| Spacebar   | **Drop block instantly** (optional addition) |
| Any key (when game over) | Restart game |

---

## 🧨 Bomb Block – Special Block

- **ID:** `8`
- **Appearance:** 3x3 block  with a unique black color.
- **Effect:** When locked, **destroys all tiles in a 4x4 area** around its position.
- Appears randomly like any other block.

---

## 🧮 Scoring

| Cleared Rows | Points |
|--------------|--------|
| 1 row        | 100    |
| 2 rows       | 300    |
| 3 rows       | 500    |
| Move Down    | +1     |

Level increases every `100` points (configurable), and can be used to increase speed or complexity (future idea).

---

## 📁 Project Structure

![Screenshot 2025-06-15 193239](https://github.com/user-attachments/assets/b912feb6-3e96-44ce-a602-97faaeccf846)

Tetris++
├── Tetris.cpp # Main game loop

├── Game.h / Game.cpp # Game logic and control

├── Block.h / Block.cpp # Base class for Tetris blocks

├── ChildBlocks.cpp # All 7 classic + Bomb block definitions

├── Grid.h / Grid.cpp # Grid matrix logic

├── Position.h # 2D Position class (row, col)

├── Colors.h # Cell color definitions

├── Font/

│ └── monogram.ttf # Retro pixel font


🔮 Future Ideas
Hold system (swap block)

Ghost piece

Line-clearing animations

Music and sound effects

Multiplayer or AI mode



![Screenshot 2025-06-15 203615](https://github.com/user-attachments/assets/223e3e7b-cfdf-45ad-aec4-0332c53de1b4)





