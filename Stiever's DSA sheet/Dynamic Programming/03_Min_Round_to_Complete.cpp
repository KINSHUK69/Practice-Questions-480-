/*
MINIMUM ROUND TO COMPLETE
Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.
*/
class Solution {
public:
    /*
     vector<long long> dp;
    
     long long find(vector<int>& arr, int curr) 
     {
        
        int n = arr.size();
        if(curr == n)
            return 0;
        
        if(dp[curr] != -1)
            return dp[curr];
        
        long long minima = 1e9;
		
        if(curr + 2 < n && arr[curr] == arr[curr + 2]) {              // take three numbers at once
            minima = min(minima, 1LL + find(arr, curr + 3)) ;
        }
		
        if(curr + 1 < n && arr[curr] == arr[curr + 1]) {              // take two numbers at once
            minima = min(minima, 1LL + find(arr, curr + 2)) ;
        }
        
        return dp[curr] = minima ;                         
    }
    */
   
    
    int minimumRounds(vector<int>& tasks) {
        /*
        sort(tasks.begin(), tasks.end());
		
        dp.resize(tasks.size() + 1, -1);
        long long ans = find(tasks, 0);
        
        if(ans >= 1e9)
            return -1;
        return ans;
        */
    
        unordered_map<int, int> count;
        int res = 0, freq1;
        for (int a: tasks)
            ++count[a];
        for (auto& it: count) {
            if (it.second == 1) return -1;
            res += (it.second + 2) / 3;
        }
        return res;
        
    }
};
