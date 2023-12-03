class Solution {
public:
    // T.L.E 
    // T.C. = O(2^n)
    // S.C. = O(N)

    int solve(int i,int pre,vector<int>&nums,vector<int>&ds){
        if(i==nums.size())return 0;

        int len=solve(i+1,pre,nums,ds);
        if(pre==-1 || nums[i]>nums[pre]) 
            len=max(len,1+solve(i+1,i,nums,ds));
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ds;
        return solve(0,-1,nums,ds);
    }

    // Memoization
    // T.C. = O(N*N)
    // S.C. = O(N^2) + O(N)
    int solve(int i,int pre,vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size())return 0;

        if(dp[i][pre+1]!=-1)return dp[i][pre+1];

        int len=solve(i+1,pre,nums,dp);

        if(pre==-1 || nums[i]>nums[pre]) len=max(len,1+solve(i+1,i,nums,dp));
        
        dp[i][pre+1]=len;
        return dp[i][pre+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};
