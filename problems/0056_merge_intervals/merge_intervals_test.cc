#include "merge_intervals.h"
#include <gtest/gtest.h>

TEST(MergeIntervalsTest, Test01) {
  Solution s;
  vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  const vector<vector<int>> expected{{1, 6}, {8, 10}, {15, 18}};
  EXPECT_EQ(s.merge(intervals), expected);
}

TEST(MergeIntervalsTest, Test02) {
  Solution s;
  vector<vector<int>> intervals{{1, 4}, {4, 5}};
  const vector<vector<int>> expected{{1, 5}};
  EXPECT_EQ(s.merge(intervals), expected);
}

TEST(MergeIntervalsTest, Test03) {
  Solution s;
  vector<vector<int>> intervals{{4, 7}, {1, 4}};
  const vector<vector<int>> expected{{1, 7}};
  EXPECT_EQ(s.merge(intervals), expected);
}