#include "jump_game_ii.h"
#include <gtest/gtest.h>

TEST(Solution, Example01) {
  Solution s;
  vector<int> v{2, 3, 1, 1, 4};
  EXPECT_EQ(s.jump(v), 2);
}

TEST(Solution, Example02) {
  Solution s;
  vector<int> v{2, 3, 0, 1, 4};
  EXPECT_EQ(s.jump(v), 2);
}

TEST(Solution, Test01) {
  Solution s;
  vector<int> v{7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
  EXPECT_EQ(s.jump(v), 2);
}

