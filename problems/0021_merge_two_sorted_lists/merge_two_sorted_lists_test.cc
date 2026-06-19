#include "merge_two_sorted_lists.h"

#include <gtest/gtest.h>

#include "list_node.h"

TEST(MergeTwoSortedListsTest, Test01) {
  Solution s;
  EXPECT_EQ(
      toVector(s.mergeTwoLists(fromVector({1, 2, 4}), fromVector({1, 3, 4}))),
      (vector<int>{1, 1, 2, 3, 4, 4}));
}

TEST(MergeTwoSortedListsTest, Test02) {
  Solution s;
  EXPECT_EQ(toVector(s.mergeTwoLists(fromVector({}), fromVector({}))),
            (vector<int>{}));
}

TEST(MergeTwoSortedListsTest, Test03) {
  Solution s;
  EXPECT_EQ(toVector(s.mergeTwoLists(fromVector({}), fromVector({0}))),
            (vector<int>{0}));
}
