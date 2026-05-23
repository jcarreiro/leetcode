#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "is_subsequence.h"

using namespace std;

TEST(IsSubsequenceTest, Test01) {
  Solution s;
  EXPECT_TRUE(s.isSubsequence("abc", "ahbgdc"));
}

TEST(IsSubsequenceTest, Test02) {
  Solution s;
  EXPECT_FALSE(s.isSubsequence("axc", "ahbgdc"));
}



