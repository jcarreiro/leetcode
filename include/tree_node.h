// Copyright (c) Jason M. Carreiro

#pragma once

// Common node object used by various binary tree problems.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

TreeNode* make_tree(int val, TreeNode* left = nullptr,
                    TreeNode* right = nullptr) {
  return new TreeNode(val, left, right);
}