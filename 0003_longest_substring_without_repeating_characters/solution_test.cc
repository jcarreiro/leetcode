#include "solution.h"
#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>

using namespace std;

TEST(SolutionTest, Test01) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(SolutionTest, Test02) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
}

TEST(SolutionTest, Test03) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(SolutionTest, Test04) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring(" "), 1);
}

TEST(SolutionTest, Test05) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring("abba"), 2);
}
