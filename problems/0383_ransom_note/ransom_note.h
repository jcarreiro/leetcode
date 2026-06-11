// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <array>
#include <string>
#include <unordered_map>

using namespace std;

// # 383. Ransom Note
//
// Difficulty: Easy
//
// Given two strings ransomNote and magazine, return true if ransomNote can be
// constructed by using the letters from magazine and false otherwise.
//
// Each letter in magazine can only be used once in ransomNote.
//
// ## Example 1
// Input: `ransomNote = "a", magazine = "b"`
// Output: `false`
//
// ## Example 2
// Input: `ransomNote = "aa", magazine = "ab"`
// Output: `false`
//
// ## Example 3
// Input: `ransomNote = "aa", magazine = "aab"`
// Output: `true`
//
// ## Constraints
// - `1 <= ransomNote.length, magazine.length <= 10^5`
// - `ransomNote` and `magazine` consist of lowercase English letters
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    // Iterate over magazine, counting up the letters as we go. Then iterate
    // over ransomNote, decrementing the counts; if we ever hit a count of 0,
    // then the ransome note can't be constructed from the magazine. Since we
    // iterate over both strings and do a constant amount of work for each
    // letter, this has complexity O(n + m).
    array<int, 26> a{};
    for (const auto& c : magazine) {
      a[c - 'a']++;
    }

    for (const auto& c : ransomNote) {
      if (a[c - 'a']-- == 0) {
        return false;
      }
    }

    return true;
  }
};
