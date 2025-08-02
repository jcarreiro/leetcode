#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "solution.h"

using namespace std;

TEST(SolutionTest, Test01) {
  Solution sln;
  string s{"the sky is blue"};
  EXPECT_EQ(sln.reverseWords(s), "blue is sky the");
}

TEST(SolutionTest, Test02) {
  Solution sln;
  string s{"  hello world  "};
  EXPECT_EQ(sln.reverseWords(s), "world hello");
}

TEST(SolutionTest, Test03) {
  Solution sln;
  string s{"a good   example"};
  EXPECT_EQ(sln.reverseWords(s), "example good a");
}

TEST(SolutionTest, Test04) {
  Solution sln;
  string s{"  the  sky  is  blue  "};
  EXPECT_EQ(sln.reverseWords(s), "blue is sky the");
}

TEST(SolutionTest, Test05) {
  Solution sln;
  string s{" asdasd df f"};
  EXPECT_EQ(sln.reverseWords(s), "f df asdasd");
}
