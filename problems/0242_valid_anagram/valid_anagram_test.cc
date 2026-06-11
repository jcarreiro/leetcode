#include "valid_anagram.h"
#include <gtest/gtest.h>

TEST(ValidAnagramTest, Test01) {
  Solution s;
  EXPECT_TRUE(s.isAnagram("anagram", "nagaram"));
}

TEST(ValidAnagramTest, Test02) {
  Solution s;
  EXPECT_FALSE(s.isAnagram("rat", "car"));
}

TEST(ValidAnagramTest, Test03) {
  Solution s;
  EXPECT_FALSE(s.isAnagram("ab", "a"));
}

TEST(ValidAnagramTest, Test04) {
  Solution s;
  EXPECT_FALSE(s.isAnagram("a", "ab"));
}
