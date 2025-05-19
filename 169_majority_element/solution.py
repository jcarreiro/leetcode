import collections
import cProfile
import math
import random
import unittest

from typing import List

def swap(a, i, j):
    tmp = a[j]
    a[j] = a[i]
    a[i] = tmp

def partition5(a, left, right):
    """Select the median of a group of at most five elements using insertion
    sort."""
    i = left + 1
    while i <= right:
        j = i
        while j > left and a[j - 1] > a[j]:
            swap(a, j - 1, j)
            j = j - 1
        i = i + 1

    return left + (right - left) // 2

def pivot(a, left, right):
    """Find a pivot using the median of medians algorithm."""
    if right - left < 5:
        return partition5(a, left, right)

    for i in range(left, right, 5):
        end = i + 4
        if end > right:
            end = right
        median_of_5 = partition5(a, i, end)
        swap(a, median_of_5, left + (i - left) // 5)

    mid = (right - left) // 10 + left + 1
    return select(a, left, left + (right - left) // 5, mid)
        
    
def partition(a, left, right, pivot_index, k):
    """Perform a three-way partition of the elements of a in the range [left,
    right] about pivot_index, and return the index of the pivot.

    Args
    ----
    a: input array
    left: left position
    right: right position
    pivot_index: index to pivot around
    k: index of search element
    """
    pivot_value = a[pivot_index]
    swap(a, pivot_index, right)
    store_index = left
    # Move all elements smaller than the pivot to the left of it in the list.
    for i in range(left, right):
        if a[i] < pivot_value:
            swap(a, store_index, i)
            store_index += 1

    # Move all elements equal to the pivot right before it in the list.
    store_index_eq = store_index
    for i in range(store_index, right):
        if a[i] == pivot_value:
            swap(a, store_index_eq, i)
            store_index_eq += 1

    # Move the pivot to the correct location.
    swap(a, right, store_index_eq)
    
    # Return either store_index, k, or store_index_eq depending on where the
    # desired element is in relation to the pivot.
    if k < store_index:
        return store_index
    elif k <= store_index_eq:
        return k
    else:
        return store_index_eq        

def select(a, l, r, k):
    """Get the index of the k-th smallest number in the list a."""
    while True:
        if l == r:
            return l
        p = pivot(a, l, r)
        p = partition(a, l, r, p, k)
        if k == p:
            return k
        elif k < p:
            r = p - 1
        else:
            l = p + 1

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return self.majorityElementHash(nums)
    
    def majorityElementSelect(self, nums: List[int]) -> int:
        # Since the majority element must appear more than n/2 times, it must be
        # the median element in the array. So we can find it in O(n) time and
        # O(1) space using quickselect. This works, but it doesn't do well on
        # the runtime leaderboard, because of the large constant factors
        # involved when using the median of medians approach to selecting the
        # pivot (to prevent us from hitting the worse case when the array is
        # already sorted).
        i = select(nums, 0, len(nums) - 1, len(nums) // 2)
        return nums[i]

    def majorityElementHash(self, nums: List[int]) -> int:
        # Using a hash map, we count how often each element appears. Then a
        # pass over the map at the end is used to find the majority element.
        h = collections.defaultdict(lambda: 0)
        for x in nums:
            h[x] += 1

        for k, v in h.items():
            if v >= math.ceil(len(nums) / 2.0):
                return k

        # No majority element?
        raise ValueError("No majority element in array!")

class SolutionTest(unittest.TestCase):
    def test_pivot(self):
        a = [0, 1, 2, 3, 4, 5, 6]
        pivot_index = pivot(a, 0, len(a) - 1)
        self.assertEqual(pivot_index, 1)
        self.assertEqual(a[pivot_index], 5)
        
    def test_partition(self):
        a = [4, 5, 2, 1, 3]
        k = partition(a, 0, len(a) - 1, len(a) - 1, 0)
        self.assertEqual(k, 2)
        self.assertEqual(a, [2, 1, 3, 5, 4])

    def test_select(self):
        a = [7, 5, 8, 4, 0, 3, 9, 1, 2, 6]
        k = select(a, 0, 9, 9)
        self.assertEqual(k, 9)
        self.assertEqual(a[k], 9)

        a = [7, 5, 8, 4, 0, 3, 9, 1, 2, 6]
        k = select(a, 0, 9, 0)
        self.assertEqual(k, 0)
        self.assertEqual(a[k], 0)

        a = [7, 5, 8, 4, 0, 3, 9, 1, 2, 6]
        k = select(a, 0, 9, 5)
        self.assertEqual(k, 5)
        self.assertEqual(a[k], 5)

    def test_solution(self):
        s = Solution()
        m = s.majorityElement([3, 2, 3])
        self.assertEqual(m, 3)

if __name__ == '__main__':
    s = Solution()
    a = [1] * 100000
    pr = cProfile.Profile()
    pr.enable()
    s.majorityElement(a)
    pr.disable()
    pr.print_stats()
