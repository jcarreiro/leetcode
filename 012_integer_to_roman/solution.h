#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>

#define USE_STRINGSTREAM
#define intToRoman intToRoman2

using namespace std;

// Seven different symbols represent Roman numerals with the following values:
//
// |--------+-------|
// | Symbol | Value |
// |--------+-------|
// | V      |     5 |
// | X      |    10 |
// | L      |    50 |
// | C      |   100 |
// | D      |   500 |
// | M      |  1000 |
// |--------+-------|
//
// Roman numerals are formed by appending the conversions of decimal place
// values from highest to lowest. Converting a decimal place value into a Roman
// numeral has the following rules:
//
// - If the value does not start with 4 or 9, select the symbol of the maximal
//   value that can be subtracted from the input, append that symbol to the
//   result, subtract its value, and convert the remainder to a Roman numeral.
//
// - If the value starts with 4 or 9 use the subtractive form representing one
//   symbol subtracted from the following symbol, for example, 4 is 1 (I) less
//   than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following
//   subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and
//   900 (CM).
//
// - Only powers of 10 (I, X, C, M) can be appended consecutively at most 3
//   times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500
//   (D) multiple times. If you need to append a symbol 4 times use the
//   subtractive form.
//
//   [This doesn't make any sense -- how would you represent 4000 given this
//   constraint? --jmc]
//
// Given an integer, convert it to a Roman numeral.
//
// == Example 1 ==
//
// Input: num = 3749
//
// Output: "MMMDCCXLIX"
//
// Explanation:
//
// 3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
//  700 = DCC as 500 (D) + 100 (C) + 100 (C)
//   40 = XL as 10 (X) less of 50 (L)
//    9 = IX as 1 (I) less of 10 (X)
//
// Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on
// decimal places
//
// == Example 2 ==
//
// Input: num = 58
//
// Output: "LVIII"
//
// Explanation:
//
// 50 = L
//  8 = VIII
//
// == Example 3 ==
//
// Input: num = 1994
//
// Output: "MCMXCIV"
//
// Explanation:
//
// 1000 = M
//  900 = CM
//   90 = XC
//    4 = IV
class Solution {
public:
  string intToRoman1(int num) {
    struct sym {
      int value;
      string rep;
    };

    vector<sym> symbols{
      {1000, "M"},
      {900, "CM"},
      {500, "D"},
      {400, "CD"},
      {100, "C"},
      {90, "XC"},
      {50, "L"},
      {40, "XL"},
      {10, "X"},
      {9, "IX"},
      {5, "V"},
      {4, "IV"},
      {1, "I"},
    };

#ifdef USE_STRINGSTREAM
    stringstream buf;
#else
    vector<char> buf(256, 0);
    int wp = 0;
#endif

    while (num > 0) {
      for (const auto &s : symbols) {
        if (num >= s.value) {
#ifdef USE_STRINGSTREAM
          buf << s.rep;
#else
          const auto& rep = s.rep;
          const auto& n = rep.length();
          memcpy(&buf[wp], rep.data(), n);
          wp += n;
#endif
          num -= s.value;
          break;
        }
      }
    }
#ifdef USE_STRINGSTREAM
    return buf.str();
#else
    return &buf[0];
#endif
  }

  string intToRoman2(int num) {
    vector<char> buf(256, 0);
    int wp = 254;

    // ones
    auto dv = div(num, 10);
    switch (dv.rem) {
      case 9: // IX
        buf[wp--] = 'X';
        buf[wp--] = 'I';
        break;

      case 8: // VIII
        buf[wp--] = 'I';
        buf[wp--] = 'I';
        buf[wp--] = 'I';
        buf[wp--] = 'V';
        break;

      case 7: // VII
        buf[wp--] = 'I';
        buf[wp--] = 'I';
        buf[wp--] = 'V';
        break;

      case 6: // VI
        buf[wp--] = 'I';
        buf[wp--] = 'V';
        break;

      case 5: // V
        buf[wp--] = 'V';
        break;

      case 4: // IV
        buf[wp--] = 'V';
        buf[wp--] = 'I';
        break;

      case 3: // III
        buf[wp--] = 'I';
        // fall through

      case 2: // II
        buf[wp--] = 'I';
        // fall through

      case 1: // I
        buf[wp--] = 'I';
    }

    // tens
    dv = div(dv.quot, 10);
    switch (dv.rem) {
      case 9: // XC
        buf[wp--] = 'C';
        buf[wp--] = 'X';
        break;

      case 8: // LXXX
        buf[wp--] = 'X';
        buf[wp--] = 'X';
        buf[wp--] = 'X';
        buf[wp--] = 'L';
        break;

      case 7: // LXX
        buf[wp--] = 'X';
        buf[wp--] = 'X';
        buf[wp--] = 'L';
        break;

      case 6: // LX
        buf[wp--] = 'X';
        buf[wp--] = 'L';
        break;

      case 5: // L
        buf[wp--] = 'L';
        break;

      case 4: // XL
        buf[wp--] = 'L';
        buf[wp--] = 'X';
        break;

      case 3: // XXX
        buf[wp--] = 'X';
        // fall through

      case 2: // XX
        buf[wp--] = 'X';
        // fall through

      case 1: // X
        buf[wp--] = 'X';
    }

    // hundreds
    dv = div(dv.quot, 10);
    switch (dv.rem) {
      case 9: // CM
        buf[wp--] = 'M';
        buf[wp--] = 'C';
        break;

      case 8: // DCCC
        buf[wp--] = 'C';
        buf[wp--] = 'C';
        buf[wp--] = 'C';
        buf[wp--] = 'D';
        break;

      case 7: // DCC
        buf[wp--] = 'C';
        buf[wp--] = 'C';
        buf[wp--] = 'D';
        break;

      case 6: // DC
        buf[wp--] = 'C';
        buf[wp--] = 'D';
        break;

      case 5: // D
        buf[wp--] = 'D';
        break;

      case 4: // CD
        buf[wp--] = 'D';
        buf[wp--] = 'C';
        break;

      case 3: // CCC
        buf[wp--] = 'C';
        // fall through

      case 2: // CC
        buf[wp--] = 'C';
        // fall through

      case 1: // C
        buf[wp--] = 'C';
    }

    // thousands
    dv = div(dv.quot, 10);
    switch (dv.rem) {
      case 3:
        buf[wp--] = 'M';
        // fall through

      case 2:
        buf[wp--] = 'M';
        // fall through

      case 1:
        buf[wp--] = 'M';
    }
    return &buf[++wp];
  }
};
