#include "set_matrix_zeroes.h"
#include <gtest/gtest.h>

TEST(SetMatrixZeroesTest, Test01) {
  Solution s;
  vector<vector<int>> matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  s.setZeroes(matrix);
  const vector<vector<int>> expected{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  EXPECT_EQ(matrix, expected);
}

TEST(SetMatrixZeroesTest, Test02) {
  Solution s;
  vector<vector<int>> matrix{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  s.setZeroes(matrix);
  const vector<vector<int>> expected{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
  EXPECT_EQ(matrix, expected);
}
