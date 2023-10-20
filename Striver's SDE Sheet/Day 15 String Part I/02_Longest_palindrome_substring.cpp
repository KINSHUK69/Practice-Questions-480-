class Solution {
public:
    // METHOD 1 : TLE

    bool check(string s){
        int start=0,end=s.size()-1;
        while(start<=end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }

    void Substrings(string str,vector<pair<string,int>>&arr)
    {
    
        
        for (int i = 0; i < str.length(); i++) {
            string subStr;
            
            for (int j = i; j < str.length(); j++) {
                subStr += str[j];
                // cout<<subStr<<endl;
                if(check(subStr)){
                    arr.push_back({subStr,subStr.size()});
                }
            }
        }
    }

    string longestPalindrome(string s) {
        vector<pair<string,int>>arr;
        Substrings(s,arr);
        priority_queue<pair<int,string>>pq;
        for(auto it:arr){
            pq.push({it.second,it.first});
        }
        return pq.top().second;
    }

    // METHOD 2 :  RECURSIVE     TLE
    
    string longestPalindrome(string s)
    {
        int n=s.size();
        if(n==0)
            return "";

        if(n==1)
            return s;

        string result="";
        for(int i=0;i<n-1;i++)
        {
            for(int j=1;j<=n-i;j++)
            {
                if(check(s.substr(i,j)))
                {
                    if(result.size()<j)
                        result=s.substr(i,j);
                }
            }
        }
        return result;
    }
    

    // METHOD #: Using D.P. 
    string longestPalindrome(string s) {
        int n=s.size();
        if (n==0) return "";

        bool dp[n][n];        
        memset(dp, 0, sizeof(dp));

        for (int i=0;i<n;i++)
            dp[i][i]=true;

        string ans = "";
        ans += s[0];

        for (int i=n-1;i>=0;i--){
            for (int j=i+1;j<n;j++){
                if (s[i]==s[j]){
                    if (j-i==1 || dp[i+1][j-1])
                    {
                        dp[i][j] = true;
                        if (ans.size() < j-i+1)
                            ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
        return ans;
    }

 // Manacher's Algorithm : T.C. : O(2n+1) => O(n)
    string convert(string s){
        string str;
        for(auto c:s){
            str+=string("#")+c;
        }
        return str+"#";
    }
    string longestPalindrome(string s) {
        string str=convert(s);
        str="$"+str+"^"; // for parity handling both odd and even cases
        
        int n=str.length();
        vector<int> P(n); // Array to store palindrome lengths;
       
       int l=1,r=1;
       int maxLen=0,maxCenter=0;

       for(int i=1;i<n;i++){

           P[i]=max(0,min(r-i,P[l+(r-i)]));

           while(str[i-P[i]-1] == str[i+P[i]+1])  P[i]++;           

           if(i+P[i] > r) l=i-P[i], r=i+P[i];           

           if(P[i]>maxLen) maxLen=P[i], maxCenter=i;           
       }
       int start=(maxCenter-maxLen)/2;
       return s.substr(start,maxLen);
    }
};
