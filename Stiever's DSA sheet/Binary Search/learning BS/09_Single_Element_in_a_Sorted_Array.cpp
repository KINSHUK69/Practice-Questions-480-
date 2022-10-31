/*
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)   // T.C. = O(n)  S.C. = O(n)
    {
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==1) return nums[i];
        }
        
        return -1;
    }
};
