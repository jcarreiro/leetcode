// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// # 289. Game of Life
//
// According to Wikipedia's article: "The Game of Life, also known simply as
// Life, is a cellular automaton devised by the British mathematician John
// Horton Conway in 1970."
//
// The board is made up of an m x n grid of cells, where each cell has an
// initial state: live (represented by a 1) or dead (represented by a 0). Each
// cell interacts with its eight neighbors (horizontal, vertical, diagonal)
// using the following four rules (taken from the above Wikipedia article):
//
// 1. Any live cell with fewer than two live neighbors dies as if caused by
//    under-population.
//
// 2. Any live cell with two or three live neighbors lives on to the next
//    generation.
//
// 3. Any live cell with more than three live neighbors dies, as if by
//    over-population.
//
// 4. Any dead cell with exactly three live neighbors becomes a live cell, as
//    if by reproduction.
//
// 5. The next state of the board is determined by applying the above rules
//    simultaneously to every cell in the current state of the m x n grid board.
//    In this process, births and deaths occur simultaneously.
//
// Given the current state of the board, update the board to reflect its next
// state.
//
// Note that you do not need to return anything.
//
// ## Example 1
// Input: `board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]`
// Output: `[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]`
//
// ## Example 2
// Input: `board = [[1,1],[1,0]]`
// Output: `[[1,1],[1,1]]`
//
// ## Constraints
// - `m == board.length`
// - `n == board[i].length`
// - `1 <= m, n <= 25`
// - `board[i][j]` is `0` or `1`.
//
// ## Follow up
// - Could you solve it in-place? Remember that the board needs to be updated
//   simultaneously: You cannot update some cells first and then use their
//   updated values to update other cells.
//
// - In this question, we represent the board using a 2D array. In principle,
//   the board is infinite, which would cause problems when the active area
//   encroaches upon the border of the array (i.e., live cells reach the
//   border). How would you address these problems?
class Solution {
public:
  int applyRules(const int state, const int neighborCount) {
    if (state) {
      if (neighborCount < 2) {
        // A living cell with less than two neighbors dies.
        return 0;
      } else if (neighborCount == 2 || neighborCount == 3) {
        // A living cell with two or three neighbors stays alive.
        return 1;
      } else {
        // A living cell with more than three neighbors dies.
        return 0;
      }
    } else if (neighborCount == 3) {
      // A dead cell with three neighbors returns to life.
      return 1;
    }
    return 0;
  }

  int getCell(const vector<vector<int>>& board, int x, int y) {
    if (x >= 0 && x < board[0].size() && y >= 0 && y < board.size()) {
      return board[y][x] & 0x1;
    }
    return 0;
  }

  void gameOfLife(vector<vector<int>>& board) {
    // The basic idea: we'll iterate over the board, computing the new state
    // of each cell. Since each cell has an int's worth of space but only
    // needs a single bit of storage, we'll pack the new state into an unused
    // bit. Then we can do a second pass over all the cells, updating the
    // value of each cell for the next generation.
    for (int y = 0; y < board.size(); y++) {
      for (int x = 0; x < board[0].size(); x++) {
        struct Direction {
          int x;
          int y;
        };

        static constexpr array<Direction, 8> dirs{{
            {-1, -1}, // top left
            {0, -1},  // top
            {1, -1},  // top right
            {-1, 0},  // left
            {1, 0},   // right
            {-1, 1},  // bottom left
            {0, 1},   // bottom
            {1, 1},   // bottom right
        }};
        int count = 0;
        for (const auto& d : dirs) {
          count += getCell(board, x + d.x, y + d.y);
        }

        int state = getCell(board, x, y);
        int next = applyRules(state, count);
        board[y][x] = (board[y][x] & 0x1) | (next << 1);
      }
    }

    for (int y = 0; y < board.size(); y++) {
      for (int x = 0; x < board[0].size(); x++) {
        board[y][x] >>= 1;
      }
    }
  }
};
