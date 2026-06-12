#include "contains_duplicate_ii.h"
#include <gtest/gtest.h>

TEST(ContainsDuplicateIiTest, Test01) {
  Solution s;
  vector<int> v{{1, 2, 3, 1}};
  EXPECT_TRUE(s.containsNearbyDuplicate(v, 3));
}

TEST(ContainsDuplicateIiTest, Test02) {
  Solution s;
  vector<int> v{{1, 0, 1, 1}};
  EXPECT_TRUE(s.containsNearbyDuplicate(v, 1));
}

TEST(ContainsDuplicateIiTest, Test03) {
  Solution s;
  vector<int> v{{1, 2, 3, 1, 2, 3}};
  EXPECT_FALSE(s.containsNearbyDuplicate(v, 2));
}
