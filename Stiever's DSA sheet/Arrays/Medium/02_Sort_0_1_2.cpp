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

// count sort T.C. = O(3n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,white=0,blue=0;
        for(auto it:nums){
            if(it==0)red++;
            if(it==1)white++;
            if(it==2)blue++;    
            
        }
        int i=0;
        while(red>0){
            nums[i++]=0;
            red--;
        }
        while(white>0){
            nums[i++]=1;
            white--;
        }
        while(blue>0){
            nums[i++]=2;
            blue--;
        }
    }
};
