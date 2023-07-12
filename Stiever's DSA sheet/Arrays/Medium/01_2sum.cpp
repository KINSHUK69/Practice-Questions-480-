/*
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/
 vector<int> twoSum(vector<int>& nums, int target)    // T.C. = O(n^2)
    {
        vector<int> temp;
        for(auto i=0;i!=nums.size();i++)
        {
             for(auto j=0;j!=nums.size();j++)
             {
                 if(i!=j && nums[i]+nums[j]==target)
                 {
                    temp.push_back(j);
                    temp.push_back(i);
                     break;
                      
                 }
                  break;
            
             }
        
       }
        return temp;
}

vector<int> twoSum(vector<int>& nums, int target) // T.C. = O(n) S.C. = O(n)
{
        
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {                
                return {i,m[target-nums[i]};
            }
            else
            m[nums[i]]=i;
        }
        return {-1,-1};
    }
