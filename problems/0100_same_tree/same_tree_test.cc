#include "same_tree.h"

#include <gtest/gtest.h>

#include "tree_node.h"

TEST(SameTreeTest, Test01) {
  Solution s;
  EXPECT_TRUE(s.isSameTree(make_tree(1, make_tree(2), make_tree(3)),
                           make_tree(1, make_tree(2), make_tree(3))));
}

TEST(SameTreeTest, Test02) {
  Solution s;
  EXPECT_FALSE(s.isSameTree(make_tree(1, make_tree(2)),
                            make_tree(1, nullptr, make_tree(2))));
}

TEST(SameTreeTest, Test03) {
  Solution s;
  EXPECT_FALSE(s.isSameTree(make_tree(1, make_tree(2), make_tree(1)),
                            make_tree(1, make_tree(1), make_tree(2))));
}

TEST(SameTreeTest, EmptyTree) {
  Solution s;
  EXPECT_TRUE(s.isSameTree(nullptr, nullptr));
  EXPECT_FALSE(s.isSameTree(make_tree(1), nullptr));
  EXPECT_FALSE(s.isSameTree(nullptr, make_tree(1)));
}

TEST(SameTreeTest, SingleNodeTree) {
  Solution s;
  EXPECT_TRUE(s.isSameTree(make_tree(1), make_tree(1)));
  EXPECT_FALSE(s.isSameTree(make_tree(1), make_tree(2)));
}
