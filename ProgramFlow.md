# TicTacToe Program Flow

## Program Structure

```text
main()
│
├── InitWindow() [Raylib - Initialize 400x400 window]
├── SetTargetFPS(120) [Raylib - Set frame rate to 120 FPS]
├── play() [Constructor - Initialize game in NORMAL mode]
│   └── ResetGame()
│       └── [Initialize board, player turn, winner, and tracking deques]
│
├── View(play) [Constructor - Create renderer with reference to game]
│
└── Main Game Loop [Runs until window is closed]
    │
    ├── Each Frame (120 FPS):
    │   │
    │   ├── play.Update()
    │   │   │
    │   │   ├── HandleInput()
    │   │   │   ├── [Check for SPACE key → ResetGame()]
    │   │   │   ├── [Check for T key → ToggleMode() → ResetGame()]
    │   │   │   │
    │   │   │   └── Dispatch to mode-specific handler:
    │   │   │       ├── HandleInputNormal()
    │   │   │       │   └── [Place symbol, switch turn]
    │   │   │       │
    │   │   │       ├── HandleInputForget()
    │   │   │       │   ├── [Check if MAX_SYMBOLS reached]
    │   │   │       │   ├── RemoveOldestSymbol() [If limit exceeded]
    │   │   │       │   │   ├── Get oldest from deque.front()
    │   │   │       │   │   ├── Clear board cell
    │   │   │       │   │   └── Remove from deque with pop_front()
    │   │   │       │   ├── [Place new symbol]
    │   │   │       │   ├── [Track position in deque]
    │   │   │       │   └── [Switch turn]
    │   │   │       │
    │   │   │       └── HandleInputRandom()
    │   │   │           ├── [Place new symbol first]
    │   │   │           ├── [Track position in deque]
    │   │   │           ├── [Check if exceeds MAX_SYMBOLS]
    │   │   │           ├── [If exceeded: select random index]
    │   │   │           ├── [Remove random symbol from board]
    │   │   │           ├── [Remove from deque at random index]
    │   │   │           └── [Switch turn]
    │   │   │
    │   │   └── CheckWinner() [If game not over]
    │   │       ├── [Check all 3 rows for 3-in-a-row]
    │   │       ├── [Check all 3 columns for 3-in-a-row]
    │   │       ├── [Check main diagonal for 3-in-a-row]
    │   │       ├── [Check anti-diagonal for 3-in-a-row]
    │   │       ├── IsBoardFull() [Check for draw]
    │   │       │   └── [Iterate through all 9 cells]
    │   │       └── [Set gameOver and winner accordingly]
    │   │
    │   ├── BeginDrawing() [Raylib]
    │   ├── ClearBackground(WHITE) [Raylib]
    │   │
    │   ├── view.Draw()
    │   │   ├── DrawBoard()
    │   │   │   └── [Draw grid lines and board background]
    │   │   ├── DrawSymbols()
    │   │   │   └── [Iterate board and draw X/O symbols]
    │   │   ├── DrawGameOver() [If game is over]
    │   │   │   └── [Display "X Wins", "O Wins", or "Draw"]
    │   │   └── [Display mode and controls text]
    │   │
    │   └── EndDrawing() [Raylib]
    │
    └── [Continue until WindowShouldClose() returns true]

└── CloseWindow() [Raylib - Clean up and exit]
```

## Key Game Flow Phases

### 1. **Initialization Phase**
- Window and Raylib are initialized
- `play` object created and board reset
- `View` object created with reference to game

### 2. **Main Game Loop (120 FPS)**
Each frame follows this sequence:
1. **Update Phase**: `play.Update()` processes input and checks win conditions
2. **Render Phase**: `view.Draw()` renders all game elements

### 3. **Input Processing**
- **Global Commands**: SPACE to reset, T to toggle mode
- **Mode-Based Input**: Handled by appropriate mode handler
- **Coordinate Conversion**: Mouse pixels → board grid indices

### 4. **Symbol Management by Mode**

#### NORMAL Mode
- Unlimited symbols per player
- No removal logic

#### FORGET Mode
- Maximum 3 symbols per player
- **Removal strategy**: FIFO (First-In-First-Out)
- Oldest symbol removed when 4th is placed
- Removal happens **BEFORE** placing new symbol

#### RANDOM Mode
- Maximum 3 symbols per player
- **Removal strategy**: Random symbol removed
- Removal happens **AFTER** placing new symbol
- All symbols have equal chance of removal

### 5. **Win/Draw Detection**
Checks in order:
1. All 3 rows
2. All 3 columns
3. Main diagonal (top-left to bottom-right)
4. Anti-diagonal (top-right to bottom-left)
5. Board full → Draw condition

### 6. **Rendering Phase**
Each frame displays:
- Game board (3x3 grid)
- Current symbols (X and O)
- Game-over message (if applicable)
- Current mode indicator
- Control instructions
