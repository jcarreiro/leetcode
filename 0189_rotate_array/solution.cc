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

TEST(Solution, Basic) {
  Solution s;
  auto r = s.mod(-1, 7);
  ASSERT_EQ(r, 6);

  r = s.mod(1, 7);
  ASSERT_EQ(r, 1);

  vector<int> v{1, 2, 3, 4, 5, 6, 7};
  s.rotate(v, 1);
  ASSERT_EQ(v, vector<int>({7, 1, 2, 3, 4, 5, 6}));

  v = {7, 1, 2, 3, 4, 5, 6};
  s.rotate(v, -1);
  ASSERT_EQ(v, vector<int>({1, 2, 3, 4, 5, 6, 7}));

  v = {1, 2, 3, 4, 5, 6, 7};
  s.rotate(v, 2);
  ASSERT_EQ(v, vector<int>({6, 7, 1, 2, 3, 4, 5}));

  v = {6, 7, 1, 2, 3, 4, 5};
  s.rotate(v, -2);
  ASSERT_EQ(v, vector<int>({1, 2, 3, 4, 5, 6, 7}));

  v = {-1, -100, 3, 99};
  s.rotate(v, 2);
  ASSERT_EQ(v, vector<int>({3, 99, -1, -100}));

  v = {-1, -100, 3, 99};
  s.rotate(v, -2);
  ASSERT_EQ(v, vector<int>({3, 99, -1, -100}));

  v = {1, 2, 3, 4, 5, 6};
  s.rotate(v, 4);
  ASSERT_EQ(v, vector<int>({3, 4, 5, 6, 1, 2}));

  v = {};
  ASSERT_NO_THROW(s.rotate(v, 1));

  v = {1};
  s.rotate(v, 5);
  ASSERT_EQ(v, vector<int>({1}));

  v = {1};
  s.rotate(v, 0);
  ASSERT_EQ(v, vector<int>({1}));
}
