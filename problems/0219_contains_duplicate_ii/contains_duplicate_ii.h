// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <unordered_map>
#include <vector>

using namespace std;

// # 219. Contains Duplicate II
//
// Difficulty: Easy
//
// Given an integer array nums and an integer k, return true if there are two
// distinct indices i and j in the array such that nums[i] == nums[j] and
// abs(i - j) <= k.
//
// ## Example 1
// Input: `nums = [1,2,3,1], k = 3`
// Output: `true`
//
// ## Example 2
// Input: `nums = [1,0,1,1], k = 1`
// Output: `true`
//
// ## Example 3
// Input: `nums = [1,2,3,1,2,3], k = 2`
// Output: `false`
//
// ## Constraints
// - `1 <= nums.length <= 10^5`
// `-10^9 <= nums[i] <= 10^9`
// - `0 <= k <= 10^5`
class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // Iterate over the array, inserting each element into a hashtable with the
    // value as the key and the index as the value. If the element is already in
    // the table, then we may have a duplicate within the window, which we can
    // check using the stored index. Otherwise we just insert the element. Since
    // we do a constant amount of work for each element, this solution is O(n).
    //
    // NB. Some solutions on leetcode use a stack-allocated hashtable, which is
    // slightly faster since it avoids any dynamic allocations.
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      const auto& p = m.insert({nums[i], i});
      if (!p.second) {
        if (i - p.first->second <= k) {
          return true;
        }
        p.first->second = i;
      }
    }

    // If we get here, we never found a duplicate value in the window.
    return false;
  }
};
