#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "solution.h"

using namespace std;

TEST(SolutionTest, Test01) {
  Solution s;
  vector<int> height{1,8,6,2,5,4,8,3,7};
  EXPECT_EQ(s.maxArea(height), 49);
}

TEST(SolutionTest, Test02) {
  Solution s;
  vector<int> height{1,1};
  EXPECT_EQ(s.maxArea(height), 1);
}
