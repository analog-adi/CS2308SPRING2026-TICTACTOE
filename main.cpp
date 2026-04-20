#include "include/play.h"   // Include game logic (Play class)
#include "include/view.h"   // Include rendering logic (View class)

int main() {
    // Define the width and height of the game window in pixels
    const int screenWidth = 400;
    const int screenHeight = 400;

    // Initialize Raylib window with specified dimensions and title
    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");

    // Set the target frame rate (helps control game speed)
    SetTargetFPS(120);

    // Create an instance of the Play class to manage game state
    Play play;

    // Create an instance of the View class to manage rendering
    View view(play);  // Note: passes game state by reference

    // Main game loop - runs until the window is closed
    while (!WindowShouldClose()) {
        // 1. Update game logic (e.g., handle input, check for win/draw)
        play.Update();

        // 2. Begin rendering
        BeginDrawing();

        // 3. Clear background to white each frame
        ClearBackground(WHITE);

        // 4. Render the board, symbols, game over message, and UI
        view.Draw();

        // 5. End rendering (everything drawn is now shown)
        EndDrawing();
    }

    // Cleanly close the window and unload resources
    CloseWindow();

    return 0;
}
