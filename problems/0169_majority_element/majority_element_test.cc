#include "majority_element.h"
#include <gtest/gtest.h>

TEST(MajorityElement, Basic) {
  Solution s;
  vector<int> v{1, 1, 1};
  auto m = s.majorityElement(v);
  ASSERT_EQ(m, 1);

  v = {1, 2, 2, 2, 1};
  m = s.majorityElement(v);
  ASSERT_EQ(m, 2);

  v = {3, 2, 3};
  m = s.majorityElement(v);
  ASSERT_EQ(m, 3);
}

