#include "zigzag_conversion.h"
#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>

using namespace std;

TEST(ZigzagConversionTest, Test01) {
  Solution s;
  EXPECT_EQ(s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
}

TEST(ZigzagConversionTest, Test02) {
  Solution s;
  EXPECT_EQ(s.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}

TEST(ZigzagConversionTest, Test03) {
  Solution s;
  EXPECT_EQ(s.convert("A", 1), "A");
}




