/*
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)   // T.C. = O(n)  S.C. = O(n)
    {
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==1) return nums[i];
        }
        
        return -1;
    }
    
    int singleNonDuplicate(vector<int>& nums) // T.C. = O(n)  S.C. = O(1)
    {
        int sum=0;
        for(auto it:nums) 
            sum^=it;
        
        return sum;
    }
    
    /*
    So, the array has all the elements repeating twice except for one element which appears only once and the array is sorted.
    This means that in every number that's repeated, the first number is at an even index (index%2==0) and the 2nd number is at an odd index.
    The idea is to peform a binary search over the entire array and find out if this pattern follows. 
       ->If somewhere this pattern is broken, then we're going to know in which half of the array there is an element that appears only once.
    We reduce the search space to that half an search again, until we're left with a single element, which is the final answer
    */
    int singleNonDuplicate(vector<int>& nums) 
    {
        if(nums.size()==1) return nums[0];
        int start=0, end=nums.size()-1, mid, num;
        
        while(start < end){
            mid = (start+end)>>1;
            num = (mid%2 == 0) ? mid+1 : mid-1;
            if(nums[mid]==nums[num]) start = mid+1;
            else end = mid;
        }
        return nums[start];
    }
};
