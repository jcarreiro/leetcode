#include "simplify_path.h"
#include <gtest/gtest.h>

TEST(SimplifyPathTest, Test01) {
  Solution s;
  EXPECT_EQ(s.simplifyPath("/home/"), "/home");
}

TEST(SimplifyPathTest, Test02) {
  Solution s;
  EXPECT_EQ(s.simplifyPath("/home//foo/"), "/home/foo");
}

TEST(SimplifyPathTest, Test03) {
  Solution s;
  EXPECT_EQ(s.simplifyPath("/home/user/Documents/../Pictures"),
            "/home/user/Pictures");
}

TEST(SimplifyPathTest, Test04) {
  Solution s;
  EXPECT_EQ(s.simplifyPath("/../"), "/");
}

TEST(SimplifyPathTest, Test05) {
  Solution s;
  EXPECT_EQ(s.simplifyPath("/.../a/../b/c/../d/./"), "/.../b/d");
}
