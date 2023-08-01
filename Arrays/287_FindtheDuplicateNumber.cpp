// backtracking
class Solution {
public:

    vector<vector<int>> ans;
    
    void backtrack(int idx, int k,vector<int>&temp,int n){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<n+1;i++){
            temp.push_back(i);
            backtrack(i+1,k,temp,n); 
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        backtrack(1,k,temp,n);
        return ans; 
    }
};
