#include <gtest/gtest.h>
#include <iostream>

using namespace std;

#define reverseWords reverseWordsFast

/*
 * Given an input string s, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a single space.
 *
 * Note that s may contain leading or trailing spaces or multiple spaces between
 * two words. The returned string should only have a single space separating the
 * words. Do not include any extra spaces.
 *
 *
 * == Example 1 ==
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 * == Example 2 ==
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 *
 * == Example 3 ==
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a single
 * space in the reversed string.
 *
 * == Constraints ==
 * - 1 <= s.length <= 104
 * - s contains English letters (upper-case and lower-case), digits, and spaces
 *   ' '.
 * - There is at least one word in s.
 *
 * TODO: reverseWordsInPlace currently takes about 4 ms on leetcode, which is
 * only enough to beat 28% of submissions; make it faster.
 */
class Solution {
 public:
  // In-place version, but requires two passes over the string:
  //
  // - in the first pass, we reverse the whole string
  //
  // - in the second pass, we reverse each word again while pushing extra spaces
  //   to the end of the string
  string reverseWordsInPlace(string s) {
    // Reverse the whole string.
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
      swap(s[i++], s[j--]);
    }

    // Reverse every word and remove extra spaces.
    i = 0;
    j = 0;
    int k = 0;
    while (i < s.size() ) {
      // Advance j until we hit a non-space.
      while (j < s.size() && s[j] == ' ') { j++; }

      // If we never found a non-space, then this is all trailing spaces at the
      // end of the buffer, and we're done.
      if (j == s.size()) {
        break;
      }

      // Keep track of how many leading spaces there were.
      k = j - k;

      // Advance j until we hit a space.
      while (j < s.size() && s[j] != ' ') { j++; }

      // If j ended up pointing to space, back up to the end of the word.
      if (j >= s.size() || s[j] == ' ') { j--; }

      // Update k to point to the first character we need to consider on the
      // next pass.
      k = j + 2 - k;

      // Swap s[i] and s[j] until i == j.
      while (i < j) {
        swap(s[i++], s[j--]);
      }

      // Advance to the next word.
      i = j = k;
    }

    i = min(i, static_cast<int>(s.size() - 1));

    // If there were any extra spaces, back up so they're not included in the
    // output.
    while (i > 0 && s[i] == ' ') { i--; }

    // We pushed all the extra spaces to the end, if there were any, so shrink
    // the string.
    s.resize(i + 1);
    return s;
  }

  // I tried using a stack -- slower than the above.
  string reverseWordsStack(string s) {
    stack<char> k;
    string t(s.size(), '\0');
    int i = s.size() - 1;
    int j = 0;
    while (i >= 0) {
      // If we hit a space, and the stack isn't empty, output the next word.
      if (s[i] == ' ' && !k.empty()) {
        while (!k.empty()) {
          const char c = k.top();
          k.pop();
          t[j++] = c;
        }
        t[j++] = ' ';
      } else if (s[i] != ' ') {
        k.push(s[i]);
      }
      i--;
    }

    // Output the last word.
    while (!k.empty()) {
      const char c = k.top();
      k.pop();
      t[j++] = c;
    }

    if (t[j - 1] == ' ') { j--; }

    t.resize(j);
    return t;
  }

  string reverseWordsFast(string s) {
    return s;
  }
};
