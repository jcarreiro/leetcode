#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      // Given an array whose elements are the daily prices of a stock, our goal
      // is to return the maximum profit possible from buying and selling the
      // stock. To do that, we'll iterate through the array, looking for runs
      // where the difference between the start of the run and current price is
      // positive; as long as that difference is positive, then the start of the
      // run is the best price we can buy the stock at, and the maximum element
      // within the run is the best price we can sell at. If the difference from
      // the start of the run to the current element is ever negative, then we
      // can (potentially) make more profit by buying the stock on the day with
      // the lower price, so we start a new run and repeat the above.
      size_t i = 0; // start of the current run
      int max_profit = 0; // max profit seen so far
      for (auto j = 1; j < prices.size(); j++) {
        auto d = prices[j] - prices[i];
        if (d > max_profit) {
          // This is the largest profit found so far.
          max_profit = d;
        }

        if (d < 0) {
          // The run went negative, so start a new run from this element.
          i = j;
        }
      }
      return max_profit;
    }
};

TEST(SolutionTest, Basic) {
  Solution s;
  vector<int> prices{7, 1, 5, 3, 6, 4};
  ASSERT_EQ(s.maxProfit(prices), 5);
}

TEST(SolutionTest, Ascending) {
  Solution s;
  vector<int> prices{1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(s.maxProfit(prices), 6);
}
TEST(SolutionTest, Descending) {
  Solution s;
  vector<int> prices{7, 6, 5, 4, 3, 2, 1};
  ASSERT_EQ(s.maxProfit(prices), 0);
}
