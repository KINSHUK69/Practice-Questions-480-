// T.C. = O(m * n) 
class Solution {
public:
    int strStr(string haystack, string needle) {
       int n=haystack.find(needle);
       if(n==string::npos) return -1;
       return n;
    }
};

class Solution {
public:
// Z Algorithm for string matching
// T.C. = O(m+n) 
// S.C. = O(m+n)
    void createZ(string s,vector<int>&Z){
        int n=Z.size();
        int L,R,k;
        L=R=0;
        for(int i=1;i<n;i++){
          // if i>R nothing matches so we will calculate.
          // Z[i] using naive way.
            if(i>R){
                L=R=i;
                while(R<n && s[R]==s[R-L]) R++;
              
                Z[i]=R-L;
                R--;
            }
            else{
                k=i-L;                   // because str[i..] matches with str[K..] for atleast R-i+1 characters 
                                         // (they are in [L,R] interval which we know is a prefix substring)

                if(Z[k]<R-i+1) Z[i]=Z[k];  // If Z[K] < R-i+1  then there is no prefix substring starting at 
                                           // str[i] (otherwise Z[K] would be larger)  so  Z[i] = Z[K]  and 
                                           // interval [L,R] remains same.

                else {                     // it is possible to extend the [L,R] interval
                                           // thus we will set L as i
                    L=i;
                    while(R<n && s[R-L]==s[R]) R++;
                  
                    Z[i]=R-L;
                    R--;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
      
        string z=needle+"*"+haystack;
        vector<int>Z(z.size(),0);

        createZ(z,Z);
        for(int i=0;i<z.size();i++){
            if(Z[i]==needle.size()) return (i-needle.size()-1);
        }
        return -1; 
    }
};
