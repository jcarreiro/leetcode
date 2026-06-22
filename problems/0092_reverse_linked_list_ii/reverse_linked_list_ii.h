// Copyright 2026 Jason M. Carreiro.

#pragma once

#include "list_node.h"

using namespace std;

// # 92. Reverse Linked List II
//
// Medium
//
// Given the head of a singly linked list and two integers left and right where
// left <= right, reverse the nodes of the list from position left to position
// right, and return the reversed list.
//
// ## Example 1
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
//
// ## Example 2
// Input: head = [5], left = 1, right = 1
// Output: [5]
//
// ## Constraints
// - The number of nodes in the list is n.
// - 1 <= n <= 500
// - -500 <= Node.val <= 500
// - 1 <= left <= right <= n
//
// ## Follow up
// Could you do it in one pass?
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // Traverse to the start index, then reverse until we reach the end index.
    // Finally link up the the tail of the left side to the head of the reversed
    // part of the list, and the tail of the reversed part to the head of the
    // right side.
    //
    // NB. Based on the examples, left and right are 1-indexed, not 0-indexed.
    //
    // Find the tail of the left side, before the reversed section, if any.
    if (left == right) {
      // no work to do
      return head;
    }

    // Prepend a dummy so there's always at least one node on the left side of
    // the reversed part of the list; simplifies the code below.
    ListNode dummy(0, head);
    ListNode* leftTail = &dummy;
    for (int i = 1; i < left; i++) {
      leftTail = leftTail->next;
    }

    // Reverse the middle section of the list.
    ListNode* reversedTail = leftTail->next;
    ListNode* curr = reversedTail;
    ListNode* prev = nullptr;
    for (int i = left; i <= right; i++) {
      const auto next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    // Connect the left side tail to the head of the reversed part, and the tail
    // of the reversed part to the head of the right side. Note that after the
    // loop above, prev points to the head of the reversed part, and curr points
    // to the head of the right side.
    leftTail->next = prev;
    reversedTail->next = curr;
    return dummy.next;
  }
};
