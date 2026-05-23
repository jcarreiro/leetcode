#include "3sum.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;
using namespace ::testing;

TEST(Test, Test01) {
  Solution s;
  vector<int> nums{-1, 0, 1, 2, -1, -4};
  EXPECT_THAT(s.threeSum(nums),
              UnorderedElementsAre(UnorderedElementsAre(-1, -1, 2),
                                   UnorderedElementsAre(-1, 0, 1)));
}

TEST(Test, Test02) {
  Solution s;
  vector<int> nums{0, 1, 1};
  EXPECT_EQ(s.threeSum(nums), vector<vector<int>>());
}

TEST(Test, Test03) {
  Solution s;
  vector<int> nums{0, 0, 0};
  EXPECT_THAT(s.threeSum(nums),
              UnorderedElementsAre(UnorderedElementsAre(0, 0, 0)));
}

TEST(Test, Test04) {
  Solution s;
  vector<int> nums{-2, -1, 0, 1, 2};
  EXPECT_THAT(s.threeSum(nums),
              UnorderedElementsAre(UnorderedElementsAre(-2, 0, 2),
                                   UnorderedElementsAre(-1, 0, 1)));
}

TEST(Test, Test05) {
  Solution s;
  vector<int> nums{-2, 0, 1, 1, 2};
  EXPECT_THAT(s.threeSum(nums),
              UnorderedElementsAre(UnorderedElementsAre(-2, 0, 2),
                                   UnorderedElementsAre(-2, 1, 1)));
}

TEST(Test, Test06) {
  Solution s;
  //  i           j
  // --------------
  //  0  1  2 3 4 5
  // -2 -1 -1 1 1 2
  vector<int> nums{-2, -1, -1, 1, 1, 2};
  EXPECT_THAT(s.threeSum(nums),
              UnorderedElementsAre(UnorderedElementsAre(-2, 1, 1),
                                   UnorderedElementsAre(2, -1, -1)));
}

TEST(Test, Test07) {
  Solution s;
  //  i           j
  // --------------
  //  0  1  2 3 4 5
  // -2 -1 -1 1 1 2
  vector<int> nums{-6, -5, -3, -3, 3, 3, 5, 6};
  EXPECT_THAT(s.threeSum(nums),
              UnorderedElementsAre(UnorderedElementsAre(-6, 3, 3),
                                   UnorderedElementsAre(6, -3, -3)));
}

TEST(Test, Test08) {
  Solution s;
  vector<int> nums{2, -3, 0, -2, -5, -5, -4, 1, 2, -2, 2, 0, 2, -4, 5, 5, -10};
  EXPECT_THAT(
      s.threeSum(nums),
      UnorderedElementsAre(
          UnorderedElementsAre(-10, 5, 5), UnorderedElementsAre(-5, 0, 5),
          UnorderedElementsAre(-4, 2, 2), UnorderedElementsAre(-3, -2, 5),
          UnorderedElementsAre(-3, 1, 2), UnorderedElementsAre(-2, 0, 2)));
}

TEST(Test, Test09) {
  Solution s;
  vector<int> nums{3, 0, 3, 2, -4, 0, -3, 2, 2, 0, -1, -5};
  EXPECT_THAT(s.threeSum(nums),
              ElementsAre(ElementsAre(-5, 2, 3), ElementsAre(-4, 2, 2),
                          ElementsAre(-3, 0, 3), ElementsAre(0, 0, 0)));
}

