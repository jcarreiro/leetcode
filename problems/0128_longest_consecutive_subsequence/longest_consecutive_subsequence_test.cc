#include "longest_consecutive_subsequence.h"
#include <gtest/gtest.h>

TEST(LongestConsecutiveSubsequenceTest, Test01) {
  Solution s;
  vector<int> nums{100, 4, 200, 1, 3, 2};
  EXPECT_EQ(s.longestConsecutive(nums), 4);
}

TEST(LongestConsecutiveSubsequenceTest, Test02) {
  Solution s;
  vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  EXPECT_EQ(s.longestConsecutive(nums), 9);
}

TEST(LongestConsecutiveSubsequenceTest, Test03) {
  Solution s;
  vector<int> nums{1, 0, 1, 2};
  EXPECT_EQ(s.longestConsecutive(nums), 3);
}

TEST(LongestConsecutiveSubsequenceTest, TestEmptyNums) {
  Solution s;
  vector<int> nums;
  EXPECT_EQ(s.longestConsecutive(nums), 0);
}
