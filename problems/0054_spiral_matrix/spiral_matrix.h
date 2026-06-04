// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <array>
#include <vector>

using namespace std;

// # 54. Spiral Matrix
//
// Given an m x n matrix, return all elements of the matrix in spiral order.
//
// ## Example 1
// Input: `matrix = [[1,2,3],[4,5,6],[7,8,9]]`
// Output: `[1,2,3,6,9,8,7,4,5]`
//
// ## Example 2
// Input: `matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]`
// Output: `[1,2,3,4,8,12,11,10,9,5,6,7]`
//
// ## Constraints
// - `m == matrix.length`
// - `n == matrix[i].length`
// - `1 <= m, n <= 10`
// - `-100 <= matrix[i][j] <= 100`
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    // Technically the assumptions say the matrix can't be empty, but it doesn't
    // hurt to check.
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }

    // The basic idea here:
    // - store our position and the direction we're currently going
    // - move in that direction until we hit a "wall"
    // - when we hit a wall, turn 90 deg clockwise
    //
    // We take advantage of the fact that the problem specifies that the input
    // matrix will always have values in the range [-100, 100] to re-use the
    // input matrix to track the visited elements, by overwriting each with an
    // invalid value after we visit it.
    constexpr auto kInvalidValue = 2702;

    struct Direction {
      int dx;
      int dy;
    };

    constexpr array<Direction, 4> kDirections{Direction{1, 0},   // right
                                              Direction{0, 1},   // down
                                              Direction{-1, 0},  // left
                                              Direction{0, -1}}; // up

    struct Position {
      int x;
      int y;

      Position plus(const Direction d) const { return {x + d.dx, y + d.dy}; }
    };

    // The current position and direction for iteration (the latter as an index
    // into the kDirections array).
    Position pos{0, 0};
    size_t dirIndex = 0;

    // Pre-allocate our output array. We assume all rows are the same size.
    const auto kMatrixSize = matrix.size() * matrix[0].size();
    vector<int> elems;
    elems.reserve(kMatrixSize);

    // We have to visit each element once, so we can use that to check for
    // whether or not we're done traversing the matrix.
    for (size_t i = 0; i < kMatrixSize; i++) {
      // Visit our current element.
      elems.emplace_back(matrix[pos.y][pos.x]);

      // Mark it as visited.
      matrix[pos.y][pos.x] = kInvalidValue;

      // Update our position.
      Direction dir = kDirections[dirIndex];
      Position newPos = pos.plus(dir);
      if (newPos.x < 0 || newPos.x >= matrix[0].size() || newPos.y < 0 ||
          newPos.y >= matrix.size() ||
          matrix[newPos.y][newPos.x] == kInvalidValue) {
        // We went off the edge of the matrix, or we already visited this
        // element; either way, rotate which direction we're moving.
        dirIndex = (dirIndex + 1) % 4;
        dir = kDirections[dirIndex];
        newPos = pos.plus(dir);
      }

      pos = newPos;
    }

    return elems;
  }
};
