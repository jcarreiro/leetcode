#include "maximum_depth_of_binary_tree.h"

#include <gtest/gtest.h>

#include "tree_node.h"

TEST(MaximumDepthOfBinaryTreeTest, Test01) {
  Solution s;
  auto root =
      make_tree(3, make_tree(9), make_tree(20, make_tree(15), make_tree(7)));
  EXPECT_EQ(s.maxDepth(root), 3);
}

TEST(MaximumDepthOfBinaryTreeTest, Test02) {
  Solution s;
  auto root = make_tree(1, nullptr, make_tree(2));
  EXPECT_EQ(s.maxDepth(root), 2);
}

TEST(MaximumDepthOfBinaryTreeTest, EmptyTree) {
  Solution s;
  auto root = nullptr;
  EXPECT_EQ(s.maxDepth(root), 0);
}

TEST(MaximumDepthOfBinaryTreeTest, SingleNodeTree) {
  Solution s;
  auto root = make_tree(1);
  EXPECT_EQ(s.maxDepth(root), 1);
}
