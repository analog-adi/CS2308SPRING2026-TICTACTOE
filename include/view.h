#ifndef TICTACTOE_VIEW_H
#define TICTACTOE_VIEW_H

#include "raylib.h"
#include "play.h"

/**
 * @class View
 * @brief Handles rendering of the TicTacToe game using Raylib.
 *
 * This class is responsible for visually displaying the game board,
 * the X and O symbols, game mode indicators, and game-over messages.
 * It relies on the Play class to obtain game state information.
 */
class View {
private:
    static const int BOARD_SIZE = 3;   ///< Number of rows and columns in the game grid
    static const int CELL_SIZE = 100;  ///< Size of each cell in pixels
    static const int PADDING = 50;     ///< Padding around the game board

    Play& play;                        ///< Reference to the game logic object

    /**
     * @brief Draws the background, grid lines, and overall board layout.
     *
     * Edge Case:
     * - Assumes screen size is large enough to accommodate the full grid
     *   based on CELL_SIZE and PADDING.
     * - Improper screen resolution may cause drawing to overflow screen boundaries.
     */
    void DrawBoard();

    /**
     * @brief Draws X and O symbols based on current board state.
     *
     * Edge Case:
     * - If an invalid value (not 1 or 2) exists in the board array,
     *   no symbol is drawn for that cell.
     * - Board coordinates out of bounds are not expected and not handled here.
     */
    void DrawSymbols();

    /**
     * @brief Displays the result of the game (X Wins, O Wins, or Draw).
     *
     * Edge Case:
     * - Relies on Play::GetWinner(). If the value is unexpected (not 1, 2, or 3),
     *   no game over message is shown.
     */
    void DrawGameOver();

public:
    /**
     * @brief Constructor for View.
     *
     * @param gamePlay Reference to the game logic handler (Play class).
     *
     * Edge Case:
     * - The reference must remain valid throughout the lifetime of the View object;
     *   no internal null check is performed.
     */
    View(Play& gamePlay);

    /**
     * @brief Draws the complete frame including board, symbols, mode status, and controls.
     *
     * Edge Case:
     * - Assumes that the Raylib drawing context is properly initialized (BeginDrawing/EndDrawing).
     * - Improper font sizes or long mode labels may result in text overflow.
     */
    void Draw();
};

#endif //TICTACTOE_VIEW_H
