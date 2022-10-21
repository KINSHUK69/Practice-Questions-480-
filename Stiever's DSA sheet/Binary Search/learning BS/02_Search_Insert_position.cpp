/*

*/



/*
Because when high = low+1, then mid = low.
If the target > nums[mid], then low = mid + 1 = high. The target position can be low or high, since they are the same.
but if the target < nums[mid], then high = mid - 1 = low - 1. The target position must be low,
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)    // T.C. = O(logN)
    {
         int start=0,end=nums.size()-1,mid;
        
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target) return mid;
            else if(target >nums[mid]) start=mid+1;
            else end=mid-1;
        }
        
        return start;
    }
  
  
// USING STL LOWER BOUND                 // T.C. = O(logN)
int searchInsert(vector<int>& nums, int target) 
{
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}
};

