#include "rotate_list.h"

#include <gtest/gtest.h>

#include "list_node.h"

TEST(RotateListTest, Test01) {
  Solution s;
  EXPECT_EQ(toVector(s.rotateRight(fromVector({1, 2, 3, 4, 5}), 2)),
            (vector<int>{4, 5, 1, 2, 3}));
}

TEST(RotateListTest, Test02) {
  Solution s;
  EXPECT_EQ(toVector(s.rotateRight(fromVector({0, 1, 2}), 4)),
            (vector<int>{2, 0, 1}));
}

TEST(RotateListTest, EmptyList) {
  Solution s;
  EXPECT_EQ(toVector(s.rotateRight(fromVector({}), 2)), (vector<int>{}));
}

TEST(RotateListTest, SingleElementList) {
  Solution s;
  EXPECT_EQ(toVector(s.rotateRight(fromVector({1}), 5)), (vector<int>{1}));
}
