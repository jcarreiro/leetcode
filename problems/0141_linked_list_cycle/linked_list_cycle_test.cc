#include "linked_list_cycle.h"

#include <gtest/gtest.h>

ListNode* makeNode(int val, ListNode* next = nullptr) {
  auto n = new ListNode(val);
  n->next = next;
  return n;
}

TEST(LinkedListCycleTest, Test01) {
  Solution s;
  auto tail = makeNode(-4);
  auto head = makeNode(3, makeNode(2, makeNode(0, tail)));
  // Make the tail loop back to the second node (index 1):
  //
  //   3 -> 2 -> 0 -> -4 -+
  //        ^             |
  //        |             |
  //        +-------------+
  tail->next = head->next;
  EXPECT_TRUE(s.hasCycle(head));
}

TEST(LinkedListCycleTest, Test02) {
  Solution s;
  auto tail = makeNode(2);
  auto head = makeNode(1, tail);
  // Make the tail loop back to the head:
  //
  //   1 -> 2
  //   ^    |
  //   |    |
  //   +----+
  tail->next = head;
  EXPECT_TRUE(s.hasCycle(head));
}

TEST(LinkedListCycleTest, Test03) {
  Solution s;
  auto head = makeNode(1);
  EXPECT_FALSE(s.hasCycle(head));
}