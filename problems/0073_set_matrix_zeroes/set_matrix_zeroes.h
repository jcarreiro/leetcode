// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <unordered_set>
#include <vector>

using namespace std;

// # 73. Set Matrix Zeroes
//
// Given an m x n integer matrix matrix, if an element is 0, set its entire row
// and column to 0's.
//
// You must do it in place.
//
// ## Example 1
// Input: `matrix = [[1,1,1],[1,0,1],[1,1,1]]`
// Output: `[[1,0,1],[0,0,0],[1,0,1]]`
//
// ## Example 2
// Input: `matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]`
// Output: `[[0,0,0,0],[0,4,5,0],[0,3,1,0]]`
//
// ## Constraints
// - `m == matrix.length`
// - `n == matrix[0].length`
// - `1 <= m, n <= 200`
// `-2^31 <= matrix[i][j] <= 23^1 - 1`
//
// Follow up:
// - A straightforward solution using O(mn) space is probably a bad idea.
// - A simple improvement uses O(m + n) space, but still not the best solution.
// - Could you devise a constant space solution?
class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    // We're going to iterate over the matrix twice:
    //
    // - The first time, when we encounter a 0, we're going to insert the
    //   column and row of the current element into two hashsets.
    //
    // - The second time, we're going to check the current row and column
    //   index in each set as we iterate, and set the value to 0 if we find
    //   a match for either index.
    //
    // This takes O(m * n) time (we iterate over each element twice and do a
    // constant amount of work each time) and O(1) space (the hashset size
    // doesn't depend on m or n).
    unordered_set<size_t> zeroCols;
    unordered_set<size_t> zeroRows;
    for (size_t i = 0; i < matrix.size(); i++) {
      for (size_t j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 0) {
          zeroRows.insert(i);
          zeroCols.insert(j);
        }
      }
    }

    for (size_t i = 0; i < matrix.size(); i++) {
      const bool zeroRow = zeroRows.contains(i);
      for (size_t j = 0; j < matrix[0].size(); j++) {
        if (zeroRow || zeroCols.contains(j)) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};
