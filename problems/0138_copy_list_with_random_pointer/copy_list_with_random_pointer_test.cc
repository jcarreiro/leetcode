#include "copy_list_with_random_pointer.h"

#include <gtest/gtest.h>

Node* fromVector(vector<int> vals, vector<optional<size_t>> randoms) {
  Node dummy(0);
  Node* tail = &dummy;
  vector<Node*> index;
  index.reserve(vals.size());
  for (const auto& v : vals) {
    Node* node = new Node(v);
    index.push_back(node);
    tail->next = node;
    tail = tail->next;
  }
  tail = dummy.next;
  for (const auto& r : randoms) {
    if (r) {
      tail->random = index[r.value()];
    }
    tail = tail->next;
  }
  return dummy.next;
}

unordered_map<Node*, size_t> buildIndex(Node* l) {
  unordered_map<Node*, size_t> m;
  size_t i = 0;
  while (l != nullptr) {
    m[l] = i++;
    l = l->next;
  }
  return m;
}

bool randomListsEqual(Node* a, Node* b) {
  auto indexA = buildIndex(a);
  auto indexB = buildIndex(b);
  while (a != nullptr && b != nullptr) {
    if (a->val != b->val || indexA[a->random] != indexB[b->random]) {
      return false;
    }
    a = a->next;
    b = b->next;
  }
  return a == nullptr && b == nullptr;
}

TEST(CopyListWithRandomPointerTest, Test01) {
  Solution s;
  auto head = fromVector({7, 13, 11, 10, 1}, {nullopt, 0, 4, 2, 0});
  EXPECT_PRED2(randomListsEqual, s.copyRandomList(head), head);
}

TEST(CopyListWithRandomPointerTest, Test02) {
  Solution s;
  auto head = fromVector({1, 2}, {1, 1});
  EXPECT_PRED2(randomListsEqual, s.copyRandomList(head), head);
}

TEST(CopyListWithRandomPointerTest, Test03) {
  Solution s;
  auto head = fromVector({3, 3, 3}, {nullopt, 0, nullopt});
  EXPECT_PRED2(randomListsEqual, s.copyRandomList(head), head);
}
