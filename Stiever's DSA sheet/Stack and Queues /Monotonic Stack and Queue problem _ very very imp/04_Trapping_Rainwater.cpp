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
// Two pointer
// T.C. = O(n)
// S.C. = O(1)
class Solution {
public:
    int trap(vector<int>& h) {
        int ans=0,left=0,right=h.size()-1;
        int leftMax=0,rightMax=0; // to keep track of max from  left and right 

        while(left<=right){
            
            if(h[left]<=h[right]){   // then there exist an greater wall in the right of the index
                if(h[left]>=leftMax)
                    leftMax=h[left];
                else 
                    ans+=leftMax-h[left];

                left++;
            }
            else{                    // then there exist an greater wall in the left of the index
                if(h[right]>=rightMax)
                    rightMax=h[right];
                else
                    ans+=rightMax-h[right];

                right--;
            }
        }
        return ans;        
    }
};
