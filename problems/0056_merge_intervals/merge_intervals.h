// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <algorithm>
#include <vector>

using namespace std;

// # 56. Merge Intervals
//
// Difficulty: Medium
//
// Given an array of intervals where intervals[i] = [start_i, end_i], merge all
// overlapping intervals, and return an array of the non-overlapping intervals
// that cover all the intervals in the input.
//
// ## Example 1
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
//
// ## Example 2
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
// ## Example 3
// Input: intervals = [[4,7],[1,4]]
// Output: [[1,7]]
// Explanation: Intervals [1,4] and [4,7] are considered overlapping.
//
// ## Constraints
// - 1 <= intervals.length <= 10^4
// - intervals[i].length == 2
// - 0 <= start_i <= end_i <= 10^4
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Sort all the intervals by their start, then iterate over the sorted list,
    // tracking a current interval as we iterate. For each interval, we check if
    // start overlaps with the current interval; if so, then we merge them.
    // Sort the list of intervals.
    sort(intervals.begin(), intervals.end());
    vector<int> m = move(intervals[0]);
    vector<vector<int>> v;
    for (int i = 1; i < intervals.size(); i++) {
      const auto& e = intervals[i];
      if (e[0] <= m[1]) {
        // This interval overlaps with the current candidate interval, so merge
        // them.
        m[1] = max(m[1], e[1]);
      } else {
        // This interval doesn't overlap. Since we sorted the intervals, that
        // means there's a gap, so we can output the current merged interval.
        v.push_back(move(m));
        m = move(intervals[i]);
      }
    }

    // Output the last interval.
    v.push_back(move(m));
    return v;
  }
};
