// BruteForce 
// T.C. = O(N^2)
// S.C. = O(1)
// 89 / 98 testcases passed
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n=heights.size();
        int maxArea=0;

        for(int i=0;i<n;i++){
            int h = INT_MAX;
            for(int j=i;j<n;j++){
                minH=min(h,heights[j]);
                maxArea=max(maxArea,h*(j-i+1));
            }           
        }    
        return maxArea; 
    }
};
// Optimal Approach 
// T.C. = O(N)
// S.C. = O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int>stack;
        for (int i = 0; i < heights.size(); ++i) {
            while (!stack.empty() && heights[i] < heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            int height = heights[stack.top()];
            stack.pop();
            int width = stack.empty() ? heights.size() : heights.size() - stack.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        return maxArea;
    }
};
