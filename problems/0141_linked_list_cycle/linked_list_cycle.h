// Copyright 2026 Jason M. Carreiro.

#pragma once

using namespace std;

// # 141. Linked List Cycle
//
// Difficulty: Easy
//
// Given head, the head of a linked list, determine if the linked list has a
// cycle in it.
//
// There is a cycle in a linked list if there is some node in the list that can
// be reached again by continuously following the next pointer. Internally, pos
// is used to denote the index of the node that tail's next pointer is connected
// to. Note that pos is not passed as a parameter.
//
// Return true if there is a cycle in the linked list. Otherwise, return false.
//
// [The input in the examples below is a bit unclear; the pos value should be
// read as the next pointer for the tail of the list. So any value other than
// -1 indicates a cycle. Note that pos is not an actual input to the solution.
// --jmc]
//
// ## Example 1
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to
// the 1st node (0-indexed).
//
// ## Example 2
// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to
// the 0th node.
//
// ## Example 3
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.
//
// ## Constraints
// - The number of the nodes in the list is in the range [0, 10^4].
// - -10^5 <= Node.val <= 10^5
// - pos is -1 or a valid index in the linked-list.
//
// ## Follow up
// Can you solve it using O(1) (i.e. constant) memory?

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  bool hasCycle(ListNode* head) {
    // We apply an old trick here: if a list has a cycle, then two pointers
    // iterating it at different speeds must eventually meet, as long as the
    // difference in speeds is coprime to the cycle length (Floyd's algorithm).
    // The easy way to ensure this is to make the difference in speeds 1. Since
    // we use only a constant amount of additional space, this has O(1) space
    // complexity, and since we iterate the list once (in the worst case, we
    // need to traverse the entire cycle before the pointers meet) this solution
    // has O(n) time complexity.
    ListNode* hare = head;
    ListNode* tortise = head;
    while (hare != nullptr && hare->next != nullptr) {
      tortise = tortise->next;
      hare = hare->next->next;
      if (tortise == hare) {
        return true;
      }
    }
    return false;
  }
};