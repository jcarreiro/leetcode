// Copyright 2026 Jason M. Carreiro.

#pragma once

#include "list_node.h"

using namespace std;

// # 25. Reverse Nodes in k-Group
//
// Difficulty: Hard
//
// Given the head of a linked list, reverse the nodes of the list k at a time,
// and return the modified list.
//
// k is a positive integer and is less than or equal to the length of the linked
// list. If the number of nodes is not a multiple of k then left-out nodes, in
// the end, should remain as it is.
//
// You may not alter the values in the list's nodes, only nodes themselves may
// be changed.
//
// ## Example 1
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
//
// ## Example 2
// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
//
// ## Constraints
// - The number of nodes in the list is n.
// - 1 <= k <= n <= 5000
// - 0 <= Node.val <= 1000
//
// ## Follow-up
// Can you solve the problem in O(1) extra memory space?
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    // Iterate over the list, checking to see if we have a group of k nodes.
    // If so, reverse the group, then link up the tail of the previous group
    // to the new head node.
    ListNode dummy(0, head);
    auto prevTail = &dummy;
    while (true) {
      // Find the end of the next group.
      auto curr = prevTail;
      for (int i = 0; i < k; i++) {
        curr = curr->next;
        if (curr == nullptr) {
          // This isn't a full group, so we're done.
          return dummy.next;
        }
      }

      // Reverse the group.
      auto groupStart = prevTail->next;
      // Start with prev pointing to the next node after the group. This handles
      // the case where the remaining nodes don't make a full group, since the
      // tail of the reversed group will already be pointing to the correct
      // node (the head of the remaining list), since we "reverse it to point
      // at prev in the loop below.
      auto prev = curr->next;
      curr = groupStart;
      for (int i = 0; i < k; i++) {
        auto next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }

      prevTail->next = prev;
      prevTail = groupStart;
    }
  }
};
