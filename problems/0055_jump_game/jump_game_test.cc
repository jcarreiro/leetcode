#include "jump_game.h"
#include <gtest/gtest.h>

TEST(Solution, Example01) {
  Solution s;
  vector<int> v{2, 3, 1, 1, 4};
  EXPECT_TRUE(s.canJump(v));
}

TEST(Solution, Example02) {
  Solution s;
  vector<int> v{2, 0};
  EXPECT_TRUE(s.canJump(v));
}

TEST(Solution, Example03) {
  Solution s;
  vector<int> v{2, 0, 0};
  EXPECT_TRUE(s.canJump(v));
}

TEST(Solution, InputHasZero) {
  Solution s;
  vector<int> v{2, 3, 1, 0, 4};
  EXPECT_TRUE(s.canJump(v));
}

TEST(Solution, CantReachEnd) {
  Solution s;
  vector<int> v{3, 2, 1, 0, 4};
  EXPECT_FALSE(s.canJump(v));
}

TEST(Solution, AllZeros) {
  Solution s;
  vector<int> v{0, 0, 0, 0, 0};
  EXPECT_FALSE(s.canJump(v));
}

TEST(Solution, SingleElementArray) {
  Solution s;
  vector<int> v{0};
  EXPECT_TRUE(s.canJump(v));
}

