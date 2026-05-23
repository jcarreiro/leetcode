#include <cmath>
#include <iostream>
#include <numeric>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  int mod(int a, int b) {
    const auto r = a % b;
    return r < 0 ? r + abs(b) : r;
  }

  void rotate(vector<int>& nums, int k) {
    // A rotation is just a particular kind of permutation.
    //
    // Note that if the shift is not relatively prime to the array length, then
    // there will be cycles in the permutation shorter than the length of the
    // array. For example, consider the case with n = 4 and k = 2; starting at
    // index 0, the permutation sends the element to index 2, which is then sent
    // back to index 0.
    if (nums.size() == 0 || k == 0) {
      return;
    }

    size_t n = nums.size();
    size_t l = lcm(n, abs(k)) / abs(k);
    size_t i = 0;
    int last = nums[i];
    for (auto c = 0; c < n; c++) {
      // If we just completed a cycle, move forward an element so that we start
      // the next one.
      if (gcd(n, k) > 1 && c > 0 && c % l == 0) {
        last = nums[++i];
      }

      // Where do we send this element?
      // size_t j = modulo(i + k, nums.size());
      size_t j = mod(i + k, n);

      // Write the element to its final position in the permutation.
      int tmp = nums[j];
      nums[j] = last;
      last = tmp;

      // Loop and handle the next element in the permutation.
      i = j;
    }
    return;
  }

  // TODO: come up wtih 2 more ways to solve this
};
