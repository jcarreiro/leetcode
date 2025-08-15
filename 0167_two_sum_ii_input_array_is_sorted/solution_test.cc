#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "solution.h"

using namespace std;

TEST(SolutionTest, Test01) {
  Solution s;
  vector<int> numbers{2, 7, 11, 15};
  vector<int> indices{1, 2};
  EXPECT_EQ(s.twoSum(numbers, 9), indices);
}

TEST(SolutionTest, Test02) {
  Solution s;
  vector<int> numbers{2, 3, 4};
  vector<int> indices{1, 3};
  EXPECT_EQ(s.twoSum(numbers, 6), indices);
}

TEST(SolutionTest, Test03) {
  Solution s;
  vector<int> numbers{-1, 0};
  vector<int> indices{1, 2};
  EXPECT_EQ(s.twoSum(numbers, -1), indices);
}
