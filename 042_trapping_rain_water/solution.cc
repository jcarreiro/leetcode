#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_set>

using namespace std;

// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it can trap after raining.
//
// Example 1
// ---------
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
//
// Explanation: The above elevation map (black section) is represented by array
// [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
// are being trapped.
//
// Example 2
// ---------
// Input: height = [4,2,0,3,2,5]
// Output: 9

class Solution {
public:
  int trap(vector<int>& height) {
    // Build the max height tables: one for the max to the left, and one for the
    // max to the right.
    vector<int> max_left(height.size(), 0);
    for (int i = 1; i < height.size(); i++) {
      const auto& h = height[i - 1];
      max_left[i] = max(h, max_left[i - 1]);
    }

    vector<int> max_right(height.size(), 0);
    for (int i = height.size() - 2; i >= 0; i--) {
      const auto& h = height[i + 1];
      max_right[i] = max(h, max_right[i + 1]);
    }

    // Loop over the heights and fill up the water levels.
    int total_water = 0;
    for (int i = 0; i < height.size(); i++) {
      const auto w = max(min(max_left[i], max_right[i]) - height[i], 0);
      total_water += w;
    }

    return total_water;
  }
};

TEST(SolutionTest, Test01) {
  Solution s;
  vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
  EXPECT_EQ(s.trap(height), 6);
}

TEST(SolutionTest, Test02) {
  Solution s;
  vector<int> height{4,2,0,3,2,5};
  EXPECT_EQ(s.trap(height), 9);
}
