#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/*
 * You are given an integer array height of length n. There are n vertical lines
 * drawn such that the two endpoints of the ith line are (i, 0) and (i,
 * height[i]).
 *
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 *
 * Return the maximum amount of water a container can store.
 *
 * Notice that you may not slant the container.
 *
 * == Example 1 ==
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 *
 * == Example 2 ==
 * Input: height = [1,1]
 * Output: 1
 *
 * == Constraints ==
 * - n == height.length
 * - 2 <= n <= 10^5
 * - 0 <= height[i] <= 10^4
 */
class Solution {
public:
  int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int q = height[i];
    int r = height[j];
    int area = (j - i) * min(q, r);
    while (i < j) {
      const int nq = height[i];
      const int nr = height[j];
      if (nq != q || nr != r) {
        q = nq;
        r = nr;
        int tmp = (j - i) * min(q, r);
        if (tmp > area) {
          area = tmp;
        }
      }

      // Move whichever pointer is pointing to the lowest value.
      if (r < q) {
        j--;
      } else {
        i++;
      }
    }

    return area;
  }
};
