#include "lru_cache.h"

#include <gtest/gtest.h>

TEST(LruCacheTest, Test01) {
  LRUCache lruCache{2};
  lruCache.put(1, 1);             // cache is {1=1}
  lruCache.put(2, 2);             // cache is {1=1, 2=2}
  EXPECT_EQ(lruCache.get(1), 1);  // return 1
  lruCache.put(3, 3);  // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  EXPECT_EQ(lruCache.get(2), -1);  // returns -1 (not found)
  lruCache.put(4, 4);  // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  EXPECT_EQ(lruCache.get(1), -1);  // return -1 (not found)
  EXPECT_EQ(lruCache.get(3), 3);   // return 3
  EXPECT_EQ(lruCache.get(4), 4);   // return 4
}
