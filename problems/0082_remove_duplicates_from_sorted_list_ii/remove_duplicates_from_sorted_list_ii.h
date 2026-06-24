// Copyright 2026 Jason M. Carreiro.

#pragma once

#include "list_node.h"

using namespace std;

// # 82. Remove Duplicates from Sorted List II
//
// Difficulty: Medium
//
// Given the head of a sorted linked list, delete all nodes that have duplicate
// numbers, leaving only distinct numbers from the original list. Return the
// linked list sorted as well.
//
// ## Example 1
// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
//
// ## Example 2
// Input: head = [1,1,1,2,3]
// Output: [2,3]
//
// ## Constraints
// - The number of nodes in the list is in the range [0, 300].
// - -100 <= Node.val <= 100
// - The list is guaranteed to be sorted in ascending order.
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    ListNode* curr = head;
    while (curr != nullptr) {
      if (curr->next != nullptr && curr->val == curr->next->val) {
        // skip duplicates
        int val = curr->val;
        while (curr != nullptr && curr->val == val) {
          curr = curr->next;
        }
        prev->next = curr;
      } else {
        // curr node is not a duplicate
        prev = curr;
        curr = curr->next;
      }
    }
    return dummy.next;
  }
};
