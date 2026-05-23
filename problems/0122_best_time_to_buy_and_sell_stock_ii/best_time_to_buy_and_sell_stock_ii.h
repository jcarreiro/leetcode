#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // This is another version of the "Buy and Sell Stock" problem. In this
    // version of the problem, we can choose to buy, sell, or hold the stock
    // each day, and we can hold at most one share of the stock at any time.
    //
    // The solution from the first version of the problem also works for this
    // one, with one modification: we buy the stock at the start of any run of
    // positive deltas, and we sell it as soon as we find a negative delta
    // between any two elements of the array (since that's a local maximum).
    size_t i = 0;         // start of the current run
    int total_profit = 0; // total profit so far
    for (auto j = 1; j < prices.size(); j++) {
      const auto d = prices[j] - prices[j - 1];
      if (d < 0) {
        // The last element was a local maximum, so sell the stock.
        // Note that we need to be a bit careful here -- if we're in
        // the middle of a run of negative deltas, then we don't want
        // to buy the stock in the first place, so we don't have a
        // share to sell.
        const auto run_delta = prices[j - 1] - prices[i];
        if (run_delta > 0) {
          // Sell our share.
          total_profit += run_delta;
        }

        // Start a new run from this element.
        i = j;
      }
    }

    // If we're still holding a share, sell it for the last day's price.
    if (i < prices.size() - 1) {
      total_profit += prices[prices.size() - 1] - prices[i];
    }

    return total_profit;
  }
};