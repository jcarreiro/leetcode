#include "minimum_number_of_arrows_to_burst_balloons.h"
#include <gtest/gtest.h>

TEST(MinimumNumberOfArrowsToBurstBalloonsTest, Test01) {
  Solution s;
  vector<vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  EXPECT_EQ(s.findMinArrowShots(points), 2);
}

TEST(MinimumNumberOfArrowsToBurstBalloonsTest, Test02) {
  Solution s;
  vector<vector<int>> points{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  EXPECT_EQ(s.findMinArrowShots(points), 4);
}

TEST(MinimumNumberOfArrowsToBurstBalloonsTest, Test03) {
  Solution s;
  vector<vector<int>> points{{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  EXPECT_EQ(s.findMinArrowShots(points), 2);
}
