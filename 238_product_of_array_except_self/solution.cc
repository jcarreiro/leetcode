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

TEST(SolutionTest, Test01) {
  Solution s;
  vector<int> v{1,2,3,4};
  ASSERT_EQ(s.productExceptSelf(v), vector<int>({24,12,8,6}));
}

TEST(SolutionTest, Test02) {
  Solution s;
  vector<int> v{-1,1,0,-3,3};
  ASSERT_EQ(s.productExceptSelf(v), vector<int>({0,0,9,0,0}));
}

TEST(SolutionTest, Test03) {
  Solution s;
  vector<int> v{0,0};
  ASSERT_EQ(s.productExceptSelf(v), vector<int>({0,0}));
}
