// recursion 
int solve(int n,int k,vector<int>&height){
    if(n==0) return 0;
    int m=INT_MAX;

    for(int i=1;i<=k;i++) {
        if(n-i>=0)        
        m = min(m,solve(n-i,k,height)+abs(height[n]-height[n-i]));
    }
    return m;
}
int minimizeCost(int n, int k, vector<int> &height){
    int ans= solve(n-1, k, height);
    return ans;
}

// Memoization 
int solve(int n,int k,vector<int>&height,vector<int>&dp){
    if(n==0) return 0;
    if(dp[n]!=-1)return dp[n];
    int m=INT_MAX;

    for(int i=1;i<=k;i++) {
        if(n-i>=0)        
        m = min(m,solve(n-i,k,height,dp)+abs(height[n]-height[n-i]));
    }   
    return dp[n]=m;
}
int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n,-1);
    return solve(n-1, k, height,dp);
}

// Tabulation 
int solve(int n,int k,vector<int>&height,vector<int>&dp){
    if(n==0) return 0;
    if(dp[n]!=-1)return dp[n];
    int m=INT_MAX;

    for(int i=1;i<=k;i++) {
        if(n-i>=0)        
        m = min(m,solve(n-i,k,height,dp)+abs(height[n]-height[n-i]));
    }   
    return dp[n]=m;
}
int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n,-1);
    dp[0]=0;

    for(int i=1;i<n;i++){
        int m=INT_MAX;

        for(int j=1;j<=k;j++){
            if(i-j>=0) m = min(m, dp[i-j]+abs(height[i]-height[i-j]));
        }
        dp[i]=m;
    }
    return dp[n-1];
}
