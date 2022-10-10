class Solution {
public:
    int subarraySum(vector<int>& nums, int k)   // T.C. = O(n^3)   S.C. = O(1)
    {
        int n=nums.size(),ctr=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int sum=0;
                for(int k=i;k<j;k++)
                {
                    sum+=nums[k];
                }
                if(sum==k)ctr++;
            }
        }
        return ctr;
    }
  int subarraySum(vector<int>& nums, int k)  // T.C. = O(n^2)   S.C. = O(n)
  {
        int n=nums.size(),ctr=0;
        
        vector<int>a(n+1);
        a[0]=0;
        for(int i=1;i<=n;i++) 
            a[i]=a[i-1]+nums[i-1];
        for(int start=0;start<n;start++)
        {
            for(int end=0;end<=n;end++)
            {
                if(a[end]-a[start]==k)ctr++;
            }
        }
        return ctr;
    }
   int subarraySum(vector<int>& nums, int k) // T.C. = O(n)   S.C. = O(n)
   
   {
        unordered_map<int,int> map;
        
        int sum = 0, result = 0;
        map[sum] = 1;
        
        for (int n : nums) {
            sum += n;
            result += map[sum - k];
            map[sum]++;
        }
        
        return result;
    }
};
