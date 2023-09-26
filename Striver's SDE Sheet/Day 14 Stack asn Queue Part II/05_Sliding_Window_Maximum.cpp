// Brute Force 
// T.L.E
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

// Optimal : Using Dequeue
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
