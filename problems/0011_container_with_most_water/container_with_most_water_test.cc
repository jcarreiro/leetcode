#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "container_with_most_water.h"

using namespace std;

TEST(ContainerWithMostWaterTest, Test01) {
  Solution s;
  vector<int> height{1,8,6,2,5,4,8,3,7};
  EXPECT_EQ(s.maxArea(height), 49);
}

TEST(ContainerWithMostWaterTest, Test02) {
  Solution s;
  vector<int> height{1,1};
  EXPECT_EQ(s.maxArea(height), 1);
}



