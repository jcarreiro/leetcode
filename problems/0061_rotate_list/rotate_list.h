// Copyright 2026 Jason M. Carreiro.

#pragma once

#include "list_node.h"

using namespace std;

// # 61. Rotate List
//
// Difficulty: Medium
//
// Given the head of a linked list, rotate the list to the right by k places.
//
// ## Example 1
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
//
// ## Example 2
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
//
// ## Constraints
// - The number of nodes in the list is in the range [0, 500].
// - -100 <= Node.val <= 100
// - 0 <= k <= 2 * 10^9
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) {
      return head;
    }

    // First make the list circular, and count the length while we're at it.
    int n = 1;
    ListNode* tail = head;
    while (tail->next != nullptr) {
      n++;
      tail = tail->next;
    }
    tail->next = head;

    // Now go "back" k steps from the tail. Of course we can't go backwards, but
    // since the list is circular, we can go fowards (n - k) mod n steps and end
    // up in the same place.
    auto stepCount = (n - (k % n)) % n;
    for (int i = 0; i < stepCount; i++) {
      tail = tail->next;
    }

    head = tail->next;
    tail->next = nullptr;
    return head;
  }
};
