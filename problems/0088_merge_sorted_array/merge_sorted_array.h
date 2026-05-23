// class Solution:
//     def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) ->
//     None:
//         """
//         Do not return anything, modify nums1 in-place instead.
//         """
//         i = m - 1
//         j = n - 1
//         k = n + m - 1
//         while i >= 0 and j >= 0:
//             if nums1[i] >= nums2[k]:
//                 nums1[k] = nums1[i]
//                 i--
//             else:
//                 nums1[k] = nums2[j]
//                 j--
//         while j >= 0:
//             nums1[k] = nums2[j]
//             j--

#include <vector>

class Solution {
public:
  void merge() {
    // TODO(jcarreiro): port this one from python to C++
  }
};