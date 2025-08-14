#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "solution.h"

using namespace std;

TEST(SolutionTest, Test01) {
  Solution s;
  EXPECT_TRUE(s.isPalindrome("A man, a plan, a canal: Panama"));
}

TEST(SolutionTest, Test02) {
  Solution s;
  EXPECT_FALSE(s.isPalindrome("race a car"));
}

TEST(SolutionTest, Test03) {
  Solution s;
  EXPECT_TRUE(s.isPalindrome(" "));
}
