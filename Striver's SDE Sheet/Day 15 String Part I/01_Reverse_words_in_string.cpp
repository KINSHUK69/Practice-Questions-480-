class Solution {
public:
    string reverseWords(string s) {    

      // Method 1 : Using stringstream 
        stringstream ss(s);
        string s1="",temp;
        while(ss>>temp)
        {
            s1=temp+" "+s1;
        }
        s1.erase(s1.end()-1);
        return s1;

    // Method 2 : Using pointers 
      
        int n=s.length();
        int right=n-1;
        int left=0;
        
        string ans="";
        string temp="";

        while(left<=right){
           if(s[left]!=' '){
               temp+=s[left];
           }
           else if(s[left]==' '){
               if(ans!="") ans=temp+" "+ans;
               else ans=temp;
               temp="";
           }
           left++;
        }
        if(temp!=""){
            if(ans!="")ans=temp+" "+ans;
            else ans=temp;
        }
        return ans;
        
    }
};
