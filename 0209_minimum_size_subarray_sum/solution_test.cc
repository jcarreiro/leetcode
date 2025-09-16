#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "solution.h"

using namespace std;

TEST(SolutionTest, Test01) {
  Solution s;
  vector<int> nums{2, 3, 1, 2, 4, 3};
  EXPECT_EQ(s.minSubArrayLen(7, nums), 2);
}

TEST(SolutionTest, Test02) {
  Solution s;
  vector<int> nums{1, 4, 4};
  EXPECT_EQ(s.minSubArrayLen(4, nums), 1);
}

TEST(SolutionTest, Test03) {
  Solution s;
  vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(s.minSubArrayLen(11, nums), 0);
}

TEST(SolutionTest, Test04) {
  Solution s;
  vector<int> nums{10, 2, 3};
  EXPECT_EQ(s.minSubArrayLen(6, nums), 1);
}
