class Solution {
public:

    int helper(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        
        for(int i=1;i<n;i++){
            int t = nums[i];
            if(i>1) t += prev2;
          
            int nt = prev;
            int curr = max(t,nt);

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
      
        vector<int>t1(nums.begin(),nums.end()-1);
        vector<int>t2(nums.begin()+1,nums.end());

        int sum1 = helper(t1);
        int sum2 = helper(t2);

        return max(sum1,sum2);
    }
};
