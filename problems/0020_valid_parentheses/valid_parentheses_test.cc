#include "valid_parentheses.h"
#include <gtest/gtest.h>

TEST(ValidParenthesesTest, Test01) {
  Solution s;
  EXPECT_TRUE(s.isValid("()"));
}

TEST(ValidParenthesesTest, Test02) {
  Solution s;
  EXPECT_TRUE(s.isValid("()[]{}"));
}

TEST(ValidParenthesesTest, Test03) {
  Solution s;
  EXPECT_FALSE(s.isValid("(]"));
}

TEST(ValidParenthesesTest, Test04) {
  Solution s;
  EXPECT_TRUE(s.isValid("([])"));
}

TEST(ValidParenthesesTest, Test05) {
  Solution s;
  EXPECT_FALSE(s.isValid("([)]"));
}
