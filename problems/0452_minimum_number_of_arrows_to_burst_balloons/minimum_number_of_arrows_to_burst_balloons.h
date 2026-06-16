// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <algorithm>
#include <vector>

using namespace std;

// # 452. Minimum Number of Arrows to Burst Balloons
//
// Difficulty: Medium
//
// There are some spherical balloons taped onto a flat wall that represents the
// XY-plane. The balloons are represented as a 2D integer array points where
// points[i] = [x_start, x_end] denotes a balloon whose horizontal diameter
// stretches between x_start and x_end. You do not know the exact y-coordinates
// of the balloons.
//
// Arrows can be shot up directly vertically (in the positive y-direction) from
// different points along the x-axis. A balloon with x_start and x_end is burst
// by an arrow shot at x if x_start <= x <= x_end. There is no limit to the
// number of arrows that can be shot. A shot arrow keeps traveling up
// infinitely, bursting any balloons in its path.
//
// Given the array points, return the minimum number of arrows that must be shot
// to burst all balloons.
//
// ## Example 1
// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
// - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
//
// ## Example 2
// Input: points = [[1,2],[3,4],[5,6],[7,8]]
// Output: 4
// Explanation: One arrow needs to be shot for each balloon for a total of 4
// arrows.
//
// ## Example 3
// Input: points = [[1,2],[2,3],[3,4],[4,5]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
// - Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
//
// ## Constraints
// - 1 <= points.length <= 10^5
// - points[i].length == 2
// - -2^31 <= x_start < x_end <= 2^31 - 1
class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    // Sort the array by the ends. Then, starting with the least end point,
    // shoot an arrow at the end point of each 'balloon' that we haven't already
    // hit yet. We maintain the invariant that every balloon which starts to the
    // left of the last shot has already been hit, so we can simply skip any
    // balloons whose start is less than the last shot position.
    //
    // To see why this gives the minimum number of shots, simply consider the
    // first interval in the list, sorted by end coordinate. Clearly, the only
    // way to hit that interval is to fire an arrow at (or before) its end. Then
    // we must also hit any intervals that start before the end point, since we
    // are shooting at the first such point (so no other intervals can have
    // ended yet). If we remove the hit intervals from consideration, we can now
    // repeat the above to hit the new first interval in the list, and so on,
    // until all intervals are hit.
    //
    // Sice we sort the array and then iterate over it once, doing a constant
    // amount of work per element, this solution runs in O(n lg n) time.
    //
    // NB. Some solutions on leetcode covert the array to an array of pairs
    // before sorting and iterating over it as described above. This seems to
    // be faster, probably due to some additional logic (like bounds checking)
    // which is being done when accessing the elements of the inner vectors,
    // and which is not needed for pairs.
    sort(points.begin(), points.end(),
         [](const auto& a, const auto& b) { return a[1] < b[1]; });
    int c = 1;
    int x = points[0][1];
    for (int i = 0; i < points.size(); i++) {
      // Any interval that starts before the position of our last shot has
      // already been hit.
      if (points[i][0] <= x) {
        continue;
      }

      // Shoot an arrow.
      x = points[i][1];
      c += 1;
    }
    return c;
  }
};
