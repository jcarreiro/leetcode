#include "h_index.h"
#include <gtest/gtest.h>

TEST(Test, Test01) {
  Solution s;
  vector<int> citations{3, 0, 6, 1, 5};
  ASSERT_EQ(s.hIndex(citations), 3);
}

TEST(Test, Test02) {
  Solution s;
  vector<int> citations{1, 3, 1};
  ASSERT_EQ(s.hIndex(citations), 1);
}

TEST(Test, Test03) {
  Solution s;
  vector<int> citations{1};
  ASSERT_EQ(s.hIndex(citations), 1);
}

TEST(Test, Test04) {
  Solution s;
  vector<int> citations{3, 4, 1, 4, 3};
  ASSERT_EQ(s.hIndex(citations), 3);
}

TEST(Test, Test05) {
  Solution s;
  vector<int> citations{3, 4, 1, 1, 3};
  ASSERT_EQ(s.hIndex(citations), 3);
}

TEST(Test, Test06) {
  Solution s;
  vector<int> citations{0, 0, 2};
  ASSERT_EQ(s.hIndex(citations), 1);
}

TEST(Test, Test07) {
  Solution s;
  vector<int> citations{2, 1};
  ASSERT_EQ(s.hIndex(citations), 1);
}

TEST(Test, Test08) {
  Solution s;
  vector<int> citations{11, 15};
  ASSERT_EQ(s.hIndex(citations), 2);
}

