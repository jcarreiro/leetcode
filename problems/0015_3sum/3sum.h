#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 * == Example 1 ==
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 *
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 *
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 *
 * == Example 2 ==
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 *
 * == Example 3 ==
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 *
 * == Constraints ==
 * - 3 <= nums.length <= 3000
 * - 10^5 <= nums[i] <= 10^5
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> triplets;
    for (int i = 0; i < nums.size(); i++) {
      // Skip duplicates.
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      // Starting from the ends of the array, look for a pair that sums to the
      // inverse of this value.
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        const int a = nums[i];
        const int b = nums[j];
        const int c = nums[k];
        const int sum = a + b + c;
        if (sum < 0) {
          // The current sum is less than 0, so move the left pointer in
          // towards a smaller value.
          while (j < k && nums[j] == b) {
            j++;
          }
        } else if (sum == 0) {
          triplets.emplace_back<vector<int>>({a, b, c});
          while (j < k && nums[j] == b) {
            j++;
          }
          while (k > j && nums[k] == c) {
            k--;
          }
        } else {
          // The current sum is greater than 0, so move the right pointer in
          // towards a smaller value.
          while (k > j && nums[k] == c) {
            k--;
          }
        }
      }
    }
    return triplets;
  }
};
