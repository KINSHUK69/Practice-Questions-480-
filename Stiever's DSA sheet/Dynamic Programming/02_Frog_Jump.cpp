#include <bits/stdc++.h>  
// Memoization
int solve(int n,vector<int>&h,vector<int>&dp){
    if(n==0){
        dp[0]=0;
        return 0;
    }
    if(dp[n]!=-1)return dp[n];
    int left=solve(n-1,h,dp)+abs(h[n]-h[n-1]);
    int right=INT_MAX;
    if(n>1)right=solve(n-2,h,dp)+abs(h[n]-h[n-2]);
    dp[n]= min(left,right);
    return dp[n];
}

// Tabulation
int frogJump(int n, vector<int> &h)
{
    vector<int>dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int left = dp[i-1]+abs(h[i]-h[i-1]);
        int right=INT_MAX;
        if(i>1) right = dp[i-2]+abs(h[i]-h[i-2]);
        dp[i]=min(left,right);
    }
    return dp[n-1];
}

// Space Optimization
int frogJump(int n, vector<int> &h)
{
    // vector<int>dp(n+1,-1);
    int prev1=0,prev2=0;
    int ans=0;
    for(int i=1;i<n;i++){
        int left = prev1+abs(h[i]-h[i-1]);
        int right=INT_MAX;
        if(i>1) right = prev2+abs(h[i]-h[i-2]);
        ans=min(left,right);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
