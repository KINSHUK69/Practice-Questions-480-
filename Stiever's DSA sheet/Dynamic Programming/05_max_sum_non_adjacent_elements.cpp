class Solution {
public: 
    //   Using recursion
    //   T.C.= O(2^N)
    
    int choose(int i,vector<int>&nums){
        if(i==0)return nums[i];
        if(i<0)return 0;

        int pick = nums[i] + choose(i-2,nums);
        int notpick = choose(i-1,nums);

        return max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size()-1;        
        return choose(n,nums);
    }

   //   Using Tabulation   
   //   T.C.= O(N)
   //   S.C.= O(N)
   int rob(vector<int>& nums) {
        int n=nums.size();  
        vector<int>dp(n);  
        dp[0]=nums[0];

        for(int i=1;i<n;i++){
            int t = nums[i];
            if(i>1) t += dp[i-2];
            int nt = 0 + dp[i-1];
            dp[i]=max(t,nt);
        }
        return dp[n-1];
    }

    //   Using Space Optimization
    //   T.C.= O(N)
    //   S.C.= O(1)
   
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        
        for(int i=1;i<n;i++){
            int t=nums[i];
            if(i>1)t+=prev2;
            int nt=prev;
            int curr=max(t,nt);

            prev2=prev;
            prev=curr;
        }
        return prev;   // returned prev because we were returning dp[n-1] and dp [n-1] is nothing but prev
    }

};
