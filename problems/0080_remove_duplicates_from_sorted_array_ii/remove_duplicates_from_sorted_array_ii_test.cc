#include "remove_duplicates_from_sorted_array_ii.h"
#include <gtest/gtest.h>

TEST(RemoveDuplicatesFromSortedArrayIiTest, shortArray) {
  Solution s;
  vector<int> v{1};
  auto k = s.removeDuplicates(v);
  ASSERT_EQ(k, 1);
  v.resize(k);
  ASSERT_EQ(v, vector<int>({1}));
}

TEST(RemoveDuplicatesFromSortedArrayIiTest, longArray) {
  Solution s;
  vector<int> v{1, 1, 1, 2, 2, 3};
  auto k = s.removeDuplicates(v);
  ASSERT_EQ(k, 5);
  v.resize(k);
  ASSERT_EQ(v, vector<int>({1, 1, 2, 2, 3}));
}



