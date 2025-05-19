#include <iostream>
#include <vector>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() < 3) {
        return nums.size();
      }

      int j = 2;
      for (auto i = 2; i < nums.size(); ++i) {
        if (nums[i] != nums[j - 2]) {
          nums[j++] = nums[i];
        }
      }
      return j;
    }
};

TEST(SolutionTest, shortArray) {
  Solution s;
  vector<int> v{1};
  auto k = s.removeDuplicates(v);
  ASSERT_EQ(k, 1);
  v.resize(k);
  ASSERT_EQ(v, vector<int>({1}));
}

TEST(SolutionTest, longArray) {
  Solution s;
  vector<int> v{1, 1, 1, 2, 2, 3};
  auto k = s.removeDuplicates(v);
  ASSERT_EQ(k, 5);
  v.resize(k);
  ASSERT_EQ(v, vector<int>({1, 1, 2, 2, 3}));
}
