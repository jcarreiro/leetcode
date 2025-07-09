#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>

using namespace std;

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D
// and M.
//
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
//
// For example, 2 is written as II in Roman numeral, just two ones added
// together. 12 is written as XII, which is simply X + II. The number 27 is
// written as XXVII, which is XX + V + II.
//
// Roman numerals are usually written largest to smallest from left to right.
// However, the numeral for four is not IIII. Instead, the number four is
// written as IV. Because the one is before the five we subtract it making four.
// The same principle applies to the number nine, which is written as IX. There
// are six instances where subtraction is used:
//
// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
//
// Given a roman numeral, convert it to an integer.
//
// Example 1
// ---------
//
// Input: s = "III"
// Output: 3
// Explanation: III = 3.
//
// Example 2
// ---------
//
// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
//
// Example 3
// ---------
//
// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
//
// Constraints
// -----------
//
// 1 <= s.length <= 15
// s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
// It is guaranteed that s is a valid roman numeral in the range [1, 3999].

class Solution {
public:
  int romanToInt(string s) {
    int num = 0;
    int i = 0;
    while (i < s.length()) {
      // Get the next character from the stream, and get a look-ahead we can use
      // to detect cases like 'IV'.
      const auto& c = s[i];
      optional<char> nc;
      if (i < s.length() - 1) {
        nc = s[i + 1];
      }

      switch (c) {
        case 'I':
          // I can precede V, X
          if (nc == 'V') {
            num += 4;
            i += 2;
          } else if (nc == 'X') {
            num += 9;
            i += 2;
          } else {
            num += 1;
            i++;
          }
          break;

        case 'V':
          num += 5;
          i++;
          break;

        case 'X':
          // X can precede L, C
          if (nc == 'L') {
            num += 40;
            i += 2;
          } else if (nc == 'C') {
            num += 90;
            i += 2;
          } else {
            num += 10;
            i++;
          }
          break;

        case 'L':
          num += 50;
          i++;
          break;

        case 'C':
          // C can precede D, M
          if (nc == 'D') {
            num += 400;
            i += 2;
          } else if (nc == 'M') {
            num += 900;
            i += 2;
          } else {
            num += 100;
            i++;
          }
          break;

        case 'D':
          num += 500;
          i++;
          break;

        case 'M':
          num += 1000;
          i++;
          break;

        default:
          // This isn't a valid letter!
          throw new std::runtime_error(
            std::format("Got invalid letter value {}!", c));
      }
    }
    return num;
  }
};

TEST(SolutionTest, Test01) {
  Solution s;
  EXPECT_EQ(s.romanToInt("III"), 3);
}

TEST(SolutionTest, Test02) {
  Solution s;
  EXPECT_EQ(s.romanToInt("LVIII"), 58);
}

TEST(SolutionTest, Test03) {
  Solution s;
  EXPECT_EQ(s.romanToInt("MCMXCIV"), 1994);
}
