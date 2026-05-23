#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    // We can start from any space with a positive delta, as long as the sum
    // remains positive as we iterate over the array. If the sum ever becomes
    // negative, we need to start over since we've run out of gas. Since, per
    // the problem definition, the sum is guaranteed to be unique if it exists,
    // we can just iterate over the array once, looking for the one station
    // where the sum of the deltas remains positive.
    assert(gas.size() == cost.size());

    // The current starting position.
    optional<int> start;

    // The sum of the (gas - cost) since the start position.
    int partialSum = 0;

    // The total sum of the (gas - cost).
    int totalSum = 0;

    // Iterate over the array, tracking the overall sum, and the partial sum
    // since our current start space.
    for (auto i = 0; i < gas.size(); i++) {
      const auto delta = gas[i] - cost[i];

      // Update the total sum.
      totalSum += delta;

      // If we don't currently have a start position, and we just found a
      // positive delta, then mark this as the new start position and start
      // tracking the partial sum.
      if (!start.has_value()) {
        if (delta >= 0) {
          start = i;
          partialSum = delta;
        }
      } else {
        partialSum += delta;

        // If we have a start, but our partial sum just became negative, then
        // our start position can't be the answer, since we'll end up stuck in
        // this space. So we reset it. Note that this space can't be the start,
        // either, since if it made partialSum negative, it must have a net
        // cost.
        if (partialSum < 0) {
          start = nullopt;
          partialSum = 0;
        }
      }
    }

    // If the total sum was not negative, then whatever start space we have is
    // the answer.
    if (totalSum >= 0) {
      return start.value();
    }

    // There is no answer that works, so return -1;
    return -1;
  }
};
