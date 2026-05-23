#include "longest_substring_without_repeating_characters.h"
#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>

using namespace std;

TEST(LongestSubstringWithoutRepeatingCharactersTest, Test01) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(LongestSubstringWithoutRepeatingCharactersTest, Test02) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
}

TEST(LongestSubstringWithoutRepeatingCharactersTest, Test03) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(LongestSubstringWithoutRepeatingCharactersTest, Test04) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring(" "), 1);
}

TEST(LongestSubstringWithoutRepeatingCharactersTest, Test05) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring("abba"), 2);
}

