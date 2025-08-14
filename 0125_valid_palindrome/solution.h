#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/*
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 * == Example 1 ==
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 * == Example 2 ==
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 *
 * == Example 3 ==
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric
 * characters. Since an empty string reads the same forward and backward, it is
 * a palindrome.
 *
 * == Constraints ==
 * - 1 <= s.length <= 2 * 105
 * - s consists only of printable ASCII characters.
 */
class Solution {
 public:
  bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
      // Skip any non-alphanumeric characters.
      while (i < s.length() && !isalnum(s[i])) { i++; }
      while (j >= 0 && !isalnum(s[j])) { j--; }

      // We might have moved right past the other pointer, so check for that.
      if (i < j && tolower(s[i++]) != tolower(s[j--])) {
        return false;
      }
    }
    return true;
  }

  // This is slightly faster (1.3x), which gets us to 100% on leetcode.
  // Maybe it optomizes a bit better? Since the code isn't that different.
  // Eliminating the inner loops might let the compiler more aggresively
  // optomize our main while loop, for example by using vector ops.
  bool isPalindromeFast(string s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
      const auto q = s[i];
      const auto r = s[j];
      if (!isalnum(q)) {
        i++;
      } else if (!isalnum(r)) {
        j--;
      } else if (tolower(q) == tolower(r)) {
        i++;
        j--;
      } else {
        return false;
      }
    }
    return true;
  }
};
