#include "best_time_to_buy_and_sell_stock.h"
#include <gtest/gtest.h>

TEST(Test, Basic) {
  Solution s;
  vector<int> prices{7, 1, 5, 3, 6, 4};
  ASSERT_EQ(s.maxProfit(prices), 5);
}

TEST(Test, Ascending) {
  Solution s;
  vector<int> prices{1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(s.maxProfit(prices), 6);
}
TEST(Test, Descending) {
  Solution s;
  vector<int> prices{7, 6, 5, 4, 3, 2, 1};
  ASSERT_EQ(s.maxProfit(prices), 0);
}

