// Brute force
// T.C. = O(n)
// S.C. = O(2n)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,n=height.size();

        // for finding next greater element to left and right respectfully .
        vector<int>ngl(n),ngr(n); 
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,height[i]);
            ngl[i]=mx;
        }
        mx=0;
        for(int i=n-1;i>=0;i--){
            mx=max(mx,height[i]);
            ngr[i]=mx;
        }
         // sum up the water
        for(int i=0;i<n;i++){
            ans+= min(ngl[i],ngr[i])-height[i];
        }

        return ans;
        
    }
};
