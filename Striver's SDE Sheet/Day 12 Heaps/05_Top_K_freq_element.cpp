class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        if(k==nums.size())return nums;

        priority_queue<pair<int,int>>pq;  // element ,cout
        unordered_map<int,int>m;   
        vector<int>ans;

        for(auto it:nums) m[it]++;

        for(auto it:m) {
            pq.push({it.second,it.first});
            // cout<<it.second<<"second   "<<it.first<<"first  ";
        }

        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
