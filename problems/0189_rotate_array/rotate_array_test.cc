#include "rotate_array.h"
#include <gtest/gtest.h>

TEST(Solution, Basic) {
  Solution s;
  auto r = s.mod(-1, 7);
  ASSERT_EQ(r, 6);

  r = s.mod(1, 7);
  ASSERT_EQ(r, 1);

  vector<int> v{1, 2, 3, 4, 5, 6, 7};
  s.rotate(v, 1);
  ASSERT_EQ(v, vector<int>({7, 1, 2, 3, 4, 5, 6}));

  v = {7, 1, 2, 3, 4, 5, 6};
  s.rotate(v, -1);
  ASSERT_EQ(v, vector<int>({1, 2, 3, 4, 5, 6, 7}));

  v = {1, 2, 3, 4, 5, 6, 7};
  s.rotate(v, 2);
  ASSERT_EQ(v, vector<int>({6, 7, 1, 2, 3, 4, 5}));

  v = {6, 7, 1, 2, 3, 4, 5};
  s.rotate(v, -2);
  ASSERT_EQ(v, vector<int>({1, 2, 3, 4, 5, 6, 7}));

  v = {-1, -100, 3, 99};
  s.rotate(v, 2);
  ASSERT_EQ(v, vector<int>({3, 99, -1, -100}));

  v = {-1, -100, 3, 99};
  s.rotate(v, -2);
  ASSERT_EQ(v, vector<int>({3, 99, -1, -100}));

  v = {1, 2, 3, 4, 5, 6};
  s.rotate(v, 4);
  ASSERT_EQ(v, vector<int>({3, 4, 5, 6, 1, 2}));

  v = {};
  ASSERT_NO_THROW(s.rotate(v, 1));

  v = {1};
  s.rotate(v, 5);
  ASSERT_EQ(v, vector<int>({1}));

  v = {1};
  s.rotate(v, 0);
  ASSERT_EQ(v, vector<int>({1}));
}

