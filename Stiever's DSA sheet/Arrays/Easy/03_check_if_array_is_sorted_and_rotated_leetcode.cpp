/*
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]) c++;
        }
        if(c<=1)return true;  // or we can also do | return(c<=1);  | <=1 as we are in a cycle , so 1 time will be a cycle and >1 will be not sorted
        return false;
        
    }
};
