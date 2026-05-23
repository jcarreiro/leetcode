#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "valid_palindrome.h"

using namespace std;

TEST(ValidPalindromeTest, Test01) {
  Solution s;
  EXPECT_TRUE(s.isPalindrome("A man, a plan, a canal: Panama"));
}

TEST(ValidPalindromeTest, Test02) {
  Solution s;
  EXPECT_FALSE(s.isPalindrome("race a car"));
}

TEST(ValidPalindromeTest, Test03) {
  Solution s;
  EXPECT_TRUE(s.isPalindrome(" "));
}



