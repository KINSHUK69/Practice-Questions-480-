/*
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)  // T.C. = O(n)  S.C. = O(1)
    {
       vector<int>ans(nums.size());
        int even=0,odd=1;
        for(auto i:nums)
        {
            if(i>0){
                ans[even]=i;
                even+=2;
            }
            if(i<0){
                ans[odd]=i;
                odd+=2;
            }
        }
        return ans;
    }
};
