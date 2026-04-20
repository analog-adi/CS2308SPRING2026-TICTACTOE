#ifndef TICTACTOE_PLAY_H
#define TICTACTOE_PLAY_H

#include "raylib.h"
#include <deque>
#include <utility>

/**
 * @class Play
 * @brief Manages all game logic for TicTacToe with three gameplay modes.
 *
 * This class is made to do:
 * -Record game board state.
 * -Maintain player turn memory
 * - Detect Win or Draw condition across rows, columns, and diagonals.
 * -Maintain three game modes: NORMAL (unlimited symbols), FORGET (oldest removed), RANDOM (random symbol removed when limit exceeded).
 * -Process input and convert pixel coordinates to board indices.
 * -Track positions in deques for FORGET and RANDOM modes.
 *
 * Edge Cases:
 * - What might happen if the playerInput is outside the game boundry
 * -Are the X and O symbols properly tracked in the deques for FORGET and RANDOM modes?
 * -What happens if the mode is toggled in the middle of a game?
 * -Does the CheckWinner function correctly identify wins and draws in all scenarios?
 * -Does the RemoveOldestSymbol function correctly handle the case when the deque is empty?
 * -Does the HandleInput functions correctly enforce the rules for each mode, especially when placing symbols and switching turns?
 * -Does the ResetGame function properly clear the board and reset all state variables to their initial values?
 */
class Play {
private:
    static const int BOARD_SIZE = 3;     ///< Playing area dimensions: 3X3 board for classic TicTacToe gameplay
    static const int MAX_SYMBOLS = 3;    ///< Maximum number of symbol useful for FORGET/RANDOM game mode

    int board[BOARD_SIZE][BOARD_SIZE];   ///< Two-Dimensional array for tracking the state of the game board: 0 for empty, 1 for X, 2 for O
    bool playerXTurn;                    ///< Boolean flag to track which player's turn it is: true for X's turn, false for O's turn; X always starts first
    bool gameOver;                       ///< Boolean flag to indicate if the game has ended: true when a win or draw condition is detected, false during active play
    int winner;                          ///< Integer to represent the winner of the game: 1 for X wins, 2 for O wins, 3 for draw, 0 if game is still in progress

    enum Mode { NORMAL, FORGET, RANDOM };///< Enumeration to represent the three different game modes: NORMAL, FORGET, RANDOM
    Mode mode;                           ///< Variable to track the currently active game mode; can be toggled by the player using the T key

    std::deque<std::pair<int, int>> xPositions; ///< Tracks all X moves in order of placement (used in FORGET and RANDOM mode)
    std::deque<std::pair<int, int>> oPositions; ///< Tracks all O moves in order of placement (used in FORGET and RANDOM mode)

    void CheckWinner();
    /**
    *@brief Scans the entire board to detect win or draw conditions.
     *
     * Checks all 8 possible winning conditions (3 rows + 3 columns + 2 diagonals)
     * and determines if the board is  completely filled (draw condition)
     * Sets gameOver= true and winner appropriately when condition is found
     *
     * @return void (modifies gameOver and winner member variables)
     *
     * Edge Cases:
     * - Empty board returns without setting gameOver
     * -  Multiple winning conditions stop at first match (row check before column)
     * - Draw only detected after all winning conditions fail
     * - Called every frame in Update() when gameOver is false
    */
    bool IsBoardFull();
    /**
     * @brief Checks if all 9 cells of the board are filled with symbols.
     *
     * Iterates through the 3x3 board array to determine if any empty cells remain.
     * Used by CheckWinner() to detect draw condition.
     *
     * @return bool- true if all cells are filled (no empty cells), false if at least one cell is empty
     *
     * Edge Cases:
     * - Returns false immediately upon finding first empty cell (optimization)
     * - Empty board (all zeros) returns false correctly
     */

    void ResetGame();

    /**
    *  @brief Reinitializes all game state for a fresh game.
     *
     * Clears the board (all cells set to 0), resets player turn to X, sets gameOver
     * to false, clears winner value, and empties both position tracking deques.
     * Called on game start, reset (SPACE key), and mode toggle.
     *
     * @return void (modifies all member variables)
     *
     * Edge Cases:
     * - Safe to call multiple times without side effects
     * - Clears move history for custom modes
     */
    void RemoveOldestSymbol(bool isX);

    /**
    *  @brief Removes the oldest symbol from the board when player exceeds MAX_SYMBOLS.
     *
     * Used only in FORGET and RANDOM modes. Gets the oldest position from the front
     * of the player's deque, clears that cell on the board, and removes the position
     * from the deque.
     *
     * @param isX - true to remove oldest X symbol, false for oldest O symbol
     *
     * Edge Cases:
     * - Safely handles empty deque with early return
     * - Updates both board array and deque (crucial for consistency)
     * - Called BEFORE placing new symbol in FORGET mode
     * - Called AFTER placing new symbol in RANDOM mode
     */
    void HandleInputNormal();

