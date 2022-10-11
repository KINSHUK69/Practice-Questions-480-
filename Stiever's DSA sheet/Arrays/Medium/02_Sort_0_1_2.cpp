/*
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/


class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
       // sort(nums.begin(),nums.end());         // T.C. = O(NlogN)
      
          
      int l=0,m=0,h=nums.size()-1;              // T.C. = O(N)           three pointer approach
        
        while(m<=h){           
            
            switch(nums[m]){
                case 0:
                    swap(nums[l++],nums[m++]);
                    break;
                case 1:
                    m++;
                    break;
                case 2:
                    swap(nums[m],nums[h--]);
                    break;
            }
        }
    }
};
