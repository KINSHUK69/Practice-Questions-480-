/*
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

int maxSubArray(vector < int > & nums, vector < int > & subarray)    //  T.C. = O(N^3)
{
  int max_sum = INT_MIN;
  int n = nums.size();
  if (n == 1) {
    return nums[0];
  }
  int i, j;
  for (i = 0; i <= n - 1; i++) {
    for (j = i; j <= n - 1; j++) {
      int sum = 0;
      for (int k = i; k <= j; k++)
        sum = sum + nums[k];
      if (sum > max_sum) {
        subarray.clear();
        max_sum = sum;
        subarray.push_back(i);
        subarray.push_back(j);

      }
    }
  }
  return max_sum;
}


// KADAEN'S ALGORITHM
    
int maxSubArray(vector<int>& nums)     //  T.C. = O(N)
{
        int csum=0;
        int m=INT_MIN;
        for(auto it:nums)
        {
            csum+=it;
            m=max(m,csum);
            if(csum<0) csum=0;
        }
        return m;
    
}
