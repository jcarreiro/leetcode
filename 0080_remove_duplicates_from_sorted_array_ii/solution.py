import numpy as np
import timeit
import unittest

from line_profiler import profile
from typing import List

class Solution:
    @profile
    def removeDuplicates(self, nums: List[int]) -> int:
        j = 1
        c = 1
        for i in range(1, len(nums)):
            if nums[i] == nums[j - 1]:
                # this is a repeat
                c += 1
                if c < 3:
                    # two of any one number is ok
                    if i != j:
                        nums[j] = nums[i]
                    j += 1
            else:
                # not a repeat
                if i != j:
                    nums[j] = nums[i]
                j += 1
                c = 1
        return j

    @profile
    def removeDuplicates2(self, nums: List[int]) -> int:
        j = 1
        c = 1
        n = nums[0]
        for i in range(1, len(nums)):
            if nums[i] == n:
                # this is a repeat
                c += 1
                if c < 3:
                    # two of any one number is ok
                    if i != j:
                        nums[j] = nums[i]
                    j += 1
            else:
                # not a repeat
                if i != j:
                    nums[j] = nums[i]
                j += 1
                c = 1
                n = nums[i]
        return j


class SolutionTest(unittest.TestCase):
    def test_remove_duplicates(self):
        s = Solution()
        l = [1,1,1,2,2,3]
        k = s.removeDuplicates(l)
        self.assertEqual(l[:k], [1,1,2,2,3])

        l = [1,2,3]
        k = s.removeDuplicates(l)
        self.assertEqual(l[:k], [1,2,3])

        l = [1,1,1]
        k = s.removeDuplicates(l)
        self.assertEqual(l[:k], [1,1])

        l = [0,0,1,1,1,1,2,3,3]
        k = s.removeDuplicates(l)
        self.assertEqual(l[:k], [0,0,1,1,2,3,3])


if __name__ == '__main__':
    data = np.random.randint(0, 101, 10000)
    s = Solution()
    s.removeDuplicates(data)
    # stmt = lambda: s.removeDuplicates(data)
    # time_taken = timeit.timeit(stmt, number=10000)
    # print(f"Time taken: {time_taken:.5f} seconds.")
    
