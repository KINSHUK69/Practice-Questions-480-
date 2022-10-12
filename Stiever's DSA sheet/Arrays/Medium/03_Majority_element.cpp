class Solution {
public:
    int majorityElement(vector<int>& nums)   //     T.C.= O(N)   S.C.= O(N)
    {
        unordered_map<int,int>m;
        for(auto it:nums)
        {
            //if(m.count(it)>floor((nums.size()-1)/2)) return it;
            m[it]++;
            if(m[it]>floor((nums.size()-1)/2)) return it;
        }
        return 0;
    }
};
