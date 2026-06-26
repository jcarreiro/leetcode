// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <algorithm>

#include "tree_node.h"

using namespace std;

// # 104. Maximum Depth of Binary Tree
//
// Difficulty: Easy
//
// Given the root of a binary tree, return its maximum depth.
//
// A binary tree's maximum depth is the number of nodes along the longest path
// from the root node down to the farthest leaf node.
//
// ## Example 1
// Input: root = [3,9,20,null,null,15,7]
// Output: 3
//
// ## Example 2
// Input: root = [1,null,2]
// Output: 2
//
// ## Constraints
// - The number of nodes in the tree is in the range [0, 10^4].
// - -100 <= Node.val <= 100
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    // This is a simple recursive solution.
    if (root == nullptr) {
      return 0;
    }
    return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
  }
};
