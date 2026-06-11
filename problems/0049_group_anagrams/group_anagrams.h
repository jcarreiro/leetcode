// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// # 49. Group Anagrams
//
// Difficulty: Medium
//
// Given an array of strings strs, group the anagrams together. You can return
// the answer in any order.
//
// ## Example 1
// Input: `strs = ["eat","tea","tan","ate","nat","bat"]`
// Output: `[["bat"],["nat","tan"],["ate","eat","tea"]]`
//
// ### Explanation
// - There is no string in strs that can be rearranged to form "bat".
// - The strings "nat" and "tan" are anagrams as they can be rearranged to form
//   each other.
// - The strings "ate", "eat", and "tea" are anagrams as they can be rearranged
//   to form each other.
//
// ## Example 2
// Input: `strs = [""]`
// Output: `[[""]]`
//
// ## Example 3
// Input: `strs = ["a"]`
// Output: `[["a"]]`
//
// Constraints
// - `1 <= strs.length <= 10^4`
// - `0 <= strs[i].length <= 100`
// - `strs[i]` consists of lowercase English letters.
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // The easiest way to do this is to sort each string, then insert the string
    // into a map with the sorted version as the key. Since all anagrams will
    // sort to the same key, this will group them all. Sorting is log-linear in
    // general, so if there are n strings, each of length m, then the complexity
    // of this solution is O(n * m log m), if we assume the hash operations take
    // constant time.
    unordered_map<string, vector<string>> m;
    for (auto& s : strs) {
      auto key = s;
      sort(key.begin(), key.end());
      m[key].push_back(std::move(s));
    }

    vector<vector<string>> rv;
    for (auto& [k, v] : m) {
      rv.push_back(move(v));
    }

    return rv;
  }
};
