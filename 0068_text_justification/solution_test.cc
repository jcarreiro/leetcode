#include "solution.h"
#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>

using namespace std;

TEST(SolutionTest, Test01) {
  Solution s;
  vector<string> words{"This",          "is", "an", "example", "of", "text",
                       "justification."};
  // clang-format off
  vector<string> lines{
    "This    is    an",
    "example  of text",
    "justification.  "};
  // clang-format on
  EXPECT_EQ(s.fullJustify(words, 16), lines);
}

TEST(SolutionTest, Test02) {
  Solution s;
  vector<string> words{"What", "must", "be", "acknowledgment", "shall", "be"};
  // clang-format off
  vector<string> lines{
    "What   must   be",
    "acknowledgment  ",
    "shall be        "};
  // clang-format on
  EXPECT_EQ(s.fullJustify(words, 16), lines);
}

TEST(SolutionTest, Test03) {
  Solution s;
  vector<string> words{"Science", "is",        "what", "we",      "understand",
                       "well",    "enough",    "to",   "explain", "to",
                       "a",       "computer.", "Art",  "is",      "everything",
                       "else",    "we",        "do"};
  // clang-format off
  vector<string> lines{
    "Science  is  what we",
    "understand      well",
    "enough to explain to",
    "a  computer.  Art is",
    "everything  else  we",
    "do                  "};
  // clang-format on
  EXPECT_EQ(s.fullJustify(words, 20), lines);
}
