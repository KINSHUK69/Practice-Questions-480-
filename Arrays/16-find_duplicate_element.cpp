class Solution {
public:
    // used linked list cycle method to create a cycle.
  //tortoise approach to solve this problem by taking two pointers one is slow and other one is fast , then traverse through the created linked list cycle and when the slow pointer meets the fast pointer the element at the slow pointer will be the duplicate element
    int findDuplicate(vector<int>& nums) {  
       int s=nums[0];   //slow pointer
        int f=nums[0];  //fast pointer
        do{
            s=nums[s];            //moves by one
            f=nums[nums[f]];      //moves by two
        }while(s!=f);
        f=nums[0];
        while(s!=f){
            s=nums[s];
            f=nums[f];            
        }
        return s;
    }
};
