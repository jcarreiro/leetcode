// Copyright 2026 Jason M. Carreiro

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a string s, find the length of the longest substring without duplicate
 * characters.
 *
 * == Example 1 ==
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 * == Example 2 ==
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 * == Example 3 ==
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. Notice that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 * == Constraints ==
 * - 0 <= s.length <= 5 * 10^4
 * - s consists of English letters, digits, symbols and spaces.
 */
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> chars(128, -1);
    int maxLength = 0;
    int i = 0; // start of substring
    for (int j = 0; j < s.size(); j++) {
      const char c = s[j];

      // Have we already used this character?
      if (chars[c] >= i) {
        // Move the left pointer past the previous instance of the character.
        i = chars[c] + 1;
      }

      // Record the last index where we saw this character.
      chars[c] = j;

      // Update our max length with the length of the current substring.
      maxLength = max(maxLength, j - i + 1);
    }

    return maxLength;
  }
};
