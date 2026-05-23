#include "include/test_utils.h"
#include "solution.h"
#include <gtest/gtest.h>

TEST(TwoSumTest, BasicExample) {
  Solution s;

  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  auto result = time_it([&] { return s.twoSum(nums, target); });

  EXPECT_EQ(result, (vector<int>{0, 1}));
}
