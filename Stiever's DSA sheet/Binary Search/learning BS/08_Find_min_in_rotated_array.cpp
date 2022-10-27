/*
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
*/
class Solution {
public:
    int findMin(vector<int>& nums)  // T.C. = O(NlogN)
    {
        sort(nums.begin(),nums.end());
        return nums[0];
    }
  
};
