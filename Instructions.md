<!-- Red Background Warning -->
<div style="background-color:#ffcccc; padding:15px; border-radius:5px; font-weight:bold;">

⚠️ **IMPORTANT NOTICE**

**Use of Generative AI Tools (e.g., ChatGPT):**
- You may use AI tools for **learning and understanding**, not for blindly copy-pasting solutions.
- You are expected to **read, analyze, and explain** the logic you write.
- If misuse is suspected, your project will require a **live code explanation** and may be **disqualified**.

**Repository Contribution Rules:**
- Do **not modify shared files or folders** that are not assigned to you.
- This is a **collaborative educational project**; individual contributions must be clear.

</div>

# 🎮 TicTacToe with Raylib — Documentation & Custom Mode Implementation

## Overview

You are provided with a clean implementation of a TicTacToe game using **C++** and **Raylib**. Your goal is to:
- Write proper **docstrings and edge case documentation**.
- Understand and **explain the rendering and logic functions**.
- **Implement two new gameplay modes** with unique logic.

---

## ✅ What You’re Working With

```text
TicTacToe/
├── include/
│ ├── play.h ← Add docstrings & TODOs
│ └── view.h
│
├── src/
│ ├── play.cpp ← Add comments, implement game logic
│ └── view.cpp
│
├── Readme.md ← Basic Information about the project
├── Instructions.md ← How to complete the assignment?
├── ProgramFlow.md ← Provide a detail program flow of the game.
├── SelfReflections.md ← Answer self reflections questions.
│
├── main.cpp ← Read-only (add TODOs only if instructed)
├── run.sh ← (optional) for Linux/macOS
├── CMakeLists.txt ← Build system (already configured)
```

---

## 📝 Instructions

### 🔹 Part 1: Docstrings and Edge Cases

1. **`play.h` and `view.h`**
    - For every function, class, and constant, add a **docstring** in the format:
      ```cpp
      /**
       * TODO: Provide docstring and any edge cases if exists.
       */
      ```
    - For all variable declarations or inline constants:
      ```cpp
      ///< TODO: Explain!
      ```

2. **`play.cpp` and `view.cpp`**
    - Replace existing comments with:
        - `// TODO: Explain?` → for one-line expressions
        - `// TODO: Explain below` → for loops or blocks

---

### 🔹 Part 2: Implement Custom Game Modes

Inside `play.cpp`, you will find these three function stubs:

```cpp
void Play::HandleInputForget(); // Calls `HandleInputNormal()` as default 
void Play::HandleInputRandom(); // Calls `HandleInputNormal()` as default
void Play::RemoveOldestSymbol(bool); // No Implementation
```

#### 🎯 Your Task:

* Read the instructions given in comments inside these functions.
* Step-by-step, replace the call to `HandleInputNormal()` and **implement the correct logic**.
* Step-by-step, **implement the correct logic** for `RemoveOldestSymbol()`.

**FORGET Mode Logic:**

* Each player can only have **3 active symbols**.
* Placing a new symbol should **remove the oldest one**.

**RANDOM Mode Logic:**

* Each player can only have **3 active symbols**.
* Placing a new symbol should **remove a random old one**.

**Remove Oldest Logic:**

* Use the player's position queue (xPositions or oPositions) to track the order of placements.
* The oldest move is at the **front** of the deque.
* Remove it from the board and from the queue.

---

### 🔹 Part 3: Provide ProgramFlow (in ProgramFlow.md)
* Study the example provided in ProgramFlow.md for some dummy program
* Now create similar ProgramFlow for this overall project
* Ignore library functions call or any recursion calls


### 🔹 Part 4: SelfReflection (in SelfReflections.md)
* Complete the self reflection questions in SelfReflections.md

After completing your changes:

* Add your **explanation as inline comments** next to important lines in `HandleInputForget()` and `HandleInputRandom()`.
* Mention:
    * Why you chose that approach
    * What bug or edge case you considered (e.g., duplicate moves, invalid clicks)

---

## 🧪 Build & Run Instructions

### ✅ From Terminal

```bash
mkdir build
cd build
cmake ..
make
./TicTacToe
```

### ✅ From CLion

1. Open the `TicTacToe` folder in CLion.
2. Right-click on `CMakeLists.txt` → **Reload CMake Project**.
3. Press **Build** ▶️ and then **Run**.

---

## 🎓 Submission Checklist

* [x] `play.h`updated with all docstrings and edge case notes.
* [x] `play.cpp` include TODOs like `// TODO: Explain?`.
* [x] `HandleInputForget()` implemented with correct logic and inline explanations.
* [x] `HandleInputRandom()` implemented with correct logic and inline explanations.
* [ ] The dummy calls to `HandleInputNormal()` are removed.
* [ ] `RemoveOldestSymbol()` implemented with correct logic and inline explanations.
* [ ] The game runs correctly in all modes.
* [ ] Program Flow Requirement Completed
* [ ] Self Reflections Questions Completed

---

Here's how students can **run the Tic Tac Toe project in DEBUG mode**, adapted to fit the same style and structure as your previous project instructions:

---

## 🐞 Running in Debug Mode (CLion Recommended)

### What is Debug Mode?

Debug mode allows you to step through code, set breakpoints, inspect variables, and ensure that your logic is functioning correctly — especially helpful when you're implementing or fixing logic like in `HandleInputForget()` or `HandleInputRandom()`.

---

### 🔧 For CLion Users (Recommended)

1. **Open the Project in CLion:**

    * Open the `TicTacToe/` folder directly in CLion.

2. **Set the Build Type to Debug:**

    * Go to the top-right where the run configuration is located.
    * Click the dropdown (e.g., it might say “Release”) and select `Debug`.

3. **Place Breakpoints:**

    * Click on the **left margin** of any line number in `play.cpp` to set a red dot (breakpoint).

4. **Run in Debug Mode:**

    * Press the **bug icon** 🐞 or choose `Run > Debug` from the top menu.
    * The execution will pause at your breakpoints, allowing you to inspect variable values step-by-step.

---

## Submission Guidelines (To Canvas)

* ZIP everything and upload the zip file in canvas
* Make sure everything is completed and up and running

## 🏁 Final Notes

* You are encouraged to test your game by **switching modes (T key)** and restarting (SPACE key).
* Feel free to style your board further (colors, fonts, etc.), but **focus on logic first**.

---

Good luck, and remember: **understanding before execution**!
