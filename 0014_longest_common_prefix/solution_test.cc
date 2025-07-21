#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "solution.h"

using namespace std;

TEST(SolutionTest, Test01) {
  Solution s;
  vector<string> strs{"flower","flow","flight"};
  EXPECT_EQ(s.longestCommonPrefix(strs), "fl");
}

TEST(SolutionTest, Test02) {
  Solution s;
  vector<string> strs{"dog","racecar","car"};
  EXPECT_EQ(s.longestCommonPrefix(strs), "");
}
