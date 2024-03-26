class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans=0;

        for(int it:nums){
            if(s.find(it-1)==s.end()){
                int curr=it;
                int len=1;
                while(s.find(curr+1)!=s.end()){
                    curr+=1;
                    len+=1;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};
