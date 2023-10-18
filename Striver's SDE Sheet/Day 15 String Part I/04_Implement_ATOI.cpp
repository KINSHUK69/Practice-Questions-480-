class Solution {
public:
    bool isDigit(char ch){
        return ch >= '0' && ch <= '9';
    }
    int myAtoi(string s) {
      
        const int l=s.size();
        if(l==0) return 0;
        int i=0;
        
        while(i<l && s[i]==' ') ++i;

        bool isNegative = false;

        if(i<l){
            if(s[i]=='-'){
                isNegative=true;
                ++i;
            } 
            else if(s[i]=='+') ++i;
        }

        int ans=0;
        while(i<l && isDigit(s[i])){
            int digit = s[i] - '0';
            if(ans > (INT_MAX / 10) || (ans == (INT_MAX / 10) && digit > 7)){
                return isNegative ? INT_MIN : INT_MAX;
            }
            ans=(ans*10)+digit; 
            ++i;
        }
        
        return isNegative ? -ans : ans;
  }
};
