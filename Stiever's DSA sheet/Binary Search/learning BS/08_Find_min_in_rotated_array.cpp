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
    
    int findMin(vector<int>& nums) // T.C. = O(logN)
    {
        // loop            1. low < high
        //                 2. mid != high and thus A[mid] != A[high] (no duplicate exists)
        //                 3. minimum is between [low, high]
        int start=0,end=nums.size()-1,mid;
        while(start<end){
            mid=(start+end)>>1;
            if(nums[mid]<nums[end]) end=mid;            // the mininum is in the left part
            if(nums[mid]>nums[end]) start=mid+1;        // the mininum is in the right part           
        }
        return nums[start];
    }
  
};
