#include "add_two_numbers.h"

#include <gtest/gtest.h>

#include "list_node.h"

TEST(AddTwoNumbersTest, Test01) {
  Solution s;
  auto l1 = fromVector({2, 4, 3});
  auto l2 = fromVector({5, 6, 4});
  EXPECT_EQ(toVector(s.addTwoNumbers(l1, l2)), (vector<int>{7, 0, 8}));
}

TEST(AddTwoNumbersTest, Test02) {
  Solution s;
  auto l1 = fromVector({0});
  auto l2 = fromVector({0});
  EXPECT_EQ(toVector(s.addTwoNumbers(l1, l2)), (vector<int>{0}));
}

TEST(AddTwoNumbersTest, Test03) {
  Solution s;
  auto l1 = fromVector({9, 9, 9, 9, 9, 9, 9});
  auto l2 = fromVector({9, 9, 9, 9});
  EXPECT_EQ(toVector(s.addTwoNumbers(l1, l2)),
            (vector<int>{8, 9, 9, 9, 0, 0, 0, 1}));
}
