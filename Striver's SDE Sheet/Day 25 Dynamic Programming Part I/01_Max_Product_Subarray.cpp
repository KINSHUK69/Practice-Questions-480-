class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        int curr=1;
        for(int it:nums){
            curr*=it;
            ans=max(ans,curr);
            if(curr==0) curr=1;
        }
        curr=1;
        reverse(nums.begin(),nums.end());
        for(int it:nums){
            curr*=it;
            ans=max(ans,curr);
            if(curr==0) curr=1;
        }
        return ans;
    }
};
