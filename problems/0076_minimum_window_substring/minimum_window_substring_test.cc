#include "minimum_window_substring.h"
#include "test_utils.h"
#include <gtest/gtest.h>

TEST(MinimumWindowSubstringTest, Test01) {
  Solution s;
  auto result = s.minWindow("ADOBECODEBANC", "ABC");
  EXPECT_EQ(result, "BANC");
}

TEST(MinimumWindowSubstringTest, Test02) {
  Solution s;
  auto result = s.minWindow("a", "a");
  EXPECT_EQ(result, "a");
}

TEST(MinimumWindowSubstringTest, Test03) {
  Solution s;
  auto result = s.minWindow("a", "aa");
  EXPECT_EQ(result, "");
}

TEST(MinimumWindowSubstringTest, Test04) {
  Solution s;
  auto result = s.minWindow("abc", "b");
  EXPECT_EQ(result, "b");
}
