/*
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

class Solution {
public:
  
    int climbStairs(int n) 
    {
        if(n<=2) return n;
        int a=1,b=2,ans;
        vector<int>dp(n+1);
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
            
        }
        return dp[n];
    }
    int climbStairs(int n) 
    {
        if(n<=2) return n;
        int a=1,b=2,ans;
        for(int i=3;i<=n;i++){
            ans=a+b;
            a=b;
            b=ans;
        }
        return ans;
    }
};
