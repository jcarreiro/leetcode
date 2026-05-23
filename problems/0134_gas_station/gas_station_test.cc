#include "gas_station.h"
#include <gtest/gtest.h>

TEST(Test, Test01) {
  Solution s;
  vector<int> gas{1, 2, 3, 4, 5};
  vector<int> cost{3, 4, 5, 1, 2};
  EXPECT_EQ(s.canCompleteCircuit(gas, cost), 3);
}

TEST(Test, Test02) {
  Solution s;
  vector<int> gas{2, 3, 4};
  vector<int> cost{3, 4, 3};
  EXPECT_EQ(s.canCompleteCircuit(gas, cost), -1);
}

TEST(Test, Test03) {
  Solution s;
  vector<int> gas{2};
  vector<int> cost{2};
  EXPECT_EQ(s.canCompleteCircuit(gas, cost), 0);
}

