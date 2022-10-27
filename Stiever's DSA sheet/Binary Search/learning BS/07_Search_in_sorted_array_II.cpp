/*
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
*/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int start=0,end=nums.size()-1,mid=0;
        while(start<=end){
            
            mid=(start+end)>>1;
            if(nums[mid]==target) return true;
            
             if(nums[mid]==nums[start] && nums[end]==nums[mid]){
                start++; end--;continue;
            }
            if(nums[start]<=nums[mid]){
                if(nums[start]<=target && nums[mid]>=target) end=mid-1;
                else start=mid+1;
                
            }
            else {
                if(nums[end]>=target && nums[mid]<=target) start=mid+1;
                else end=mid-1;
            }
        }
        return false;
    }
};
