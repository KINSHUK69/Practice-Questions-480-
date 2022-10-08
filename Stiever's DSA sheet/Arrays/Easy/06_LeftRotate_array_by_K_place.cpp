/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        TIME LIMIT EXCEED  T.C.: O(n^2)
        while(k--)
        {
            int n=nums.size(),t=nums[n-1];
            for(int i=n-1;i>0;i--){
                nums[i]=nums[i-1];
            }
            nums[0]=t;    
            
        }        
        */
        
        //  T.C.: O(n)+O(k)+O(n-k) ~ O(n)
        
        k = k%nums.size(); // to prevent ambiguity as after some rotations the values after the rotation will start to   repeat
        
      
        reverse(nums.begin(),(nums.begin()+nums.size())-k);  //reverse the first part
        reverse(nums.size()-k,nums.end());                    // reverse the second part  
        reverse(nums.begin(),nums.end());                     // now reverse the whole array together
        
        
    }
};
