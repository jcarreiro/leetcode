// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <array>
#include <string>

using namespace std;

// # 205. Isomorphic Strings
//
// Difficulty: Easy
//
// Given two strings s and t, determine if they are isomorphic.
//
// Two strings s and t are isomorphic if the characters in s can be replaced to
// get t.
//
// All occurrences of a character must be replaced with another character while
// preserving the order of characters. No two characters may map to the same
// character, but a character may map to itself.
//
// ## Example 1
// Input: `s = "egg", t = "add"`
// Output: `true`
//
// ### Explanation
// The strings s and t can be made identical by:
// - Mapping 'e' to 'a'.
// - Mapping 'g' to 'd'.
//
// ## Example 2
// Input: `s = "f11", t = "b23"`
// Output: `false`
//
// ### Explanation
// The strings s and t can not be made identical as '1' needs to be mapped to
// both '2' and '3'.
//
// ## Example 3
// Input: `s = "paper", t = "title"`
// Output: `true`
//
// ## Constraints
// - `1 <= s.length <= 5 * 10^4`
// - `t.length == s.length`
// - `s` and `t` consist of any valid ascii character
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    // Iterate over s and t, checking that each character in s maps to a valid
    // character in t. There are two cases:
    //
    // - If the characters in s and t haven't been used yet, we can map the
    //   current character in s to that character in t.
    //
    // - If either character has already been used, and they don't map to each
    //   other, than the strings are not isomorphic.
    array<char, 128> a; // s -> t
    array<char, 128> b; // t -> s
    a.fill(-1);         // not a valid ASCII character
    b.fill(-1);
    for (int i = 0; i < s.length(); i++) {
      const auto& c = s[i];
      const auto& d = t[i];
      if (a[c] == -1 && b[d] == -1) {
        a[c] = d;
        b[d] = c;
      } else if (a[c] != d || b[d] != c) {
        return false;
      }
    }

    return true;
  }
};
