class Solution {
public:
    int singleNumber(vector<int>& nums)  // T.C. = O(n) S.C. = O(1)
    {
        int r=0;
        for(auto it:nums) r^=it;     // xor of two similar number is 0
        return r;
    }
};
