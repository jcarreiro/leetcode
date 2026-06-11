#include "isomorphic_strings.h"
#include <gtest/gtest.h>

TEST(IsomorphicStringsTest, Test01) {
  Solution s;
  EXPECT_TRUE(s.isIsomorphic("egg", "add"));
}

TEST(IsomorphicStringsTest, Test02) {
  Solution s;
  EXPECT_FALSE(s.isIsomorphic("f11", "b23"));
}

TEST(IsomorphicStringsTest, Test03) {
  Solution s;
  EXPECT_TRUE(s.isIsomorphic("paper", "title"));
}

TEST(IsomorphicStringsTest, Test04) {
  Solution s;
  EXPECT_FALSE(s.isIsomorphic("badc", "baba"));
}
