class Solution {
public: 
    //  Using Sorting 
    //  T.C. = O(N log N)
    //  S.C. = O(1)
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }



    //  Using Priority Queue 
    //  T.C. = O(N log N)
    //  S.C. = O(N)
    int findKthLargest(vector<int>& nums, int k) {
        int ans=0;
        priority_queue<int>pq(nums.begin(),nums.end());
        while(k--){
            ans=pq.top();
            pq.pop();           
        }
        return ans;
    }

};
