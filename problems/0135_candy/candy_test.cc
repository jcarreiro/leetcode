#include "candy.h"
#include <gtest/gtest.h>

TEST(CandyTest, Test01) {
  Solution s;
  vector<int> ratings{1, 0, 2};
  EXPECT_EQ(s.candy(ratings), 5);
}

TEST(CandyTest, Test02) {
  Solution s;
  vector<int> ratings{1, 2, 2};
  EXPECT_EQ(s.candy(ratings), 4);
}

TEST(CandyTest, Test03) {
  Solution s;
  vector<int> ratings{1, 2, 2, 2, 1};
  EXPECT_EQ(s.candy(ratings), 7);
}

TEST(CandyTest, Test04) {
  Solution s;
  vector<int> ratings{1, 2, 87, 87, 87, 2, 1};
  EXPECT_EQ(s.candy(ratings), 13);
}

TEST(CandyTest, Test05) {
  Solution s;
  vector<int> ratings{1, 2, 87, 87, 87, 1};
  EXPECT_EQ(s.candy(ratings), 10);
}

TEST(CandyTest, Test06) {
  Solution s;
  vector<int> ratings{1, 3, 2, 2, 1};
  EXPECT_EQ(s.candy(ratings), 7);
}

TEST(CandyTest, Test07) {
  Solution s;
  vector<int> ratings{5, 3, 7, 3};
  EXPECT_EQ(s.candy(ratings), 6);
}



