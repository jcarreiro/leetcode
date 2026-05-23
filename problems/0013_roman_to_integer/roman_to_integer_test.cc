#include "roman_to_integer.h"
#include <gtest/gtest.h>

TEST(Test, Test01) {
  Solution s;
  EXPECT_EQ(s.romanToInt("III"), 3);
}

TEST(Test, Test02) {
  Solution s;
  EXPECT_EQ(s.romanToInt("LVIII"), 58);
}

TEST(Test, Test03) {
  Solution s;
  EXPECT_EQ(s.romanToInt("MCMXCIV"), 1994);
}

