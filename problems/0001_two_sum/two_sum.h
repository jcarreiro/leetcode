// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

// # 1. Two Sum
//
// Difficulty: Easy
//
// Given an array of integers nums and an integer target, return indices of the
// two numbers such that they add up to target.
//
// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.
//
// You can return the answer in any order.
//
// ## Example 1
// Input: `nums = [2,7,11,15], target = 9`
// Output: `[0,1]`
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
//
// ## Example 2
// Input: `nums = [3,2,4], target = 6`
// Output: `[1,2]`
//
// ## Example 3
// `Input: nums = [3,3], target = 6`
// Output: `[0,1]`
//
// ## Constraints
// - `2 <= nums.length <= 10^4`
// `-10^9 <= nums[i] <= 10^9`
// `-10^9 <= target <= 10^9`
// - Only one valid answer exists.
//
// ## Follow-up
// - Can you come up with an algorithm that is less than O(n2) time complexity?
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // We build a hashmap, where the key is (target - e) for each element, e,
    // and the value is the index of the element (since the constraints
    // guarantee a unique solution, we assume uniqueness and do not handle
    // duplicates; if the same number shows up again later in the iteration,
    // we can just skip it). Since we iterate over the list twice and do a
    // constant amount of work for each element, this has O(n) complexity.
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      // If we fail to insert, that's fine -- it just means we already have the
      // complement of this number.
      m.insert({target - nums[i], i});
    }

    for (int i = 0; i < nums.size(); i++) {
      const auto& it = m.find(nums[i]);
      if (it != m.end() && it->second != i) {
        return {i, it->second};
      }
    }

    // The problem states there will always be a unique solution, so we should
    // never get here.
    assert(0);
    return {};
  }
};
