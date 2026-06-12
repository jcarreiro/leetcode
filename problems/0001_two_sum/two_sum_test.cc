#include "two_sum.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

TEST(TwoSumTest, Test01) {
  Solution s;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  EXPECT_THAT(s.twoSum(nums, target), UnorderedElementsAre(0, 1));
}

TEST(TwoSumTest, Test02) {
  Solution s;
  vector<int> nums = {3, 2, 4};
  int target = 6;
  EXPECT_THAT(s.twoSum(nums, target), UnorderedElementsAre(1, 2));
}

TEST(TwoSumTest, Test03) {
  Solution s;
  vector<int> nums = {3, 3};
  int target = 6;
  EXPECT_THAT(s.twoSum(nums, target), UnorderedElementsAre(0, 1));
}
