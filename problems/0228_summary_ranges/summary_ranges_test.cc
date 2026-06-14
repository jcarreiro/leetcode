#include "summary_ranges.h"
#include <gtest/gtest.h>

TEST(SummaryRangesTest, Test01) {
  Solution s;
  vector<int> nums{{0, 1, 2, 4, 5, 7}};
  vector<string> expected{"0->2", "4->5", "7"};
  EXPECT_EQ(s.summaryRanges(nums), expected);
}

TEST(SummaryRangesTest, Test02) {
  Solution s;
  vector<int> nums{{0, 2, 3, 4, 6, 8, 9}};
  vector<string> expected{"0", "2->4", "6", "8->9"};
  EXPECT_EQ(s.summaryRanges(nums), expected);
}

TEST(SummaryRangesTest, Test03) {
  Solution s;
  vector<int> nums{{-2147483648, 0, 2, 3, 4, 6, 8, 9}};
  vector<string> expected{"-2147483648", "0", "2->4", "6", "8->9"};
  EXPECT_EQ(s.summaryRanges(nums), expected);
}