class Solution {
public:
    bool check(string s,int l,int r){
        while(l<=r){
            if(s[l++]!=s[r--])return false;            
        }
        return true;
    }
    void solve(string &s,vector<vector<string>>&ans,vector<string>&ds,int i){
        
        if(i==s.length()){
            ans.push_back(ds);    
            return;
        }
        for(int j=i;j<s.length();j++){
            if(check(s,i,j)){
                ds.push_back(s.substr(i,j-i+1));
                solve(s,ans,ds,j+1);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>ds;
        solve(s,ans,ds,0);
        return ans;
    }
};
