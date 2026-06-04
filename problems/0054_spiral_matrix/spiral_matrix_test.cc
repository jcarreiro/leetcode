#include "spiral_matrix.h"
#include <gtest/gtest.h>

TEST(SpiralMatrixTest, Test01) {
  Solution s;
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  const vector<int> expected = {1, 2, 3, 6, 9, 8, 7, 4, 5};
  EXPECT_EQ(s.spiralOrder(matrix), expected);
}

TEST(SpiralMatrixTest, Test02) {
  Solution s;
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  const vector<int> expected = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
  EXPECT_EQ(s.spiralOrder(matrix), expected);
}

TEST(SpiralMatrixTest, SingleRowMatrix) {
  Solution s;
  vector<vector<int>> matrix = {{1, 2, 3, 4}};
  const vector<int> expected = {1, 2, 3, 4};
  EXPECT_EQ(s.spiralOrder(matrix), expected);
}

TEST(SpiralMatrixTest, SingleColumnMatrix) {
  Solution s;
  vector<vector<int>> matrix = {{1}, {2}, {3}, {4}};
  const vector<int> expected = {1, 2, 3, 4};
  EXPECT_EQ(s.spiralOrder(matrix), expected);
}

TEST(SpiralMatrixTest, SingleElementMatrix) {
  Solution s;
  vector<vector<int>> matrix = {{1}};
  const vector<int> expected = {1};
  EXPECT_EQ(s.spiralOrder(matrix), expected);
}