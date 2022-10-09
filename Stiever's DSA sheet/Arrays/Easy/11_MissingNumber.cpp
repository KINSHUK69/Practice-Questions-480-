/*
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
*/
class Solution {
public:
    int missingNumber(vector<int>& nums)     // T.C.: O(nlog(n))+O(n)   S.C.: O(1)
    {
        int n=0;
        sort(nums.begin(),nums.end());
        for(auto it:nums){
            if(n==it){
                n++;
            }             
        }
        if(nums.size()>n) return n;
        else if(nums.size()==n) return nums.size();
        else return 0;
    }
  
  
  int missingNumber(vector<int>& nums)  // T.C.: O(n)   S.C.: O(1)
  {
        int s=0;
        int tsum=(nums.size()*(nums.size()+1))/2;
        for(auto it:nums){
            s+=it;
        }
        return tsum-s; 
   }
};
