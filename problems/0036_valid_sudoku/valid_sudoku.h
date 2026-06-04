// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <unordered_set>
#include <vector>

using namespace std;

// # 36. Valid Sudoku
//
// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
// validated according to the following rules:
//
// 1. Each row must contain the digits 1-9 without repetition.
//
// 2. Each column must contain the digits 1-9 without repetition.
//
// 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
//    without repetition.
//
// Note:
//
// - A Sudoku board (partially filled) could be valid but is not necessarily
//   solvable.
//
// - Only the filled cells need to be validated according to the mentioned
//   rules.
//
// ## Example 1
// Input:
// ```
// board =
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// ```
// Output: true
//
// ## Example 2
// Input:
// ```
// board =
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// ```
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner
// being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
// is invalid.
//
// ## Constraints
//
// - `board.length == 9`
// - `board[i].length == 9`
// - `board[i][j]` is a digit 1-9 or '.'.
class Solution {
public:
  bool checkDigit(const char c, unordered_set<char>& s) {
    // '.'s are blank spaces.
    if (c == '.') {
      return true;
    }

    const auto& rv = s.insert(c);
    return rv.second;
  }

  bool isValidSudoku(vector<vector<char>>& board) {
    // We're going to iterate over the rows, then the columns, then finally the
    // sub-boxes; each time, we're going to insert the values into a hash set.
    // If we ever find a duplicate, the sudoku isn't valid.
    //
    // Since we visit each element 3 times, this is O(n).
    //
    // Start with the rows.
    unordered_set<char> s;
    for (size_t i = 0; i < board.size(); i++) {
      for (size_t j = 0; j < board[0].size(); j++) {
        if (!checkDigit(board[i][j], s)) {
          return false;
        }
      }

      // Clear the set for the next row.
      s.clear();
    }

    // Now check the columns.
    for (size_t j = 0; j < board[0].size(); j++) {
      for (size_t i = 0; i < board.size(); i++) {
        if (!checkDigit(board[i][j], s)) {
          return false;
        }
      }

      // Clear the set for the next column.
      s.clear();
    }

    // Now check each 3x3 sub-box.
    for (size_t br = 0; br < board.size(); br += 3) {
      for (size_t bc = 0; bc < board[0].size(); bc += 3) {
        for (size_t i = 0; i < 3; i++) {
          for (size_t j = 0; j < 3; j++) {
            if (!checkDigit(board[br + i][bc + j], s)) {
              return false;
            }
          }
        }

        // Clear the set for the next sub-box.
        s.clear();
      }
    }

    // If we get here, the sudoku is valid.
    return true;
  }
};
