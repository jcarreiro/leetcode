#include "jump_game.h"
#include <gtest/gtest.h>

TEST(JumpGameTest, Example01) {
  Solution s;
  vector<int> v{2, 3, 1, 1, 4};
  EXPECT_TRUE(s.canJump(v));
}

TEST(JumpGameTest, Example02) {
  Solution s;
  vector<int> v{2, 0};
  EXPECT_TRUE(s.canJump(v));
}

TEST(JumpGameTest, Example03) {
  Solution s;
  vector<int> v{2, 0, 0};
  EXPECT_TRUE(s.canJump(v));
}

TEST(JumpGameTest, InputHasZero) {
  Solution s;
  vector<int> v{2, 3, 1, 0, 4};
  EXPECT_TRUE(s.canJump(v));
}

TEST(JumpGameTest, CantReachEnd) {
  Solution s;
  vector<int> v{3, 2, 1, 0, 4};
  EXPECT_FALSE(s.canJump(v));
}

TEST(JumpGameTest, AllZeros) {
  Solution s;
  vector<int> v{0, 0, 0, 0, 0};
  EXPECT_FALSE(s.canJump(v));
}

TEST(JumpGameTest, SingleElementArray) {
  Solution s;
  vector<int> v{0};
  EXPECT_TRUE(s.canJump(v));
}



