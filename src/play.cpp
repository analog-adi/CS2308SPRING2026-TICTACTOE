#include "../include/play.h"
#include "raylib.h"
#include <cstdlib> // TODO: Explain?

// TODO: Explain?
Play::Play() : mode(NORMAL) {
    ResetGame();  // TODO: Explain?
}

// TODO: Explain?
void Play::ResetGame() {
    // TODO: Explain below
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;  // TODO: Explain?
        }
    }

    playerXTurn = true;     // TODO: Explain?
    gameOver = false;       // TODO: Explain?
    winner = 0;             // TODO: Explain?

    xPositions.clear();     // TODO: Explain?
    oPositions.clear();     // TODO: Explain?
}

// TODO: Explain?
void Play::Update() {
    HandleInput();          // TODO: Explain?

    // TODO: Explain?
    if (!gameOver) {
        CheckWinner();      // TODO: Explain?
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

// TODO: Explain?
void Play::HandleInput() {
    // TODO: Explain?
    if (IsKeyPressed(KEY_SPACE)) {
        ResetGame();  // TODO: Explain?
        return;
    }

    // TODO: Explain?
    if (IsKeyPressed(KEY_T)) {
        ToggleMode();  // TODO: Explain?
        return;
    }

    // TODO: Explain below
    if (IsNormalMode()) {
        HandleInputNormal();
    } else if (IsForgetMode()) {
        HandleInputForget();
    } else if (IsRandomMode()) {
        HandleInputRandom();
    }
}

// TODO: Explain?
void Play::HandleInputNormal() {
    // TODO: Explain?
    if (!gameOver && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();  // TODO: Explain?

        // TODO: Explain below
        int row = (mousePos.y - 50) / 100;
        int col = (mousePos.x - 50) / 100;

        // TODO: Explain below
        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == 0) {
            board[row][col] = playerXTurn ? 1 : 2;  // TODO: Explain?
            playerXTurn = !playerXTurn;             // TODO: Explain?
        }
    }
}

// TODO: Implement FORGET mode logic:
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


// TODO: Explain?
void Play::CheckWinner() {
    // TODO: Explain below
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != 0 &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            gameOver = true;
            winner = board[i][0];
            return;
        }
    }

    // TODO: Explain below
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] != 0 &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i]) {
            gameOver = true;
            winner = board[0][i];
            return;
        }
    }

    // TODO: Explain?
    if (board[0][0] != 0 &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        gameOver = true;
        winner = board[0][0];
        return;
    }

    // TODO: Explain?
    if (board[0][2] != 0 &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        gameOver = true;
        winner = board[0][2];
        return;
    }

    // TODO: Explain?
    if (IsBoardFull()) {
        gameOver = true;
        winner = 3;
    }
}

// TODO: Explain?
bool Play::IsBoardFull() {
    // TODO: Explain below
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) return false;
        }
    }
    return true;
}
