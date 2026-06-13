// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

// # 128. Longest Consecutive Sequence
//
// Difficulty: Medium
//
// Given an unsorted array of integers nums, return the length of the longest
// consecutive elements sequence.
//
// You must write an algorithm that runs in O(n) time.
//
// ## Example 1
// Input: `nums = [100,4,200,1,3,2]`
// Output: `4`
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.
//
// ## Example 2
// Input: `nums = [0,3,7,2,5,8,4,6,0,1]`
// Output: `9`
//
// ## Example 3
// Input: `nums = [1,0,1,2]`
// Output: `3`
//
// ## Constraints
// - `0 <= nums.length <= 10^5`
// - `-10^9 <= nums[i] <= 10^9`
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    return longestConsecutiveSort(nums);
  }

  int longestConsecutiveSet(vector<int>& nums) {
    // We build a set with all the values in nums, then we iterate over the
    // array, looking for the start of each sequence (as determined by the lack
    // of a predecessor element in the set). We can then use the set to count
    // the length of the sequence, by repeatedly checking for the successor of
    // the current value, until one isn't found, at which point we know the
    // length of the sequence. Since we iterate over each element twice and do
    // a constant amount of work each time, the complexity is O(n).
    //
    // Build a set with all the values from nums.
    unordered_set<int> s(nums.begin(), nums.end());

    // Find all the sequences in nums, starting from each unique value in the
    // array.
    int lcs = 0;
    for (auto n : s) {
      // To make sure we only visit each sequence once, we start from the least
      // element of each sequence. If the set contains the predecessor of the
      // current element, it's not the least element in a sequence, so we can
      // skip it.
      if (s.contains(n - 1)) {
        continue;
      }

      // This is the least element in some sequence; find the sequence length.
      int l = 1;
      while (s.contains(++n)) {
        l++;
      }

      // If we found a longer sequence, save the length.
      lcs = max(l, lcs);
    }

    return lcs;
  }

  int longestConsecutiveSort(vector<int>& nums) {
    // NB. The problem stipulates that the solution must be O(n), which would
    // normally rule out a comparison-based sort like std::sort() (which is
    // O(n lg n)), but in practice, the sort is faster for the problem sizes
    // which are used as test cases.
    if (nums.empty()) {
      return 0;
    }

    sort(nums.begin(), nums.end());
    int lcs = 1;
    int n = 1;
    for (int i = 0; i < nums.size() - 1; i++) {
      const auto& a = nums[i];
      const auto& b = nums[i + 1];
      if (b - a == 1) {
        // This is part of a sequence.
        n++;
      } else if (b == a) {
        // This is a duplicate, skip it.
        continue;
      } else {
        // The previous sequence ended, start a new one.
        n = 1;
      }
      lcs = max(lcs, n);
    }
    return lcs;
  }
};
