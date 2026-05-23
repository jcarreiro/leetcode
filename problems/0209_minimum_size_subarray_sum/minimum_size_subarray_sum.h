#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * Given an array of positive integers, and a positive integer target, return
 * the minimal length of a subarray whose sum is greater than or equal to the
 * target. If there is no such subarray, return 0 instead.
 *
 * == Example 1 ==
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 * == Example 2 ==
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 *
 * == Example 3 ==
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 *
 * == Constraints == *
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 */
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }

    optional<size_t> minLength;
    size_t i = 0;
    assert(nums[0] > 0); // All numbers must be positive

    // If the first value is already \geq to the target, return early.
    if (nums[0] >= target) {
      return 1;
    }

    size_t sum = nums[0];
    for (size_t j = 1; j < nums.size(); j++) {
      assert(nums[j] > 0); // All numbers must be positive

      // If we ever find a single value \geq the target, return early.
      if (nums[j] >= target) {
        return 1;
      }

      // Add the new value into the sum.
      sum += nums[j];

      // cout << "Got value " << nums[j] << ", new sum " << sum << "." << endl;

      // If the new sum is greater than the target, try to remove some values
      // from the left side, to shrink the window.
      while (sum - nums[i] >= target) {
        // cout << "Removing value " << nums[i] << " from window." << endl;
        sum -= nums[i++];
      }

      // If our sum is equal to or greater than the target, check to see if
      // we found a new minimum length subarray.
      if (sum >= target) {
        const auto length = j - i + 1;
        if (!minLength.has_value() || length < minLength) {
          // cout << "Found new minimun length subarray " << length << " (from "
          //      << i << " to " << j << ")." << endl;
          minLength = length;
        }
      }
    }

    if (minLength.has_value()) {
      return minLength.value();
    }

    return 0;
  }
};
