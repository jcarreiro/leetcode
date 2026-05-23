#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "reverse_words_in_string.h"

using namespace std;

TEST(ReverseWordsInStringTest, Test01) {
  Solution sln;
  string s{"the sky is blue"};
  EXPECT_EQ(sln.reverseWords(s), "blue is sky the");
}

TEST(ReverseWordsInStringTest, Test02) {
  Solution sln;
  string s{"  hello world  "};
  EXPECT_EQ(sln.reverseWords(s), "world hello");
}

TEST(ReverseWordsInStringTest, Test03) {
  Solution sln;
  string s{"a good   example"};
  EXPECT_EQ(sln.reverseWords(s), "example good a");
}

TEST(ReverseWordsInStringTest, Test04) {
  Solution sln;
  string s{"  the  sky  is  blue  "};
  EXPECT_EQ(sln.reverseWords(s), "blue is sky the");
}

TEST(ReverseWordsInStringTest, Test05) {
  Solution sln;
  string s{" asdasd df f"};
  EXPECT_EQ(sln.reverseWords(s), "f df asdasd");
}



