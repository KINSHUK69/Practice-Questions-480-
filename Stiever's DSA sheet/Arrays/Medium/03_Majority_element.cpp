class Solution {
public:
    // Using Hashing 
    int majorityElement(vector<int>& nums)   //     T.C.= O(N)   S.C.= O(N)
    {
        unordered_map<int,int>m;
        for(auto it:nums)
        {
            //if(m.count(it)>floor((nums.size()-1)/2)) return it;
            m[it]++;
            if(m[it]>floor((nums.size()-1)/2)) return it;
        }
        return 0;
    }
    
    
    
    // Moore’s Voting Algorithm       
    //     T.C.= O(N)   S.C.= O(1)
    int majorityElement(vector<int>& nums) 
    {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if(num==candidate) count += 1; 
            else count -= 1; 
        }

        return candidate;
    }
};
