class Solution {
public:
    int findPeakElement(vector<int>& nums)    // T.C. = O(n)
    {
        int ans=0;
        int n=nums.size();
        
        if(n==1) return 0;
       
            
        if(nums[0]>nums[1]) return 0;
            
        if (nums.back() > nums[n-2]) return n-1;
        
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1])
            {
                ans=i;
                return i;
                break;
            }
        }        
        return -1;
                             
    }
  /*
  If nums[mid] < nums[mid+1], then there has to be a peak element in the right side of mid.
  Either the numbers increase until we reach the end and then the last element will be a peak, or at some point a number gets smaller and right there we will have a peak.
  Same for the left side of mid.
  */
  int findPeakElement(vector<int>& nums) 
  {
        int start = 0, end = nums.size()-1, mid;
        
        while (start < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] < nums[mid + 1]) 
                start = mid + 1;
            else end = mid;
        }
        
        return start;
    }
};
