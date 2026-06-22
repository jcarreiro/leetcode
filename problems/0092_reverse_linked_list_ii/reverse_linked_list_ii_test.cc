#include "reverse_linked_list_ii.h"

#include <gtest/gtest.h>

#include "list_node.h"

TEST(ReverseLinkedListIiTest, Test01) {
  Solution s;
  EXPECT_EQ(toVector(s.reverseBetween(fromVector({1, 2, 3, 4, 5}), 2, 4)),
            (vector<int>{1, 4, 3, 2, 5}));
}

TEST(ReverseLinkedListIiTest, Test02) {
  Solution s;
  EXPECT_EQ(toVector(s.reverseBetween(fromVector({5}), 1, 1)),
            (vector<int>{5}));
}

TEST(ReverseLinkedListIiTest, ReverseEnd) {
  Solution s;
  EXPECT_EQ(toVector(s.reverseBetween(fromVector({1, 2, 3}), 2, 3)),
            (vector<int>{1, 3, 2}));
}