#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "integer_to_roman.h"

using namespace std;

TEST(IntegerToRomanTest, Test01) {
  Solution s;
  EXPECT_EQ(s.intToRoman(3749), "MMMDCCXLIX");
}

TEST(IntegerToRomanTest, Test02) {
  Solution s;
  EXPECT_EQ(s.intToRoman(58), "LVIII");
}

TEST(IntegerToRomanTest, Test03) {
  Solution s;
  EXPECT_EQ(s.intToRoman(1994), "MCMXCIV");
}



