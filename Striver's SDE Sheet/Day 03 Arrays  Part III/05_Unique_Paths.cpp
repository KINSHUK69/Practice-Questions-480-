class Solution {
public:
    // USING RECURSION  (T.L.E.)    
    int solve(int &m,int &n,int i,int j){
        if(i>=m || j>=n) return 0;
        if(i==m-1 || j==n-1) return 1;

        return solve(m,n,i+1,j) + solve(m,n,i,j+1);
    }
    int uniquePaths(int m, int n) {
        int ans = solve(m,n,0,0);
    }
    // USING D.P. MEMOIZATION 
    // T.C. = O(N^2)
    // S.C. = O(m*n)   + O(m*n)  for stack and for 2d dp array
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i>=m || j>=n)return 0;
        if(i==m-1 || j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }

    // USING D.P. TABULATION
    // T.C. = O(N^2)
    // S.C. = O(m*n)  just for 2d dp
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        return dp[m-1][n-1];
    }
};
