#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "solution.h"

using namespace std;

TEST(SolutionTest, Test01) {
  Solution s;
  EXPECT_EQ(s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
}

TEST(SolutionTest, Test02) {
  Solution s;
  EXPECT_EQ(s.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}

TEST(SolutionTest, Test03) {
  Solution s;
  EXPECT_EQ(s.convert("A", 1), "A");
}