    /**
    *  @brief Handles input for NORMAL mode with no symbol limits.
     *
     * Detects mouse clicks, converts pixel coordinates to board indices, validates
     *  the click is within  bounds and on an empty cell, then places the symbol.
     * Switches turn after successful placement.
     *
     * @return void (modifies board array and playerXTurn)
     *
     * Edge Cases:
     * - Ignores clicks when gameOver is true
     * - Ignores clicks outside board boundaries
     * -  Ignores clicks on oupied cells
     * - No symbol limit enforcement (unlimited placement)
     */
    void HandleInputForget();
    /**
  *  @brief Handles input for FORGET mode where oldest symbol is removed when limit exceeded.
  *
  * Each player can maintain maximum 3 symbols on board. When a player places their
  * 4th symbol, the oldest is automatically removed before the new one is placed.
  * Tracks moves in deque for FIFO (first-in-first-out) removal.
  *
  * @return void (modifies board, deques, and playerXTurn)
  *
  * Edge Cases:
  * - Checks size >= MAX_SYMBOLS BEFORE placing (ensures max 3 at any time)
  * - Calls RemoveOldestSymbol() when limit reached
  * - Ignores invalid clicks (outside bounds, occupied cells)
  * - Maintains fairness through FIFO removal strategy
  */
    void HandleInputRandom();
    /**
   * @brief Handles input for RANDOM mode where random symbol removed when limit exceeded.
   *
   * Similar to FORGET mode, each player maintains maximum 3 symbols. However,
   * when a 4th symbol is placed, a RANDOM older symbol (not necessarily oldest)
   * is removed. Creates unpredictable gameplay compared to FORGET mode.
   *
   * @return void (modifies board, deques, and playerXTurn)
   *
   * Edge Cases:
   * - Places symbol FIRST, then removes if size exceeds 3
   * - Uses rand() for randomization (all 3 symbols have equal removal chance)
   * - Ignores invalid clicks
   * - Different removals each playthrough (non-deterministic)
   */
public:

    Play();
 /**
 * @brief Constructor initializes game in NORMAL mode and sets up initial state.
 *
 * Initializes mode to NORMAL and calls ResetGame() to set up the board
 * and game state. Called once at program start from main.cpp.
 *
 * Edge Cases:
 * - No parameters; all initialization done via ResetGame()
 * - Default mode is NORMAL (no restrictions)
    */


    void HandleInput();

 /**
* @brief Routes keyboard and mouse input to appropriate mode handler.
*
* Checks for special keys (SPACE to reset, T to toggle mode) first, then
* dispatches remaining input to the appropriate handler based on current mode
* (HandleInputNormal, HandleInputForget, or HandleInputRandom).
*
* @return void (modifies game state based on input)
*
* Edge Cases:
* - SPACE key always resets regardless of game state
* - T key toggles modes and automatically resets
* - Input is only processed when not blocked by game-over state
  */
    void Update();

  /**
  * @brief Main game update function called every frame from main game loop.
  *
  * Processes input first via HandleInput(), then checks for win/draw conditions
  * via CheckWinner() if game is still active.
  *
  * @return void (modifies all game state variables)
  *
  * Edge Cases:
  * - CheckWinner() only called when gameOver is false (optimization)
  * - Called at 120 FPS (SetTargetFPS in main.cpp)
     */
    bool IsGameOver() const { return gameOver; }

 /**
  * @brief Queries if game has ended (win or draw detected).
  *
  * @return bool - true if game over, false if game is still in progress
  */
    int GetWinner() const { return winner; }

    /**
     * @brief Retrieves the winner of the completed game.
     *
     * @return int - 1 if X wins, 2 if O wins, 3 for draw, 0 if game still in progress
     */
    int GetBoardValue(int row, int col) const { return board[row][col]; }

    /**
     * @brief Queries the current state of a board cell.
     *
     * @param row - Row index (0-2)
     * @param col - Column index (0-2)
     *
     * @return int - 0 for empty, 1 for X symbol, 2 for O symbol
     *
     * Edge Cases:
     * - Does not validate row/col bounds; caller responsible for valid indices
     */
    bool IsPlayerXTurn() const { return playerXTurn; }

    /**
     * @brief Queries whose turn it is.
     *
     * @return bool - true if X's turn, false if O's turn
     */
    void ToggleMode() { mode = static_cast<Mode>((mode + 1) % 3); ResetGame(); }

    /**
     * @brief Cycles through game modes: NORMAL → FORGET → RANDOM → NORMAL.
     *
     * Uses modulo arithmetic to cycle through the three modes and automatically
     * resets the game after mode change.
     *
     * @return void (modifies mode and calls ResetGame())
     *
     * Edge Cases:
     * - Triggered by T key press
     * - Always resets game state after mode switch
     */
    bool IsForgetMode() const { return mode == FORGET; }

    /**
    * @brief Checks if current mode is FORGET mode.
    *
    * @return bool - true if mode == FORGET, false otherwise
    */
    bool IsRandomMode() const { return mode == RANDOM; }

    /**
     * @brief Checks if current mode is RANDOM mode.
     *
     * @return bool - true if mode == RANDOM, false otherwise
     */
    bool IsNormalMode() const { return mode == NORMAL; }
    /**
     * @brief Checks if current mode is NORMAL mode.
     *
     * @return bool - true if mode == NORMAL, false otherwise
     */
};

#endif //TICTACTOE_PLAY_H
