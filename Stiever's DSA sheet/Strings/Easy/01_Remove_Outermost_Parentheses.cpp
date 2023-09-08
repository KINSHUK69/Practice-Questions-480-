// T.C. = O(N)

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int ctr=0;
        for(auto it:s){
            if(it=='(' && ctr++ >0) ans+=it;
            if(it==')' && ctr-- >1) ans+=it;
        }
        return ans;
    }
 
    //  or

    string removeOuterParentheses(string s) {
        string res;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' && count==0)
                count++;
            else if(s[i]=='(' && count>=1){
                res+=s[i];
                count++;
            }   
            else if(s[i]==')' && count>1){
                res+=s[i];
                count--;
            }
            else if(s[i]==')' && count==1)
                count--;
        }
        return res;
    }
};
