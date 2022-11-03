class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;
        // return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        
        
        /*
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-3]+dp[i-1]+dp[i-2];
        }
        return dp[n];
        */
        
        int a=0,b=1,c=1,ans=0;
        for(int i=3;i<=n;i++){
            ans=a+b+c;
            a=b;
            b=c;
            c=ans;
        }
        return ans;
        
       
    }
};
