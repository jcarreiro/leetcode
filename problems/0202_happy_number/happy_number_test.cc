#include "happy_number.h"
#include <gtest/gtest.h>

TEST(HappyNumberTest, Test01) {
  Solution s;
  EXPECT_TRUE(s.isHappy(19));
}

TEST(HappyNumberTest, Test02) {
  Solution s;
  EXPECT_FALSE(s.isHappy(2));
}
