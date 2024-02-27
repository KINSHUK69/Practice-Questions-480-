class Solution {
public:
// Tabulation
    int solve(vector<int>&nums,int n){
        int prev=nums[0];
        int prev2=0;

        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int notPick = prev;

            int curr= max(pick,notPick);
            prev2 = prev;
            prev = curr; 
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        vector<int>t1(nums.begin(),nums.end()-1);
        vector<int>t2(nums.begin()+1,nums.end());

        int x = solve(t1,n-1);
        int y = solve(t2,n-1);

        return max(x,y);
        
    }
};
