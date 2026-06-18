// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <vector>

// Common node object used by various linked list problems.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

inline ListNode* fromVector(const std::vector<int>& vals) {
  ListNode dummy(0);
  ListNode* tail = &dummy;
  for (int v : vals) {
    tail->next = new ListNode(v);
    tail = tail->next;
  }
  return dummy.next;
}

inline std::vector<int> toVector(ListNode* node) {
  std::vector<int> result;
  while (node != nullptr) {
    result.push_back(node->val);
    node = node->next;
  }
  return result;
}