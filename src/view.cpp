#include "../include/view.h"

// Constructor initializes View with a reference to the game logic (Play)
View::View(Play& gamePlay) : play(gamePlay) {}

// Draw: Main render function called every frame
void View::Draw() {
    DrawBoard();     // Draw the background and board grid
    DrawSymbols();   // Draw X and O symbols based on board state

    // If the game is over, draw the overlay and winner message
    if (play.IsGameOver()) {
        DrawGameOver();
    }

    // Determine the text to show based on current game mode
    const char* modeText = play.IsRandomMode() ? "Random Mode" :
                           play.IsForgetMode() ? "Forget Mode" : "Normal Mode";

    // Help/control text
    const char* controlsText = "Press T to toggle mode | SPACE to reset";

    // Center both texts horizontally using MeasureText()
    int modeWidth = MeasureText(modeText, 15);
    int controlsWidth = MeasureText(controlsText, 15);

    // Draw mode text near top-center of screen
    DrawText(modeText,
             GetScreenWidth() / 2 - modeWidth / 2,
             10, 15, Color{52, 73, 94, 255}); // Subtle dark blue-gray color

    // Draw controls info just below mode text
    DrawText(controlsText,
             GetScreenWidth() / 2 - controlsWidth / 2,
             30, 15, Color{52, 73, 94, 255});
}

// DrawBoard: Draws the board background, gradient, and grid lines
void View::DrawBoard() {
    // Subtle vertical gradient background from top to bottom
    for (int i = 0; i < GetScreenHeight(); i++) {
        float alpha = 0.1f + (float)i / GetScreenHeight() * 0.05f; // Light gradient
        DrawRectangle(0, i, GetScreenWidth(), 1,
                      Color{245, 247, 250, (unsigned char)(alpha * 255)});
    }

    // White board background with a subtle shadow effect
    DrawRectangle(PADDING - 5, PADDING - 5,
                  BOARD_SIZE * CELL_SIZE + 10,
                  BOARD_SIZE * CELL_SIZE + 10,
                  Color{255, 255, 255, 255});

    // Draw vertical and horizontal grid lines
    for (int i = 1; i < BOARD_SIZE; i++) {
        // Vertical line
        DrawRectangle(
            PADDING + i * CELL_SIZE - 1, PADDING,
            2, BOARD_SIZE * CELL_SIZE,
            Color{230, 230, 230, 255}  // Light gray grid lines
        );

        // Horizontal line
        DrawRectangle(
            PADDING, PADDING + i * CELL_SIZE - 1,
            BOARD_SIZE * CELL_SIZE, 2,
            Color{230, 230, 230, 255}
        );
    }
}

// DrawSymbols: Loops through the board and draws X or O at each occupied cell
void View::DrawSymbols() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Calculate center of each cell
            int x = PADDING + j * CELL_SIZE + CELL_SIZE / 2;
            int y = PADDING + i * CELL_SIZE + CELL_SIZE / 2;

            // Get board value: 1 = X, 2 = O
            int val = play.GetBoardValue(i, j);

            if (val == 1) {
                // Draw X (blue)
                DrawText("X", x - 20, y - 25, 50, Color{41, 128, 185, 255});
            }
            else if (val == 2) {
                // Draw O (orange)
                DrawText("O", x - 20, y - 25, 50, Color{230, 126, 34, 255});
            }
        }
    }
}

// DrawGameOver: Displays the result message and restart instruction
void View::DrawGameOver() {
    const char* message;
    int winner = play.GetWinner();

    // Determine what message to show
    if (winner == 1) message = "X Wins!";
    else if (winner == 2) message = "O Wins!";
    else if (winner == 3) message = "Draw!";

    // Semi-transparent white overlay to fade the background
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(),
                  Color{255, 255, 255, 240});

    // Pick color based on who won
    Color textColor = winner == 1 ? Color{41, 128, 185, 255} :  // Blue for X
                      winner == 2 ? Color{230, 126, 34, 255} :  // Orange for O
                      Color{52, 73, 94, 255};                   // Gray for draw

    // Draw the game result message at center of screen
    DrawText(message,
             GetScreenWidth() / 2 - MeasureText(message, 40) / 2,
             GetScreenHeight() / 2 - 20, 40, textColor);

    // Prompt to restart
    DrawText("Press SPACE to restart",
             GetScreenWidth() / 2 - MeasureText("Press SPACE to restart", 20) / 2,
             GetScreenHeight() / 2 + 30, 20, Color{52, 73, 94, 255});
}