// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <array>
#include <string>
#include <unordered_map>

using namespace std;

// # 290. Word Pattern
//
// Difficulty: Easy
//
// Given a pattern and a string s, find if s follows the same pattern.
//
// Here follow means a full match, such that there is a bijection between a
// letter in pattern and a non-empty word in s. Specifically:
//
// - Each letter in pattern maps to exactly one unique word in s.
// - Each unique word in s maps to exactly one letter in pattern.
// - No two letters map to the same word, and no two words map to the same
//   letter.
//
// ## Example 1
// Input: `pattern = "abba", s = "dog cat cat dog"`
// Output: `true`
//
// ### Explanation
// The bijection can be established as:
// - 'a' maps to "dog".
// - 'b' maps to "cat".
//
// ## Example 2
// Input: `pattern = "abba", s = "dog cat cat fish"`
// Output: `false`
//
// ## Example 3
// Input: `pattern = "aaaa", s = "dog cat cat dog"`
// Output: `false`
//
// ## Constraints
// - `1 <= pattern.length <= 300`
// - `pattern` contains only lower-case English letters.
// - `1 <= s.length <= 3000`
// - `s` contains only lowercase English letters and spaces `' '`.
// - `s` does not contain any leading or trailing spaces.
// - All the words in `s` are separated by a single space.
class Solution {
public:
  bool wordPattern(string pattern, string s) {
    // Iterate over the letters in pattern, and the words in s, building a map
    // from letter -> word. For each letter, there are two cases:
    //
    // - If the letter and word aren't already mapped, then we can create a new
    //   mapping from the letter -> word.
    //
    // - If either the letter or word are already mapped, then they must be
    //   mapped to each other, otherwise s does not follow the pattern.
    array<string, 26> lm{};         // letter -> word ('a' -> "dog")
    unordered_map<string, char> wm; // word -> letter ("dog" -> 'a')
    int i = 0;                      // pos in pattern
    int j = 0;                      // pos in s
    while (i < pattern.length() && j < s.length()) {
      const auto& letter = pattern[i++];
      const int idx = letter - 'a';
      // get the next word
      int tmp = j;
      while (tmp < s.length() && s[tmp] != ' ') {
        tmp++;
      }
      const auto& word = s.substr(j, tmp - j);
      if (tmp < s.length()) {
        j = ++tmp;
      } else {
        j = tmp;
      }

      const auto& p = wm.insert({word, letter});
      if (lm[idx].empty() && p.second) {
        lm[idx] = word;
      } else if (lm[idx] != word || wm[word] != letter) {
        return false;
      }
    }
    // If didn't use the whole pattern, or we have any extra words, then this
    // pattern wasn't a full match.
    return i == pattern.length() && j == s.length();
  }
};
