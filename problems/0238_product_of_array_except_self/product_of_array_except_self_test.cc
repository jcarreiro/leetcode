#include "product_of_array_except_self.h"
#include <gtest/gtest.h>

TEST(Test, Test01) {
  Solution s;
  vector<int> v{1, 2, 3, 4};
  ASSERT_EQ(s.productExceptSelf(v), vector<int>({24, 12, 8, 6}));
}

TEST(Test, Test02) {
  Solution s;
  vector<int> v{-1, 1, 0, -3, 3};
  ASSERT_EQ(s.productExceptSelf(v), vector<int>({0, 0, 9, 0, 0}));
}

TEST(Test, Test03) {
  Solution s;
  vector<int> v{0, 0};
  ASSERT_EQ(s.productExceptSelf(v), vector<int>({0, 0}));
}

