// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <cassert>
#include <cstdlib>
#include <unordered_set>

using namespace std;

// # 202. Happy Number
//
// Difficulty: Easy
//
// Write an algorithm to determine if a number n is happy.
//
// A happy number is a number defined by the following process:
// - Starting with any positive integer, replace the number by the sum of the
//   squares of its digits.
// - Repeat the process until the number equals 1 (where it will stay), or it
//   loops endlessly in a cycle which does not include 1.
// - Those numbers for which this process ends in 1 are happy.
//
// Return true if n is a happy number, and false if not.
//
// ## Example 1
// Input: `n = 19`
// Output: `true`
//
// Explanation:
// `1^2 + 9^2 = 82`
// `8^2 + 2^2 = 68`
// `6^2 + 8^2 = 100`
// `1^2 + 0^2 + 0^2 = 1`
//
// ## Example 2
// Input: `n = 2`
// Output: `false`
//
// ## Constraints
// - `1 <= n <= 2^31 - 1`
class Solution {
public:
  bool isHappy(int n) {
    // We maintain a set of visited numbers, in the form of a hash table. If we
    // ever visit the same number again before we reach 1, then this number has
    // a cycle which doesn't include 1, so it isn't happy.
    assert(n > 0);
    unordered_set<int> s;
    while (true) {
      if (n == 1) {
        return true;
      } else if (s.contains(n)) {
        return false;
      }

      s.insert(n);

      // extract each digit of n and sum the squares
      int sum = 0;
      while (n > 0) {
        auto [q, r] = div(n, 10);
        sum += r * r;
        n = q;
      }
      n = sum;
    }
    // not reached
    assert(0);
    return false;
  }
};
