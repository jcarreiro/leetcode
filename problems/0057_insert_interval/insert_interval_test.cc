#include "insert_interval.h"
#include <gtest/gtest.h>

TEST(InsertIntervalTest, Test01) {
  Solution s;
  vector<vector<int>> intervals{{1, 3}, {6, 9}};
  vector<int> newInterval{{2, 5}};
  const vector<vector<int>> expected{{1, 5}, {6, 9}};
  EXPECT_EQ(s.insert(intervals, newInterval), expected);
}

TEST(InsertIntervalTest, Test02) {
  Solution s;
  vector<vector<int>> intervals{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval{{4, 8}};
  const vector<vector<int>> expected{{1, 2}, {3, 10}, {12, 16}};
  EXPECT_EQ(s.insert(intervals, newInterval), expected);
}
