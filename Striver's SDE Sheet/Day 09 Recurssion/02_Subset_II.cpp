class Solution {
public:
    void solve(vector<int>&arr,vector<vector<int>>&ans,vector<int>&dummy,int index,int n){
        ans.push_back(dummy);
        for(int i=index;i<n;i++){
            if(i!=index && arr[i]==arr[i-1])continue;
            dummy.push_back(arr[i]);        // pick
            solve(arr,ans,dummy,i+1,n);
            dummy.pop_back();               // not pick
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>dummy;
        sort(nums.begin(),nums.end());
        solve(nums,ans,dummy,0,nums.size());
        return ans;
    }
};
