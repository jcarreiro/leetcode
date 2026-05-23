#include "insert_delete_getrandom_O1.h"
#include <gtest/gtest.h>

TEST(RandomizedSetTest, TestInsert) {
  RandomizedSet r;
  r.insert(1);
  ASSERT_EQ(r.getRandom(), 1);
}

TEST(RandomizedSetTest, TestRemove) {
  RandomizedSet r;
  r.insert(1);
  r.insert(2);
  r.remove(1);
  ASSERT_EQ(r.getRandom(), 2);
}

TEST(RandomizedSetTest, TestGetRandom) {
  RandomizedSet r;
  // insert a bunch of items
  constexpr auto kItemCount = 6;
  for (auto i = 0; i < kItemCount; i++) {
    r.insert(i);
  }

  // call getRandom() lots of times, count how often we get each item
  map<int, size_t> counts;
  for (auto i = 0; i < kItemCount; i++) {
    counts[i] = 0;
  }

  constexpr auto kTrials = 1'000'000;
  for (auto i = 0; i < kTrials; i++) {
    const auto v = r.getRandom();
    counts[v]++;
  }

  // each item should have been returned roughly 1 / kItemCount times
  for (auto i = 0; i < kItemCount; i++) {
    EXPECT_NEAR(1.0 / static_cast<float>(kItemCount),
                static_cast<float>(counts[i]) / static_cast<float>(kTrials),
                0.001);
  }
}

TEST(RandomizedSetTest, Test01) {
  RandomizedSet r;
  r.insert(0);
  r.insert(1);
  r.remove(0);
  r.insert(2);
  r.remove(1);
  ASSERT_EQ(r.getRandom(), 2);
}



