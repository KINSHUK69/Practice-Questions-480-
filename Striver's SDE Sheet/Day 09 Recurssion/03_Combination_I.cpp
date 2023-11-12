class Solution {
public:
  // METHOD 1 :  Without looping
    void solve(vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds,int i,int target){
        if(i==arr.size()){
            if(target==0)ans.push_back(ds);
            return;
        }
        if(arr[i]<=target){
            ds.push_back(arr[i]);
            solve(arr,ans,ds,i,target-arr[i]);
            ds.pop_back();
        }
        solve(arr,ans,ds,i+1,target);    
              
    }
    // METHOD 2  : With Looping
    void solve(vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds,int i,int target){
        if(!target){
            ans.push_back(ds);
            return;
        }

        for(int j=i;j!=arr.size() && arr[j]<=target;j++){
            ds.push_back(arr[j]);
            solve(arr,ans,ds,j,target-arr[j]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(candidates,ans,ds,0,target);
        return ans;
    }
};

   
