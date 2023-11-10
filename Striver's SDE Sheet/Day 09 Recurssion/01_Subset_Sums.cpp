class Solution
{
public:
    void solve(vector<int>&arr,vector<int>&dummy,vector<int>&ans,int i,int &n){
        if(i==n) {
            int sum=0;
            for(auto it:dummy)sum+=it;
            ans.push_back(sum);
            return;
        }
        
        dummy.push_back(arr[i]);
        solve(arr,dummy,ans,i+1,n);
        dummy.pop_back();
        solve(arr,dummy,ans,i+1,n);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        vector<int>dummy;
        solve(arr,dummy,ans,0,N);
        return ans;
    }
};
