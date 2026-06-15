// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <vector>

using namespace std;

// # 57. Insert Interval
//
// Difficulty: Medium
//
// You are given an array of non-overlapping intervals intervals where
// intervals[i] = [start_i, end_i] represent the start and the end of the ith
// interval and intervals is sorted in ascending order by starti. You are also
// given an interval newInterval = [start, end] that represents the start and
// end of another interval.
//
// Insert newInterval into intervals such that intervals is still sorted in
// ascending order by start_i and intervals still does not have any overlapping
// intervals (merge overlapping intervals if necessary).
//
// Return intervals after the insertion.
//
// Note that you don't need to modify intervals in-place. You can make a new
// array and return it.
//
// ## Example 1
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// ## Example 2
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
//
// ## Constraints
// - 0 <= intervals.length <= 10^4
// - intervals[i].length == 2
// - 0 <= start_i <= end_i <= 10^5
// - intervals is sorted by start_i in ascending order.
// - newInterval.length == 2
// - 0 <= start <= end <= 10^5
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    // Iterate over the list of intervals until we find the first interval that
    // overlaps with newInterval. Then, merge in newInterval, and keep merging
    // forward until we reach an interval that we don't need to merge, or the
    // end of the list, whichever comes first. Finally, write any remaining
    // intervals from the input list (that didn't need to be merged) to the
    // output.
    //
    // Since we visit each element once and do a constant amount of work per
    // element, this runs in O(n) time.
    if (intervals.empty()) {
      return {newInterval};
    }

    // First, we can just copy any intervals that are before the new interval
    // into the output, since the insertion won't affect them.
    vector<vector<int>> v;
    int i = 0;
    for (; i < intervals.size(); i++) {
      auto& a = intervals[i];
      if (a[1] >= newInterval[0]) {
        // This interval ends after the start of the new interval.
        break;
      }
      v.push_back(std::move(a));
    }

    // If all the intervals were before the new interval, we're done.
    if (i == intervals.size()) {
      v.push_back(std::move(newInterval));
      return v;
    }

    // Now we need to merge in the new interval. There are two possibilities:
    // either it goes before the next interval on the list in the output, or it
    // overlaps and we need to merge it.
    auto a = intervals[i];
    if (newInterval[1] < a[0]) {
      // There's a gap where the new interval fits.
      v.push_back(std::move(newInterval));
    } else {
      // We need to merge it in. Merge intervals until we find one that doesn't
      // need to be merged.
      vector<int> m{min(a[0], newInterval[0]), max(a[1], newInterval[1])};
      i += 1;
      for (; i < intervals.size(); i++) {
        a = intervals[i];
        if (a[0] > m[1]) {
          // This is the first interval that doesn't need to be merged.
          break;
        }
        // Extend the end of the merged interval.
        m[1] = max(m[1], a[1]);
      }
      v.push_back(std::move(m));
    }

    // Now write any remaining intervals that we didn't need to merge.
    for (; i < intervals.size(); i++) {
      v.push_back(std::move(intervals[i]));
    }

    return v;
  }
};
