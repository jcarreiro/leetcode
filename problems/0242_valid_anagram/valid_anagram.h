// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <array>
#include <string>

using namespace std;

// # 242. Valid Anagram
//
// Difficulty: Easy
//
// Given two strings s and t, return true if t is an anagram of s, and false
// otherwise.
//
// ## Example 1
// Input: `s = "anagram", t = "nagaram"`
// Output: `true`
//
// ## Example 2
// Input: `s = "rat", t = "car"`
// Output: `false`
//
// ## Constraints
// - `1 <= s.length, t.length <= 5 * 10^4`
// - `s` and `t` consist of lowercase English letters.
//
// ## Follow up
// - What if the inputs contain Unicode characters? How would you adapt your
//   solution to such a case?
class Solution {
public:
  bool isAnagram(string s, string t) {
    // One string is an anagram of other if they have the same letter counts,
    // so we just check for that. Since we iterate over both strings and do a
    // constant amount of work at each step, this is O(n + m).
    //
    // This assumes the input consists of lower-case ASCII letters. To handle
    // Unicode input, we'd use a map from Unicode characters (however we want
    // to represent them, e.g. as a single int32) to counts, instead.
    if (s.length() != t.length()) {
      return false;
    }
    array<int, 26> a{};
    for (const auto& c : s) {
      a[c - 'a']++;
    }
    for (const auto& c : t) {
      if (a[c - 'a']-- == 0) {
        return false;
      }
    }
    return true;
  }
};
