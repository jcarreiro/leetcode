#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "solution.h"

using namespace std;

TEST(SolutionTest, Test01) {
  Solution s;
  EXPECT_EQ(s.lengthOfLastWord("Hello World"), 5);
}

TEST(SolutionTest, Test02) {
  Solution s;
  EXPECT_EQ(s.lengthOfLastWord("   fly me   to   the moon  "), 4);
}

TEST(SolutionTest, Test03) {
  Solution s;
  EXPECT_EQ(s.lengthOfLastWord("luffy is still joyboy"), 6);
}

TEST(SolutionTest, Test04) {
  Solution s;
  EXPECT_EQ(s.lengthOfLastWord("a"), 1);
}
