#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 * string convert(string s, int numRows);
 *
 *
 * == Example 1 ==
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 * == Example 2 ==
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 * == Example 3 ==
 * Input: s = "A", numRows = 1
 * Output: "A"
 *
 * == Constraints ==
 * - 1 <= s.length <= 1000
 * - s consists of English letters (lower-case and upper-case), ',' and '.'.
 * - 1 <= numRows <= 1000
 */
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }

    string t;
    t.resize(s.size(), '\0');
    int writePos = 0;
    int skipCount = 2 * (numRows - 1);
    for (int row = 0; row < numRows; row++) {
      int s0 = skipCount - (row * 2);
      int s1 = skipCount - s0;
      // TODO: figure out a better way to handle top and bottom row?
      if (s0 == 0) { s0 = skipCount; }
      if (s1 == 0) { s1 = skipCount; }
      int numWritten = 0;
      int readPos = row;
      while (readPos < s.size()) {
        t[writePos++] = s[readPos];
        if (numWritten % 2 == 0) {
          readPos += s0;
        } else {
          readPos += s1;
        }
        numWritten++;
      }
    }
    return t;
  }
};
