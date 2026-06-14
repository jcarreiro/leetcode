// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <format>
#include <string>
#include <vector>

using namespace std;

// # 228. Summary Ranges
//
// Difficulty: Easy
//
// You are given a sorted unique integer array nums.
//
// A range [a,b] is the set of all integers from a to b (inclusive).
//
// Return the smallest sorted list of ranges that cover all the numbers in the
// array exactly. That is, each element of nums is covered by exactly one of the
// ranges, and there is no integer x such that x is in one of the ranges but not
// in nums.
//
// Each range [a,b] in the list should be output as:
//
// - `"a->b"` if `a != b`
// - `"a"` if `a == b`
//
// ## Example 1
// Input: `nums = [0,1,2,4,5,7]`
// Output: `[C]`
// Explanation: The ranges are:
// [0,2] --> "0->2"
// [4,5] --> "4->5"
// [7,7] --> "7"
//
// ## Example 2
// Input: `nums = [0,2,3,4,6,8,9]`
// Output: `["0","2->4","6","8->9"]`
// Explanation: The ranges are:
// [0,0] --> "0"
// [2,4] --> "2->4"
// [6,6] --> "6"
// [8,9] --> "8->9"
//
// Constraints:
// - `0 <= nums.length <= 20`
// - `-2^31 <= nums[i] <= 2^31 - 1`
// - All the values of `nums` are unique.
// - `nums` is sorted in ascending order.
class Solution {
public:
  string formatRange(int a, int b) {
    if (a == b) {
      return format("{}", a);
    }
    return format("{}->{}", a, b);
  }

  vector<string> summaryRanges(vector<int>& nums) {
    // Iterate over the array, maintaining a current range start and range end.
    // If the next element is more than one greater than the current element,
    // then the current element is the end of a range (which may be a range of
    // one element, if it's also the start). Since we visit each element once
    // and do a constant amount of work per element, this runs in O(n) time.
    if (nums.empty()) {
      return {};
    }

    vector<string> ranges;
    int i = 0;
    int rangeStart = 0; // range start index
    for (; i < nums.size() - 1; i++) {
      // If the next element is too big, then this is the end of a range (since
      // we don't want to cover integers not in the array). Note that the result
      // of this subtraction could overflow; to avoid that, we do it using a
      // wider type (int64_t).
      const auto d =
          static_cast<int64_t>(nums[i + 1]) - static_cast<int64_t>(nums[i]);
      if (d > 1) {
        // This is the end of a range.
        ranges.push_back(std::move(formatRange(nums[rangeStart], nums[i])));

        // The new range start is the next element in the list.
        rangeStart = i + 1;
      }
    }

    // Handle the end of the last range.
    ranges.push_back(std::move(formatRange(nums[rangeStart], nums[i])));
    return ranges;
  }
};
