#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "solution.h"

using namespace std;

TEST(SolutionTest, Test01) {
  Solution s;
  EXPECT_EQ(s.intToRoman(3749), "MMMDCCXLIX");
}

TEST(SolutionTest, Test02) {
  Solution s;
  EXPECT_EQ(s.intToRoman(58), "LVIII");
}

TEST(SolutionTest, Test03) {
  Solution s;
  EXPECT_EQ(s.intToRoman(1994), "MCMXCIV");
}
