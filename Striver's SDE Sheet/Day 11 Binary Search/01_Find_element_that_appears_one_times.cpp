class Solution {
public:
    // T.C. = O(N)
    // S.C. = O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int sum=0;
        for(int it:nums)sum^=it;
        return sum;
    }

    // Using BBinary Search 
    // T.C. = O(log N)
    // S.C. = O(1)

    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size() ;
        int left=0,right=n-2;

        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) 
                return nums[mid];
            else if( (mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1]) )     
                left=mid+1; 
            else right=mid-1;            
        }
        return -1;
    }
};
