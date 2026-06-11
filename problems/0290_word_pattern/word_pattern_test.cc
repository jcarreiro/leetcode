#include "word_pattern.h"
#include <gtest/gtest.h>

TEST(WordPatternTest, Test01) {
  Solution s;
  EXPECT_TRUE(s.wordPattern("abba", "dog cat cat dog"));
}

TEST(WordPatternTest, Test02) {
  Solution s;
  EXPECT_FALSE(s.wordPattern("abba", "dog cat cat fish"));
}

TEST(WordPatternTest, Test03) {
  Solution s;
  EXPECT_FALSE(s.wordPattern("aaaa", "dog cat cat dog"));
}

TEST(WordPatternTest, Test04) {
  Solution s;
  EXPECT_FALSE(s.wordPattern("aaa", "aa aa aa aa"));
}

TEST(WordPatternTest, Test05) {
  Solution s;
  EXPECT_FALSE(s.wordPattern("jquery", "jquery"));
}