#include "remove_duplicates_from_sorted_list_ii.h"

#include <gtest/gtest.h>

#include "list_node.h"

TEST(RemoveDuplicatesFromSortedListIi, Test01) {
  Solution s;
  EXPECT_EQ(toVector(s.deleteDuplicates(fromVector({1, 2, 3, 3, 4, 4, 5}))),
            (vector<int>{1, 2, 5}));
}

TEST(RemoveDuplicatesFromSortedListIi, Test02) {
  Solution s;
  EXPECT_EQ(toVector(s.deleteDuplicates(fromVector({1, 1, 1, 2, 3}))),
            (vector<int>{2, 3}));
}

TEST(RemoveDuplicatesFromSortedListIi, AllDuplicates) {
  Solution s;
  EXPECT_EQ(toVector(s.deleteDuplicates(fromVector({1, 1, 1, 1, 1}))),
            (vector<int>{}));
}
