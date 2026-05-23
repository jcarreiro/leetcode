#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>
#include "find_the_index_of_the_first_occurrence_in_a_string.h"

using namespace std;

TEST(Test, Test01) {
  Solution s;
  EXPECT_EQ(s.strStr("sadbutsad", "sad"), 0);
}

TEST(Test, Test02) {
  Solution s;
  EXPECT_EQ(s.strStr("leetcode", "leeto"), -1);
}

