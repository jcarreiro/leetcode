#include "group_anagrams.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

TEST(GroupAnagramsTest, Test01) {
  Solution s;
  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  EXPECT_THAT(s.groupAnagrams(strs),
              UnorderedElementsAre(UnorderedElementsAre("bat"),
                                   UnorderedElementsAre("nat", "tan"),
                                   UnorderedElementsAre("ate", "eat", "tea")));
}

TEST(GroupAnagramsTest, Test02) {
  Solution s;
  vector<string> strs{""};
  const vector<vector<string>> expected{{""}};
  EXPECT_EQ(s.groupAnagrams(strs), expected);
}

TEST(GroupAnagramsTest, Test03) {
  Solution s;
  vector<string> strs{"a"};
  const vector<vector<string>> expected{{"a"}};
  EXPECT_EQ(s.groupAnagrams(strs), expected);
}
