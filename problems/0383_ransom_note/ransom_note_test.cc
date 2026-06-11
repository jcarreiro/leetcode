#include "ransom_note.h"
#include <gtest/gtest.h>

TEST(RansomeNoteTest, Test01) {
  Solution s;
  EXPECT_FALSE(s.canConstruct("a", "b"));
}

TEST(RansomeNoteTest, Test02) {
  Solution s;
  EXPECT_FALSE(s.canConstruct("aa", "ab"));
}

TEST(RansomeNoteTest, Test03) {
  Solution s;
  EXPECT_TRUE(s.canConstruct("aa", "aab"));
}
