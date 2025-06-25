#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int candy(vector<int>& ratings) {
    if (ratings.empty()) {
      return 0;
    }

    if (ratings.size() == 1) {
      return 1;
    }

    // TODO: sum up the candy as we go
    const auto& n = ratings.size();
    vector<int> candy(n);

    // go forward
    int amt = 1;

    // handle the first index
    if (ratings[0] <= ratings[1]) {
      candy[0] = 1;
    }

    for (int i = 1; i < n - 1; i++) {
      // give candy if the ratings are increasing in this direction
      if (ratings[i - 1] < ratings[i]) {
        candy[i] = ++amt;
      } else if (ratings[i - 1] == ratings[i]) {
        candy[i] = 1;
        amt = 1;
      } else {
        // rating is decreasing, skip unless local minima
        if (ratings[i] < ratings[i + 1]) {
          candy[i] = 1;
        }
        amt = 1;
      }
    }

    // go backward
    //
    // handle the last index
    if (ratings[n - 2] < ratings[n - 1]) {
      candy[n - 1] = ++amt;
    } else {
      candy[n - 1] = 1;
    }

    amt = 1;
    for (int i = n - 2; i > 0; i--) {
      // give candy if ratings are increasing in this direction
      if (ratings[i + 1] < ratings[i]) {
        // There's a tricky edge case here: what if we find a local maximum, so
        // the ratings are increasing (relative to the last element visted) in
        // both directions? In that case, we need to either keep the existing
        // candy amount, or overwrite it with our new value, whichever is
        // larger.
        candy[i] = max(candy[i], ++amt);
      } else if (ratings[i + 1] == ratings[i]) {
        if (candy[i] == 0) {
          candy[i] = 1;
          amt = 1;
        }
      } else {
        // rating is decreasing, skip
        amt = 1;
      }
    }

    // handle first index (again)
    if (ratings[0] > ratings[1]) {
      candy[0] = ++amt;
    }

    // sum up candy
    int total_candy = 0;
    for (int i = 0; i < candy.size(); i++) {
      total_candy += candy[i];
    }

    return total_candy;
  }
};

TEST(SolutionTest, Test01) {
  Solution s;
  vector<int> ratings{1, 0, 2};
  EXPECT_EQ(s.candy(ratings), 5);
}

TEST(SolutionTest, Test02) {
  Solution s;
  vector<int> ratings{1, 2, 2};
  EXPECT_EQ(s.candy(ratings), 4);
}

TEST(SolutionTest, Test03) {
  Solution s;
  vector<int> ratings{1, 2, 2, 2, 1};
  EXPECT_EQ(s.candy(ratings), 7);
}

TEST(SolutionTest, Test04) {
  Solution s;
  vector<int> ratings{1, 2, 87, 87, 87, 2, 1};
  EXPECT_EQ(s.candy(ratings), 13);
}

TEST(SolutionTest, Test05) {
  Solution s;
  vector<int> ratings{1, 2, 87, 87, 87, 1};
  EXPECT_EQ(s.candy(ratings), 10);
}

TEST(SolutionTest, Test06) {
  Solution s;
  vector<int> ratings{1,3,2,2,1};
  EXPECT_EQ(s.candy(ratings), 7);
}

TEST(SolutionTest, Test07) {
  Solution s;
  vector<int> ratings{5,3,7,3};
  EXPECT_EQ(s.candy(ratings), 6);
}
