#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "integer_to_roman.h"

using namespace std;

TEST(Test, Test01) {
  Solution s;
  EXPECT_EQ(s.intToRoman(3749), "MMMDCCXLIX");
}

TEST(Test, Test02) {
  Solution s;
  EXPECT_EQ(s.intToRoman(58), "LVIII");
}

TEST(Test, Test03) {
  Solution s;
  EXPECT_EQ(s.intToRoman(1994), "MCMXCIV");
}

