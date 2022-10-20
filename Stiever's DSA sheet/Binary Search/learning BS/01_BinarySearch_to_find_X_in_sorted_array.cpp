class Solution {
public:
    
    int search(vector<int>& nums, int target)  // T.C. = O(logN)
    {
        int start=0,end=nums.size()-1,mid;
        
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target) return mid;
            else if(target >nums[mid]) start=mid+1;
            else end=mid-1;
        }
        
        return -1;
    }
    
    // USING STL            // T.C. = O(logN)
     int search(vector<int>& n, int t) 
     {
        return (binary_search(n.begin(),n.end(), t)) ? (lower_bound(n.begin(), n.end(), t) - n.begin()) : -1;
    }
};
