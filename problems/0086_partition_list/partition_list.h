// Copyright 2026 Jason M. Carreiro.

#pragma once

#include "list_node.h"

using namespace std;

// # 86. Partition List
//
// Difficulty: Medium
//
// Given the head of a linked list and a value x, partition it such that all
// nodes less than x come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the
// two partitions.
//
// ## Example 1
// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]
//
// ## Example 2
// Input: head = [2,1], x = 2
// Output: [1,2]
//
// ## Constraints
// - The number of nodes in the list is in the range [0, 200].
// - -100 <= Node.val <= 100
// - -200 <= x <= 200
class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    // We just collect the nodes into two lists: one for the nodes less than x,
    // the other for the nodes greater than or equal to x, then splice them back
    // together into a single list. Easy.
    ListNode ltDummy(0);
    ListNode geqDummy(0);
    ListNode* lt = &ltDummy;
    ListNode* geq = &geqDummy;
    while (head != nullptr) {
      if (head->val < x) {
        lt->next = head;
        lt = lt->next;
      } else {
        geq->next = head;
        geq = geq->next;
      }
      head = head->next;
    }
    lt->next = geqDummy.next;
    geq->next = nullptr;
    return ltDummy.next;
  }
};
