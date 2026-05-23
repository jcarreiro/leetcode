#include <gtest/gtest.h>
#include <optional>
#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    // In this problem, we are given an array of integers, where each element
    // indicates how far we can "jump" to the right from that position in the
    // array. Our goal is to return true iif we can reach the end of the array
    // through a series of "jumps".
    //
    // First, observe that we can only get stuck if we encounter a 0 that we
    // can't "jump over". Since we have the entire array as input, we can
    // simply work backwards, scanning from any 0 we encounter to see if we
    // find an element before it that would let us "jump over" it. Second,
    // note that the value is the _maximum_ jump length. Since we can choose
    // to jump less than the maximum, all we need to do is get past the 0;
    // once we're on the other side, we can use any run of positive elements
    // to set ourselves up for the next "jump". (If this wasn't the case -- if
    // the value repesented a fixed step, not a maximum -- then the problem
    // becomes significantly harder, since we have to find a path through the
    // graph; even if we find a value big enough to let us step over a 0, we
    // could land in a part of the graph where there are no paths that connect
    // us to the end.)
    assert(nums.size() > 0);

    // If the first element is a 0, or the array only has a single element in
    // it, we don't need to check anything else.
    if (nums.size() == 1) {
      return true;
    }

    if (nums[0] == 0) {
      return false;
    }

    optional<size_t> nz; // index of last 0 seen
    // Note that we never need to consider the last element, since its our
    // target (it doesn't matter if it's a zero, since we never need to jump
    // over it).
    for (int i = nums.size() - 2; i >= 0; i--) {
      // If we have a zero, does this value let us jump over it?
      if (nz.has_value()) {
        // How far do we need to jump?
        const auto d = nz.value() - i;
        if (nums[i] > d) {
          // We can jump past this zero.
          nz = nullopt;
        }
        // If we couldn't jump over this zero, keep looking for a large
        // enough element.
      } else if (nums[i] == 0) {
        // This is the next 0 we'll need to jump over.
        nz = i;
      }
    }

    // If we get here with a non-empty nz, then we found a zero we couldn't
    // jump over.
    return !nz.has_value();
  }
};
