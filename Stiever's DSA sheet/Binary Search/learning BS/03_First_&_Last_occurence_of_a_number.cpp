/*

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)    // T.C.= O(log n)
    {
        
        vector<int>ans(2,-1);
        int start=0,end=nums.size()-1;
        // starting position
        while(start<=end){
            int mid=start+(end-start)/2;
            
            
            if(nums[mid]<target) start=mid+1;
            else if(nums[mid]>target) end=mid-1;
                
            else{
                if(mid==start || nums[mid]!=nums[mid-1]){
                    ans[0]=mid;
                    break;
                }else{
                    end=mid-1;
                    ans[0]=end;
                }
                
            }
            
        }
        //last occurence
        start=0,end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(nums[mid]>target)end=mid-1;            
            else if(nums[mid]<target)start=mid+1;
            
            else{
                if(mid==end || nums[mid]!=nums[mid+1])
                {
                    ans[1]=mid;
                    break;
                }
                else{
                    start=mid+1;
                    ans[1]=start;
                }
            }
            
        }
        return ans;
    }
};
