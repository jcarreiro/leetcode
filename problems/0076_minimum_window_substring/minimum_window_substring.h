// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <cassert>
#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>

using namespace std;

// Given two strings s and t of lengths m and n respectively, return the minimum
// window substring of s such that every character in t (including duplicates)
// is included in the window. If there is no such substring, return the empty
// string "".
//
// The testcases will be generated such that the answer is unique.
//
// == Example 1 ==
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
// from string t.
//
// == Example 2 ==
// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
//
// == Example 3 ==
// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a' s from t must be included in the window. Since the
// largest window of s only has one 'a', return empty string.
//
// == Constraints ==
// - m == s.length
// - n == t.length
// - 1 <= m
// - n <= 10^5
// - s and t consist of uppercase and lowercase English letters.
//
// == Follow up ==
// Could you find an algorithm that runs in O(m + n) time?
class Solution {
public:
  string minWindow(string s, string t) {
    // Set up our hash table to track the characters we need to find.
    unordered_map<char, int> h;
    for (const auto& c : t) {
      auto it = h.find(c);
      if (it != h.end()) {
        it->second++;
      } else {
        h[c] = 1;
      }
    }

    // Loop over the string. For each character, we look up the character in our
    // hash table; if the character is in the table, then we decrement the count
    // needed (if we are adding the character to our window) or increment it (if
    // we are removing it).
    size_t start = 0;
    size_t neededCount = t.length();
    optional<size_t> bestStart;
    optional<size_t> bestEnd;
    for (size_t end = 0; end < s.length(); end++) {
      // Look up the next character in our hash table.
      const auto c = s[end];
      cout << "Got character: " << c << endl;

      // There are a few possible cases to handle here:
      //
      // - If the window isn't full (it doesn't have all the characters we need)
      //   then we need to grow it.
      //
      // - If the window is full, we may be able to improve our solution by
      //   shrinking it.
      //
      // First, add the new character to our window.
      auto it = h.find(c);
      if (it != h.end()) {
        if (it->second-- > 0) {
          neededCount--;
        }
        cout << "Found " << c << ", need " << it->second << " more, "
             << "neededCount = " << neededCount << "." << endl;
      }

      // If the window is full, try to shrink it. We can shrink it if (1) the
      // left-most character isn't in our search set or (2) the left-most
      // character is in our search set, but we still have enough copies of
      // the character left in the window after removing it.
      while (neededCount == 0 && start <= end) {
        const auto c = s[start];
        auto it = h.find(c);
        if (it == h.end()) {
          // We don't need this character.
          start++;
          cout << "Removed unneeded character " << c << " from window, new "
               << "window is (" << start << ", " << end << ")." << endl;
          continue;
        }

        // This is a character we need; can we remove it?
        if (it->second < 0) {
          // We have more copies then we need, so we can remove this character
          // from the window.
          it->second++;
          start++;
          cout << "Removed unneeded character " << c << " from window, new "
               << "window is (" << start << ", " << end
               << "), updated character count is " << it->second << "." << endl;
          continue;
        }

        // If we get here, then this is a character that we need, so we can't
        // shrink further.
        break;
      }

      // If the window is full, and it's smaller then the current best window,
      // the update the best solution found.
      if (neededCount == 0) {
        const auto winSize = end - start + 1;
        if (bestStart.has_value()) {
          assert(bestEnd.has_value());
          const auto bestSize = bestEnd.value() - bestStart.value() + 1;
          if (winSize < bestSize) {
            bestStart = start;
            bestEnd = end;
            cout << "New best window (" << start << ", " << end << ") has size "
                 << winSize << "." << endl;
          }
        } else {
          // This is the first solution we've found.
          bestStart = start;
          bestEnd = end;
          cout << "New best window (" << start << ", " << end << ") has size "
               << winSize << "." << endl;
        }
      }
    }

    if (bestStart.has_value()) {
      assert(bestEnd.has_value());
      const auto winSize = bestEnd.value() - bestStart.value() + 1;
      return s.substr(bestStart.value(), winSize);
    }

    // No substring contained all the characters.
    return "";
  }
};
