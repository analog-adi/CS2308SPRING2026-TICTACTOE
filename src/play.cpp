#include "../include/play.h"
#include "raylib.h"
#include <cstdlib>  //TODO: Explain--> Header for rand() function used in RANDOM mode for randomization

// TODO: Explain--> to set inital game mode and initialize board state
Play::Play() : mode(NORMAL) {
    ResetGame();  // TODO: Explain--> Initialize all game state: board, players, flags, and tracking deques
}

// TODO: Explain--> Clear all game state and prepare for fresh game
void Play::ResetGame() {
    // TODO: Explain below--> A nested loop for two-dimensional array to iterate all 9 cells (3x3 board)
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;  // TODO: Explain--> Initialize each cell to empty (0 = no symbol)
        }
    }

    playerXTurn = true;     // TODO: Explain--> X player always goes first
    gameOver = false;       // TODO: Explain--> Game is now active and ready to play
    winner = 0;             // TODO: Explain--> No winner yet: 1 for X, 2 for O, 3 for draw and 0 for ongoing game

    xPositions.clear();     // TODO: Explain--> Clear X player Moves history deque for FORGET/RANDOM modes
    oPositions.clear();     // TODO: Explain--> Clear O player Moves history deque for FORGET/RANDOM modes
}

// TODO: Explain--> Main game loop - process input and check for game end every frame
void Play::Update() {
    HandleInput();          // TODO: Explain--> Process mouse clicks and keyboard input for current game

    // TODO: Explain--> Only check for winner if game is still active (not over)
    if (!gameOver) {
        CheckWinner();      // TODO: Explain--> Scan board for win conditions (3-in-a-row) or draw (full board)
    }
}

// TODO: Implement logic to remove the oldest symbol from the board and tracking deque.
void Play::RemoveOldestSymbol(bool isX) {
    // In FORGET mode, players can only keep MAX_SYMBOLS on the board.
    // When a new symbol is placed and the limit is exceeded, you must remove the **oldest** placed symbol.
    //
    // Hints:
    // - Use the player's position queue (xPositions or oPositions) to track the order of placements.
    // - The oldest move is at the **front** of the deque.
    // - Remove it from the board and from the queue.
    //
    // 👉 Try to write this logic on your own based on how other parts of the code use these queues.
}

// TODO: Explain--> Route input to special commands (reset, mode toggle) or active game mode handler
void Play::HandleInput() {
    // TODO: Explain--> Check if SPACE key pressed to restart game
    if (IsKeyPressed(KEY_SPACE)) {
        ResetGame();  // TODO: Explain--> Reset all game state for fresh game
        return;
    }

    // TODO: Explain--> Check if T key pressed to switch game mode
    if (IsKeyPressed(KEY_T)) {
        ToggleMode();  // TODO: Explain--> Cycle through modes: NORMAL → FORGET → RANDOM → NORMAL
        return;
    }

    // TODO: Explain below--> Dispatch to appropriate input handler based on current active mode
    if (IsNormalMode()) {
        HandleInputNormal();
    } else if (IsForgetMode()) {
        HandleInputForget();
    } else if (IsRandomMode()) {
        HandleInputRandom();
    }
}

// TODO: Explain--> Handle input for NORMAL mode: players can place symbols without limits, no removals
void Play::HandleInputNormal() {
    // TODO: Explain--> Only allow input if game is not over and mouse left button is pressed
    if (!gameOver && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();  // TODO: Explain--> Get current mouse position in pixel coordinates (x,y) relative to window

        // TODO: Explain below--> Convert pixel coordinates to board grid indices using Padding and cell_size
        int row = (mousePos.y - 50) / 100;
        int col = (mousePos.x - 50) / 100;

        // TODO: Explain below--> to validate the click: must be within board bounds AND cell must be empty (0) to allow placement
        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == 0) {
            board[row][col] = playerXTurn ? 1 : 2;  // TODO: Explain--> Place 1 for X and 2 for O
            playerXTurn = !playerXTurn;             // TODO: Explain--> Switch to other player's turn after successful placement
        }
    }
}

// TODO: Implement FORGET mode logic: each player limited to 3 symbol, oldest automatically removed when 4th place
void Play::HandleInputForget() {
    // In this mode, each player can have at most MAX_SYMBOLS on the board.
    // If a player tries to place a symbol after reaching this limit, the oldest one should be removed.
    // Steps:
    // 1. Get the mouse click and convert it to board coordinates.
    // 2. If the clicked cell is empty and valid, place the symbol.
    // 3. Check if the player's queue (xPositions or oPositions) already has MAX_SYMBOLS.
    //    If so, remove the oldest symbol using RemoveOldestSymbol().
    // 4. Add the new position to the player's queue.
    // 5. Switch the turn to the other player.
    // 👉 For now, we call the NORMAL mode handler as a placeholder.
    // ❌ Remove the line below once you've implemented the logic above.
    HandleInputNormal(); // TODO: Remove this line once FORGET logic is implemented
}


// TODO: Implement RANDOM mode logic:
void Play::HandleInputRandom() {
    // In this mode, each player can still have at most MAX_SYMBOLS.
    // However, instead of removing the oldest symbol, you should remove a **random** one if the limit is exceeded.
    // Steps:
    // 1. Get the mouse click and convert it to board coordinates.
    // 2. If the clicked cell is valid and empty, place the symbol.
    // 3. Add the new position to the correct queue (xPositions or oPositions).
    // 4. If the queue size exceeds MAX_SYMBOLS, randomly pick one symbol and remove it.
    // 5. Switch to the other player.
    // 👉 For now, we call the NORMAL mode handler as a placeholder.
    // ❌ Remove the line below once you've implemented the logic above.
    HandleInputNormal(); // TODO: Remove this line once RANDOM logic is implemented
}


// TODO: Explain--> Check all winning conditions and draw condition
void Play::CheckWinner() {
    // TODO: Explain below--> Check each row: if 3 cells match and not empty, player wins
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != 0 &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            gameOver = true;
            winner = board[i][0];
            return;
        }
    }

    // TODO: Explain below--> Check each column: if 3 cells match and not empty, player wins
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] != 0 &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i]) {
            gameOver = true;
            winner = board[0][i];
            return;
        }
    }

    // TODO: Explain--> Check main diagonal
    if (board[0][0] != 0 &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        gameOver = true;
        winner = board[0][0];
        return;
    }

    // TODO: Explain--> Check anti-diagonal
    if (board[0][2] != 0 &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        gameOver = true;
        winner = board[0][2];
        return;
    }

    // TODO: Explain--> If no winner and board is full, it's a draw
    if (IsBoardFull()) {
        gameOver = true;
        winner = 3;
    }
}

// TODO: Explain--> Check if all cells on the board are filled (no empty spaces) to determine draw condition
bool Play::IsBoardFull() {
    // TODO: Explain below--> iterate through all 9 cells of the board to check for any empty cell (0). If found, board is not full.
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) return false;
        }
    }
    return true;
}
