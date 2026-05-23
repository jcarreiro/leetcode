// class Solution:
//     def removeDuplicates(self, nums: List[int]) -> int:
//         j = 1
//         for i in range(1, len(nums)):
//             if nums[i] != nums[j - 1]:
//                 if i != j:
//                     nums[j] = nums[i]
//                 j += 1
//         return j

#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int j = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[j - 1]) {
        if (i != j) {
          nums[j] = nums[i];
        }
        j++;
      }
    }
    return j;
  }
};