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

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    void CheckWinner();

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    bool IsBoardFull();

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    void ResetGame();

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    void RemoveOldestSymbol(bool isX);

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    void HandleInputNormal();

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    void HandleInputForget();

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    void HandleInputRandom();

public:
    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    Play();

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    void HandleInput();

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    void Update();

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    bool IsGameOver() const { return gameOver; }

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    int GetWinner() const { return winner; }

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    int GetBoardValue(int row, int col) const { return board[row][col]; }

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    bool IsPlayerXTurn() const { return playerXTurn; }

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    void ToggleMode() { mode = static_cast<Mode>((mode + 1) % 3); ResetGame(); }

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    bool IsForgetMode() const { return mode == FORGET; }

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    bool IsRandomMode() const { return mode == RANDOM; }

    /**
     * TODO: Provide docstring and any edge cases if exists.
     */
    bool IsNormalMode() const { return mode == NORMAL; }
};

#endif //TICTACTOE_PLAY_H
