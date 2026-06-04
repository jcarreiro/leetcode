// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <array>
#include <iostream>
#include <vector>

using namespace std;

// # 48. Rotate Image
//
// You are given an n x n 2D matrix representing an image, rotate the image by
// 90 degrees (clockwise).
//
// You have to rotate the image in-place, which means you have to modify the
// input 2D matrix directly. DO NOT allocate another 2D matrix and do the
// rotation.
//
// ## Example 1
// Input: `matrix = [[1,2,3],[4,5,6],[7,8,9]]`
// Output: `[[7,4,1],[8,5,2],[9,6,3]]`
//
// ## Example 2
// Input: `matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]`
// Output: `[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]`
//
// ## Constraints
// - `n == matrix.length == matrix[i].length`
// - `1 <= n <= 20`
// - `-1000 <= matrix[i][j] <= 1000`
class Solution {
public:
  struct Index {
    int x;
    int y;

    Index operator+(Index other) const {
      return Index{x + other.x, y + other.y};
    }
  };

  void rotate(vector<vector<int>>& matrix) {
    // We rotate each ring, starting from the outermost, and moving inward.
    int n = matrix.size();
    int offset = 0;
    while (n > 1) {
      // Each rotation is composed of a series of cycles: we move the element at
      // (0, 0) to (n - 1, 0), then we move (n - 1, 0) to (n - 1, n - 1), etc.,
      // as illustrated below:
      //
      //   +------------+-------+------------+
      //   |   (0, 0)   | ----> |  (n-1, 0)  |
      //   +------------+       +------------+
      //   |      ^                    |     |
      //   |      |                    v     |
      //   +------------+       +------------+
      //   |  (0, n-1)  | <---- | (n-1, n-1) |
      //   +------------+-------+------------+
      //
      // until we loop around to (0, 0) and finish the first cycle. Then we
      // repeat this n - 2 times, starting at position (1, 0), (2, 0), ...
      // (n - 2, 0), at which point the entire ring has been rotated.
      //
      // After we've finished all the cycles for one ring, we move inward to the
      // next ring, and so on, until we hit a ring of size 2 or less, at which
      // point there are no smaller rings left to rotate.
      for (int i = 0; i < n - 1; i++) {
        // Each cycle goes right, then down, then left, then finally back up.
        Index i0{offset + i, offset};

        // We want to go (n - 1) pixels to the right, but we may not have enough
        // room, in which case we need to wrap around.
        const int dx = n - 1 - i;
        const int dy = i;
        const array<Index, 4> cycle{{{dx, dy},    // right
                                     {-dy, dx},   // down
                                     {-dx, -dy},  // left
                                     {dy, -dx}}}; // up
        int tmp = matrix[i0.y][i0.x];
        for (const auto& step : cycle) {
          const auto i1 = i0 + step;
          swap(matrix[i1.y][i1.x], tmp);
          i0 = i1;
        }
      }

      n -= 2;
      offset += 1;
    }
  }
};
