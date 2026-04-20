# 🎮 TicTacToe with Raylib (C++)

This project is a modern and visually polished implementation of the classic TicTacToe game built using the [Raylib](https://www.raylib.com/) C++ game framework.

---
## 📁 Project Structure
```text
TicTacToe/
├── CMakeLists.txt         # CMake build configuration
├── main.cpp               # Main entry point
├── run.sh                 # Shell script to run the game
├── include/               # Header files
│   ├── play.h
│   └── view.h
├── src/                   # Source files
│   ├── play.cpp
│   └── view.cpp
├── build/                 # (Usually build artifacts, can be ignored)
├── cmake-build-debug/     # (CMake build directory, can be ignored)
└── .idea/                 # (IDE config, can be ignored)
```
---

## ⚙️ What is Raylib?
Raylib is a simple and easy-to-use C/C++ library to learn game programming. It supports:
- 2D shapes and text rendering
- Keyboard and mouse input
- Easy setup with CMake and cross-platform builds

In this project, Raylib is used to:
- Render a 3x3 game board
- Display "X" and "O" symbols with stylized colors
- Handle mouse and keyboard input
- Show win/draw screens with overlays

---

## 🎮 Game Features
- **Normal Mode**: Classic TicTacToe rules
- **Forget Mode**: Each player can have only 3 symbols; oldest one disappears
- **Random Mode**: Exceeding symbol limit removes a random older symbol
- **UI Controls**:
  - `Mouse Click`: Place X or O
  - `T`: Toggle between game modes
  - `SPACE`: Reset the game
---

## 🛠️ Build & Run

### Prerequisites
- CMake ≥ 3.24
- C++ compiler with C++17 support
- Internet access (for automatic Raylib download via CMake)

### Build Instructions
```bash
mkdir build
cd build
cmake ..
make
./TicTacToe
````

Or use the quick script:

```bash
./run.sh
```

### ✅ Build & Run in CLion (JetBrains)
1. Open **CLion**.
2. Choose `File > Open...` and select the **project root folder** (`TicTacToe/`).
3. Locate and right-click on `CMakeLists.txt` in the project tree.
4. Select **Reload CMake Project**.
5. Click the **Build** or **Run** button in CLion's toolbar.

> CLion will automatically fetch Raylib (via CMake) and handle build setup.
---

## 📌 Credits

* Developed using [Raylib](https://www.raylib.com/)
* Clean structure with `Play` for game logic and `View` for rendering

Enjoy building and playing!