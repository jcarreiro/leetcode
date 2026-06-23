#include "reverse_nodes_in_k_group.h"

#include <gtest/gtest.h>

#include "list_node.h"

TEST(ReverseNodesInKGroupTest, Test01) {
  Solution s;
  EXPECT_EQ(toVector(s.reverseKGroup(fromVector({1, 2, 3, 4, 5}), 2)),
            (vector<int>({2, 1, 4, 3, 5})));
}

TEST(ReverseNodesInKGroupTest, Test02) {
  Solution s;
  EXPECT_EQ(toVector(s.reverseKGroup(fromVector({1, 2, 3, 4, 5}), 3)),
            (vector<int>({3, 2, 1, 4, 5})));
}

TEST(ReverseNodesInKGroupTest, ListLengthIsMultipleOfK) {
  Solution s;
  EXPECT_EQ(toVector(s.reverseKGroup(fromVector({1, 2, 3, 4}), 2)),
            (vector<int>({2, 1, 4, 3})));
}