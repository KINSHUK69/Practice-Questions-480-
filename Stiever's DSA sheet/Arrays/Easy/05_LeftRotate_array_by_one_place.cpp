/*
Input: [1,2,3,4,5]
Output: [2,3,4,5,1]
*/

void rotate(vector<int>& nums) {

        
            int n=nums.size(),t=nums[n-1];
            for(int i=n-1;i>0;i--){
                nums[i]=nums[i-1];
            }
            nums[0]=t;    
            
        }
