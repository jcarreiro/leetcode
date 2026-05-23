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
