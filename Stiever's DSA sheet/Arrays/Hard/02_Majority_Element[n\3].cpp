class Solution {
public:
    // T.C. = O(N)
    // S.C. = O(N)
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto it:nums)mp[it]++;

        int n=nums.size();
        vector<int>ans;

        for(auto it:mp){
            if(it.second>n/3) ans.push_back(it.first);
        }
        return ans;
    }


    // T.C. = O(N)
    // S.C. = O(1)
    vector<int> majorityElement(vector<int>& nums) 
    {
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        int ctr1=0, ctr2=0;

        for(int i=0;i<nums.size();i++){
            if(ctr1 == 0 && ele2 != nums[i]){
                ctr1 = 1;
                ele1 = nums[i];
            }
            else if(ctr2 == 0 && ele1 != nums[i]){
                ctr2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1) ctr1++;
            else if(nums[i] == ele2) ctr2++;
            else {
                ctr2--;
                ctr1--;
            }
        }
        ctr1=0,ctr2=0;

        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            if(ele1==nums[i])ctr1++;
            if(ele2==nums[i])ctr2++;
        }
        int m = floor(nums.size()/3) +1;
        if(ctr1>=m) ans.push_back(ele1);
        if(ctr2>=m) ans.push_back(ele2);
        return ans;
   
    }

};
