#include "partition_list.h"

#include <gtest/gtest.h>

#include "list_node.h"

TEST(PartitionListTest, Test01) {
  Solution s;
  EXPECT_EQ(toVector(s.partition(fromVector({1, 4, 3, 2, 5, 2}), 3)),
            (vector<int>{1, 2, 2, 4, 3, 5}));
}

TEST(PartitionListTest, Test02) {
  Solution s;
  EXPECT_EQ(toVector(s.partition(fromVector({2, 1}), 2)), (vector<int>{1, 2}));
}

TEST(PartitionListTest, EmptyList) {
  Solution s;
  EXPECT_EQ(toVector(s.partition(fromVector({}), 5)), (vector<int>{}));
}

TEST(PartitionListTest, SingleElementList) {
  Solution s;
  EXPECT_EQ(toVector(s.partition(fromVector({1}), 5)), (vector<int>{1}));
}
