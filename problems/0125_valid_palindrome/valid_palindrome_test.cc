#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "valid_palindrome.h"

using namespace std;

TEST(Test, Test01) {
  Solution s;
  EXPECT_TRUE(s.isPalindrome("A man, a plan, a canal: Panama"));
}

TEST(Test, Test02) {
  Solution s;
  EXPECT_FALSE(s.isPalindrome("race a car"));
}

TEST(Test, Test03) {
  Solution s;
  EXPECT_TRUE(s.isPalindrome(" "));
}

