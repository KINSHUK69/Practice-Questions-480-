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
