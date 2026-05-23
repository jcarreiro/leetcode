#include <array>
#include <cassert>
#include <iostream>
#include <optional>
#include <random>
#include <unordered_set>

using namespace std;

class RandomizedSet {
public:
  RandomizedSet() : buckets_{}, end_{0}, array_(1024, 0), prng_{0} {}

  bool insert(int val) {
    auto& bucket = hash(val);
    if (bucket.has_value()) {
      if (bucket->val != val) {
        throw new runtime_error("No space left in hash table!");
      }
      // item already present
      return false;
    }

    // item not present
    if (end_ == array_.size()) {
      array_.resize(array_.size() * 2);
    }

    array_[end_] = val;
    bucket = {val, end_++};
    return true;
  }

  bool remove(int val) {
    auto& bucket = hash(val);
    if (bucket.has_value() && bucket->val == val) {
      // get the last item in the array
      const auto& lastItem = array_[--end_];
      auto& otherBucket = hash(lastItem);
      assert(otherBucket.has_value());

      // swap with it
      swap(array_[bucket->idx], array_[end_]);

      // update the index for the swapped element
      swap(bucket->idx, otherBucket->idx);

      // remove this element
      bucket = nullopt;
      return true;
    }
    return false;
  }

  int getRandom() {
    // Per the problem definition, we should always have at least one element in
    // the set when getRandom() is called.
    assert(end_ > 0);
    uniform_int_distribution<> dist(0, end_ - 1);
    return array_[dist(prng_)];
  }

private:
  constexpr static size_t kNumBuckets{10'000};

  struct Bucket {
    // Value stored in this bucket.
    int val;

    // Index into auxillary array (for getRandom).
    size_t idx;
  };

  optional<Bucket>& hash(int val) {
    size_t i = 0;
    size_t k = val % kNumBuckets;
    while (i++ < kNumBuckets && buckets_[k].has_value() &&
           buckets_[k].value().val != val) {
      k = (k + 1) % kNumBuckets;
    }
    return buckets_[k];
  }

  // TODO: resize hash table when load factor becomes large
  array<optional<Bucket>, kNumBuckets> buckets_;
  size_t end_;
  vector<int> array_;
  mt19937 prng_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
