#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <unordered_set>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> output(nums.size(), 1);

    // forward pass
    int product = 1;
    for (size_t i = 0; i < nums.size(); i++) {
      output[i] = product;
      product *= nums[i];
    }

    // backwards pass
    product = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      output[i] *= product;
      product *= nums[i];
    }

    return output;
  }
};
