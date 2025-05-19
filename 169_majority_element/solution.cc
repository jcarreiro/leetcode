#include <iostream>
#include <vector>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      // We use an unordered_map to count elements, then do a second pass over
      // the map to find the majority element.
      std::unordered_map<int, int> counts;
      for (const auto& n : nums) {
        const auto& it = counts.find(n);
        if (it == counts.end()) {
          counts[n] = 1;
        } else {
          counts[n] = it->second + 1;
        }
      }

      const auto t = ceil(nums.size() / 2.0);
      for (const auto& [k, v] : counts) {
        if (v >= t) {
          return k;
        }
      }

      // No majority element.
      throw new runtime_error("No majority element!");
    }
};

TEST(MajorityElement, Basic) {
  Solution s;
  vector<int> v{1, 1, 1};
  auto m = s.majorityElement(v);
  ASSERT_EQ(m, 1);

  v = {1, 2, 2, 2, 1};
  m = s.majorityElement(v);
  ASSERT_EQ(m, 2);

  v = {3, 2, 3};
  m = s.majorityElement(v);
  ASSERT_EQ(m, 3);
}
