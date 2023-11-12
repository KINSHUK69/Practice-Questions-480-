class Solution {
public:
    void solve(vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds,int i,int n,int target){
        if(!target){
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<n;j++){
            if(j>i && arr[j]==arr[j-1])continue;
            if(arr[j]>target)break;
            ds.push_back(arr[j]);
            solve(arr,ans,ds,j+1,n,target-arr[j]);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        solve(candidates,ans,ds,0,candidates.size(),target);
        return ans;
    }
};
