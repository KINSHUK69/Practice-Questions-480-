/*
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

*/
 // used monotonic stack 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>s;
        vector<int>ans(t.size(),0);
        for(int i=0;i<t.size();i++){
            while(!s.empty() && t[i]>t[s.top()]){   // pop till current temp < stack's top's temp. This maintains monotonic stack
                ans[s.top()]=i-s.top();
                s.pop();                           // cur day will be next warmer day for each element that's popped
            }
            s.push(i);                            // push onto stack to find next warmer day for cur later on
            
        }return ans;
    }
};
