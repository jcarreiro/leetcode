#include "roman_to_integer.h"
#include <gtest/gtest.h>

TEST(RomanToIntegerTest, Test01) {
  Solution s;
  EXPECT_EQ(s.romanToInt("III"), 3);
}

TEST(RomanToIntegerTest, Test02) {
  Solution s;
  EXPECT_EQ(s.romanToInt("LVIII"), 58);
}

TEST(RomanToIntegerTest, Test03) {
  Solution s;
  EXPECT_EQ(s.romanToInt("MCMXCIV"), 1994);
}



