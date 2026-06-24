#include "remove_nth_node_from_end_of_list.h"

#include <gtest/gtest.h>

#include "list_node.h"

TEST(RemoveNthNodeFromEndOfListTest, Test01) {
  Solution s;
  EXPECT_EQ(toVector(s.removeNthFromEnd(fromVector({1, 2, 3, 4, 5}), 2)),
            (vector<int>{1, 2, 3, 5}));
}

TEST(RemoveNthNodeFromEndOfListTest, Test02) {
  Solution s;
  EXPECT_EQ(toVector(s.removeNthFromEnd(fromVector({1}), 1)), (vector<int>{}));
}

TEST(RemoveNthNodeFromEndOfListTest, Test03) {
  Solution s;
  EXPECT_EQ(toVector(s.removeNthFromEnd(fromVector({1, 2}), 1)),
            (vector<int>{1}));
}