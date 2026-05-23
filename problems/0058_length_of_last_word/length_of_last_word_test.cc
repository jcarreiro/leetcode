#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "length_of_last_word.h"

using namespace std;

TEST(LengthOfLastWordTest, Test01) {
  Solution s;
  EXPECT_EQ(s.lengthOfLastWord("Hello World"), 5);
}

TEST(LengthOfLastWordTest, Test02) {
  Solution s;
  EXPECT_EQ(s.lengthOfLastWord("   fly me   to   the moon  "), 4);
}

TEST(LengthOfLastWordTest, Test03) {
  Solution s;
  EXPECT_EQ(s.lengthOfLastWord("luffy is still joyboy"), 6);
}

TEST(LengthOfLastWordTest, Test04) {
  Solution s;
  EXPECT_EQ(s.lengthOfLastWord("a"), 1);
}



