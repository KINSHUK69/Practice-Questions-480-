/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/
class Solution {
public:
    int search(vector<int>& nums, int target) // T.C. = O(log N)
    {
        int s=0,e=nums.size()-1,m=0;
        while(s<=e){
            m=s+(e-s)/2;
            if(nums[m]==target) return m;
         
          // dividing the arrau into two parts which are like sorted induidally.  [4,5,6,7] [0,1,2]
           
          if(nums[s]<=nums[m]){
                if(nums[s]<=target && nums[m]>=target) e=m-1;
                else s=m+1;
            }
            else{
                if(nums[m]<=target && nums[e]>=target) s=m+1;
                else e=m-1;
            }
        }
        return -1;
    }
};
