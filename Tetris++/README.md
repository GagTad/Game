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
- **Appearance:** 2x2 block (like OBlock) with a unique dark color.
- **Effect:** When locked, **destroys all tiles in a 3x3 area** around its position.
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

Game saving

🎨 Screenshot
![image](https://github.com/user-attachments/assets/642db757-8c41-470d-b28a-c94e36db254a)




