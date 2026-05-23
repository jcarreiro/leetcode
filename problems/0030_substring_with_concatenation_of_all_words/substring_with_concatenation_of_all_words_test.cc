#include "substring_with_concatenation_of_all_words.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;
using namespace ::testing;

TEST(Test, Test01) {
  Solution s;
  vector<string> words{"foo", "bar"};
  vector<int> expected{0, 9};
  EXPECT_EQ(s.findSubstring("barfoothefoobarman", words), expected);
}

TEST(Test, Test02) {
  Solution s;
  vector<string> words{"word", "good", "best", "word"};
  vector<int> expected{};
  EXPECT_EQ(s.findSubstring("wordgoodgoodgoodbestword", words), expected);
}

TEST(Test, Test03) {
  Solution s;
  vector<string> words{"bar", "foo", "the"};
  vector<int> expected{6, 9, 12};
  EXPECT_EQ(s.findSubstring("barfoofoobarthefoobarman", words), expected);
}

TEST(Test, Test04) {
  Solution s;
  vector<string> words{"aa", "aa"};
  vector<int> expected{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(s.findSubstring("aaaaaaaaaaaaaa", words), expected);
}

TEST(Test, Test05) {
  Solution s;
  vector<string> words{"ab","ba","ba"};
  vector<int> expected{1};
  EXPECT_EQ(s.findSubstring("ababaab", words), expected);
}

