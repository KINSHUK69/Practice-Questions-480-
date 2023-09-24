// Brute Force : 
// T.C. = O(N^2)
// S.C. = O(1)   
// test cases passed - 37/51
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        
        for(int i=0;i<=n-k;i++){
            int j=i,ctr=k;
            int m=INT_MIN; 
            while(ctr--){
                m=max(nums[j],m);
                j++;
            }
            ans.push_back(m);
        }
        return ans;
    }
};
// Optimized :  Using Priority Queue
// T.C. = O(NlogN)
// S.C. = O(N)   
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++){
            while(!pq.empty() && pq.top().second<=i-k){
                pq.pop();
            }
            pq.push({nums[i],i});
            if(i>=k-1){
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};
// Optimized :  Using DeQueue
// T.C. = O(N)
// S.C. = O(N)   
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        for (int i=0;i<n;i++) {
            if (!dq.empty() && dq.front() == i-k) 
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
            if (i >= k - 1) 
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

