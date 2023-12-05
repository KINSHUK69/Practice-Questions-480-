class Solution {
public:
    // T.C. = O(N log N)
    // S.C. = O(1)
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0; 

        int prev=INT_MIN,ctr=0,longest=1;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            if(nums[i]-1 == prev){
                prev=nums[i];
                ctr++;
            }
            else if(nums[i]!= prev){
                ctr=1;
                prev=nums[i];
            }
            longest=max(longest,ctr);
        }
        return longest;
    }

    // T.C. = O(N)
    // S.C. = O(N)
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0; 

        unordered_set<int>s(nums.begin(),nums.end());        

        int longest = 1;

        for(auto it:s){
            if(s.find(it-1)==s.end())
            {
                int ctr = 1;
                int ele = it;
                while(s.find(ele+1)!=s.end()){
                    ele = ele+1;
                    ctr++;
                }
                longest= max(longest,ctr);
            }
        }
        return longest;       
    }
};
