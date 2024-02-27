class Solution {
public:
// Memoization
    int solve(int n,vector<int>& nums,vector<int>& dp){
        if(n==0)return nums[0];
        if(n<0)return 0;

        if(dp[n]!=-1)return dp[n];
        int pick = nums[n] + solve(n-2,nums,dp);
        int notpick  = solve(n-1,nums,dp);
        return dp[n]=max(pick,notpick);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
    }
// Tabulation 
 int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<0)return 0;
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1)pick+= dp[i-2];
            int notPick = 0 + dp[i-1];
            dp[i]= max(pick,notPick);
        }
        return dp[n-1];
    }
// Space optimization
int rob(vector<int>& nums) {

        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int notPick = 0 + prev;
            int curr = max(pick,notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
