class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)   // T.C. = O(n)  S.C. = O(1)
    {
        int ctr=0,m=0;
        for(auto it:nums){            
            if(it==0)ctr=0;
            else ctr++;
            m=max(m,ctr);
        }
        return m;
    }
};
