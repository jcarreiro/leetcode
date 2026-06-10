#include "game_of_life.h"
#include <gtest/gtest.h>

TEST(GameOfLifeTest, Test01) {
  Solution s;
  vector<vector<int>> board{{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}}};
  s.gameOfLife(board);
  const vector<vector<int>> expected{
      {{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}}};
  EXPECT_EQ(board, expected);
}

TEST(GameOfLifeTest, Test02) {
  Solution s;
  vector<vector<int>> board{{{1, 1}, {1, 0}}};
  s.gameOfLife(board);
  const vector<vector<int>> expected{{{1, 1}, {1, 1}}};
  EXPECT_EQ(board, expected);
}