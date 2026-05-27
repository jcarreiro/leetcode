#include "substring_with_concatenation_of_all_words.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;
using namespace ::testing;

TEST(SubstringWithConcatenationOfAllWordsTest, Test01) {
  Solution s;
  vector<string> words{"foo", "bar"};
  EXPECT_THAT(s.findSubstring("barfoothefoobarman", words),
              UnorderedElementsAre(0, 9));
}

TEST(SubstringWithConcatenationOfAllWordsTest, Test02) {
  Solution s;
  vector<string> words{"word", "good", "best", "word"};
  EXPECT_THAT(s.findSubstring("wordgoodgoodgoodbestword", words), IsEmpty());
}

TEST(SubstringWithConcatenationOfAllWordsTest, Test03) {
  Solution s;
  vector<string> words{"bar", "foo", "the"};
  EXPECT_THAT(s.findSubstring("barfoofoobarthefoobarman", words),
              UnorderedElementsAre(6, 9, 12));
}

TEST(SubstringWithConcatenationOfAllWordsTest, Test04) {
  Solution s;
  vector<string> words{"aa", "aa"};
  EXPECT_THAT(s.findSubstring("aaaaaaaaaaaaaa", words),
              UnorderedElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
}

TEST(SubstringWithConcatenationOfAllWordsTest, Test05) {
  Solution s;
  vector<string> words{"ab", "ba", "ba"};
  EXPECT_THAT(s.findSubstring("ababaab", words), UnorderedElementsAre(1));
}
