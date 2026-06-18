#include "basic_calculator.h"

#include <gtest/gtest.h>

TEST(BasicCalculatorTest, Test01) {
  Solution s;
  EXPECT_EQ(s.calculate("1 + 1"), 2);
}

TEST(BasicCalculatorTest, Test02) {
  Solution s;
  EXPECT_EQ(s.calculate(" 2-1 + 2 "), 3);
}

TEST(BasicCalculatorTest, Test03) {
  Solution s;
  EXPECT_EQ(s.calculate("(1+(4+5+2)-3)+(6+8)"), 23);
}

TEST(BasicCalculatorTest, Test04) {
  Solution s;
  EXPECT_EQ(s.calculate("-2147483648"), -2147483648);
}

TEST(BasicCalculatorTest, Test05) {
  Solution s;
  EXPECT_EQ(s.calculate("- (3 + (4 + 5))"), -12);
}

TEST(BasicCalculatorTest, HandlesNegatedSubexpression) {
  Solution s;
  EXPECT_EQ(s.calculate("10+5-(3+2)"), 10);
}