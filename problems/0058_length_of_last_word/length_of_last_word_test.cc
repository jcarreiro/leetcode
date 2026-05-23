#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "length_of_last_word.h"

using namespace std;

TEST(Test, Test01) {
  Solution s;
  EXPECT_EQ(s.lengthOfLastWord("Hello World"), 5);
}

TEST(Test, Test02) {
  Solution s;
  EXPECT_EQ(s.lengthOfLastWord("   fly me   to   the moon  "), 4);
}

TEST(Test, Test03) {
  Solution s;
  EXPECT_EQ(s.lengthOfLastWord("luffy is still joyboy"), 6);
}

TEST(Test, Test04) {
  Solution s;
  EXPECT_EQ(s.lengthOfLastWord("a"), 1);
}

