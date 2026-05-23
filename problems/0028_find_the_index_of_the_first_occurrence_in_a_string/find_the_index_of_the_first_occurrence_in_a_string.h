#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/*
 * Given two strings needle and haystack, return the index of the first
 * occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 * == Example 1 ==
 * Input: haystack = "sadbutsad", needle = "sad"
 * Output: 0
 * Explanation: "sad" occurs at index 0 and 6.
 * The first occurrence is at index 0, so we return 0.
 *
 * == Example 2 ==
 * Input: haystack = "leetcode", needle = "leeto"
 * Output: -1
 * Explanation: "leeto" did not occur in "leetcode", so we return -1.
 *
 * == Constraints ==
 * - 1 <= haystack.length, needle.length <= 104
 * - haystack and needle consist of only lowercase English characters.
 */
class Solution {
 public:
  int strStr(string haystack, string needle) {
    // I mean, we could just use string::find, but that seems like cheating? So
    // we'll implement the KMP algorithm from scratch.
    int i = 0;
    int j = 0;
    int k = 0;
    const auto& t = kmpTable(needle);
    while (j < haystack.length()) {
      if (needle[k] == haystack[j]) {
        // This is a match for the next character in the pattern, so keep going.
        j++;
        k++;
        if (k == needle.length()) {
          // We found an instance of the pattern. Since we only want the first
          // occurrence, we can return it now; if we want all of the positions
          // of the pattern, we can save the current match start position and
          // continue matching, using the failure table to check where to resume
          // matching in the pattern.
          return j - k;
        }
      } else {
        // This character doesn't match; check the failure table to see where
        // to resume matching in the pattern.
        k = t[k];
        if (k < 0) {
          // We didn't match any of the pattern, so start matching again from
          // the start of the pattern at the next input character.
          j++;
          k++;
        }
      }
    }

    // We didn't find a match.
    return -1;
  }

 private:
  vector<int> kmpTable(const std::string& w) {
    int pos = 1;
    int cnd = 0;
    vector<int> t(w.length() + 1);

    // If we mismatch at the first character in the pattern, we can't do any
    // backtracking, so we set t[0] to -1 as a special case.
    t[0] = -1;

    while (pos < w.length()) {
      // Does the character at this position in the pattern match the current
      // candidate? In that case, we have a proper suffix which is also a
      // prefix, so we can 'skip ahead' a number of characters equal to the
      // length of the suffix and then resume matching.
      if (w[pos] == w[cnd]) {
        t[pos] = t[cnd];
      } else {
        // ...
        t[pos] = cnd;
        while (cnd >= 0 && w[pos] != w[cnd]) {
          cnd = t[cnd];
        }
      }

      pos++;
      cnd++;
    }

    t[pos] = cnd;
    return t;
  }
};
