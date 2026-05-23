#include "trapping_rain_water.h"
#include <gtest/gtest.h>

TEST(TrappingRainWaterTest, Test01) {
  Solution s;
  vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  EXPECT_EQ(s.trap(height), 6);
}

TEST(TrappingRainWaterTest, Test02) {
  Solution s;
  vector<int> height{4, 2, 0, 3, 2, 5};
  EXPECT_EQ(s.trap(height), 9);
}



