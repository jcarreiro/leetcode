#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

/*
 * Write a function to find the longest common prefix string amongst an array of
 * strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * == Example 1 ==
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 * == Example 2 ==
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 * == Constraints ==
 * - 1 <= strs.length <= 200
 * - 0 <= strs[i].length <= 200
 * - strs[i] consists of only lowercase English letters if it is non-empty.
 */
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    }

    auto sizes =
        strs | views::transform([](const auto& s) { return s.size(); });
    auto minSize = ranges::min(sizes);

    const auto& s = strs[0];
    size_t i = 0;
    for (; i < minSize; i++) {
      const auto c = s[i];
      bool mismatch = false;
      for (size_t j = 1; j < strs.size(); j++) {
        if (strs[j][i] != c) {
          mismatch = true;
          break;
        }
      }

      if (mismatch) {
        break;
      }
    }

    return s.substr(0, i);
  }
};
