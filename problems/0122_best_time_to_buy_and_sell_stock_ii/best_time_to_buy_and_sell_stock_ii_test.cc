#include "best_time_to_buy_and_sell_stock_ii.h"
#include <gtest/gtest.h>

TEST(BestTimeToBuyAndSellStockIiTest, Test01) {
  Solution s;
  vector<int> prices{7, 1, 5, 3, 6, 4};
  ASSERT_EQ(s.maxProfit(prices), 7);
}

TEST(BestTimeToBuyAndSellStockIiTest, Test02) {
  Solution s;
  vector<int> prices{6, 1, 3, 2, 4, 7};
  ASSERT_EQ(s.maxProfit(prices), 7);
}

TEST(BestTimeToBuyAndSellStockIiTest, Ascending) {
  Solution s;
  vector<int> prices{1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(s.maxProfit(prices), 6);
}
TEST(BestTimeToBuyAndSellStockIiTest, Descending) {
  Solution s;
  vector<int> prices{7, 6, 5, 4, 3, 2, 1};
  ASSERT_EQ(s.maxProfit(prices), 0);
}



