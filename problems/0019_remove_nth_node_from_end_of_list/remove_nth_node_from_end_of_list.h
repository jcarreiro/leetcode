// Copyright 2026 Jason M. Carreiro.

#pragma once

#include "list_node.h"

using namespace std;

// 19. Remove Nth Node From End of List
//
// Difficulty: Medium
//
// Given the head of a linked list, remove the nth node from the end of the list
// and return its head.
//
// ## Example 1
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
//
// ## Example 2
// Input: head = [1], n = 1
// Output: []
//
// ## Example 3
// Input: head = [1,2], n = 1
// Output: [1]
//
// ## Constraints
// - The number of nodes in the list is sz.
// - 1 <= sz <= 30
// - 0 <= Node.val <= 100
// - 1 <= n <= sz
//
// ## Follow up
// Could you do this in one pass?
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Advance fast n + 1 steps ahead of slow. Note that the problem constraints
    // guarantee that n <= sz, so this should always be possible (in the worst
    // case, we should just hit the end of the list).
    ListNode dummy(0, head);
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;
    for (int i = 0; i <= n; i++) {
      fast = fast->next;
    }

    // Now advance both pointers until the fast pointer hits the end of the
    // list.
    while (fast != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    // The slow pointer should now be pointing at the node before the node to
    // remove.
    slow->next = slow->next->next;
    return dummy.next;
  }
};
