#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    // In this problem, we have to determine a researcher's h-index, which is
    // defined as the maximum value of h s.t. the researcher has published at
    // least h papers that have each been cited h times. Our input is an array
    // on integers which are the citation counts.
    //
    // To solve this, we're going to build an auxillary array, which will be the
    // count of papers with /i/ citations. Then we can iterate over the array
    // backwards, summing up as we go, and return the index of the first element
    // we encounter where the sum so far is larger than the index.
    //
    // (I think it might be possible to solve this without the extra memory, but
    // I'm not sure and this should definitely work.)
    //
    // Note that the size + 1 here is to handle papers with 0 citations.
    vector<int> counts(citations.size() + 1, 0);
    for (const auto i : citations) {
      // The problem statement specifies counts will be in this range, so we can
      // assert on it here.
      assert(i >= 0 && i <= 1000);
      const auto idx = min(counts.size() - 1, static_cast<size_t>(i));
      counts[idx]++;
    }

    int sum = 0;
    for (int i = counts.size() - 1; i > 0; i--) {
      sum += counts[i];
      if (sum >= i) {
        return i;
      }
    }
    return 0;
  }
};

TEST(SolutionTest, Test01) {
  Solution s;
  vector<int> citations{3,0,6,1,5};
  ASSERT_EQ(s.hIndex(citations), 3);
}

TEST(SolutionTest, Test02) {
  Solution s;
  vector<int> citations{1,3,1};
  ASSERT_EQ(s.hIndex(citations), 1);
}

TEST(SolutionTest, Test03) {
  Solution s;
  vector<int> citations{1};
  ASSERT_EQ(s.hIndex(citations), 1);
}

TEST(SolutionTest, Test04) {
  Solution s;
  vector<int> citations{3,4,1,4,3};
  ASSERT_EQ(s.hIndex(citations), 3);
}

TEST(SolutionTest, Test05) {
  Solution s;
  vector<int> citations{3,4,1,1,3};
  ASSERT_EQ(s.hIndex(citations), 3);
}

TEST(SolutionTest, Test06) {
  Solution s;
  vector<int> citations{0,0,2};
  ASSERT_EQ(s.hIndex(citations), 1);
}

TEST(SolutionTest, Test07) {
  Solution s;
  vector<int> citations{2,1};
  ASSERT_EQ(s.hIndex(citations), 1);
}

TEST(SolutionTest, Test08) {
  Solution s;
  vector<int> citations{11,15};
  ASSERT_EQ(s.hIndex(citations), 2);
}
