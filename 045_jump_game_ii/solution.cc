#include <optional>
#include <limits>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    assert(nums.size() < std::numeric_limits<int>::max());

    // Originally I wanted to track the cost per-space, but we can do better! If
    // we can already reach space N in X moves, then no later element of the
    // array can ever do _better_ than X moves to reach the same space. So we
    // can track the boundary between the reachable and unreachable elements,
    // given the jump distances seen so far, and we only need to increment our
    // cost when we move past the boundary.
    size_t cost = 0;
    size_t j = 0; // current boundary
    size_t k = 0; // next boundary
    for (auto i = 0; i < nums.size() && j < nums.size() - 1; i++) {
      // According the problem definition, this should never happen (since we
      // can always reach the end of the array) so we can assert on it here.
      assert(i <= j);

      // If we've hit the boundary, bump the cost (this was as far as we could
      // have moved from the original position we started in, when we set the
      // boundary) and update our current boundary with the next one (which is
      // tracking how far we could have moved if we stopped on any of the spaces
      // we've seen so far, including this one).
      //
      // Could we jump further from this space?
      k = std::min(
        std::max(static_cast<int>(k), i + nums[i]),
        static_cast<int>(nums.size() - 1));
      if (i == j) {
        j = k;
        cost++;
      }
    }
    return cost;
  }
};

TEST(Solution, Example01) {
  Solution s;
  vector<int> v{2,3,1,1,4};
  EXPECT_EQ(s.jump(v), 2);
}

TEST(Solution, Example02) {
  Solution s;
  vector<int> v{2,3,0,1,4};
  EXPECT_EQ(s.jump(v), 2);
}

TEST(Solution, Test01) {
  Solution s;
  vector<int> v{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
  EXPECT_EQ(s.jump(v), 2);
}
