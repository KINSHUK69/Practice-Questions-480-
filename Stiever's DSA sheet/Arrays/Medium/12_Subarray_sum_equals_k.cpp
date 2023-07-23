/*
Input: nums = [1,2,3], k = 3
Output: 2
*/

// brute force T.C.=O(n^3)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int s=0;
                for(int k=i;k<j;k++){
                    s+=nums[k];
                }
                    if(s==k)ans++;
            }
        }
        return ans;

        
    }
};
