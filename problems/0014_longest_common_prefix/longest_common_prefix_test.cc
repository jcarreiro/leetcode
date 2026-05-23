#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "longest_common_prefix.h"

using namespace std;

TEST(LongestCommonPrefixTest, Test01) {
  Solution s;
  vector<string> strs{"flower","flow","flight"};
  EXPECT_EQ(s.longestCommonPrefix(strs), "fl");
}

TEST(LongestCommonPrefixTest, Test02) {
  Solution s;
  vector<string> strs{"dog","racecar","car"};
  EXPECT_EQ(s.longestCommonPrefix(strs), "");
}



