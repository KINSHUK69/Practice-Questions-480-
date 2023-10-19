class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s1="";
        int count=0;
        while(s1.size()<b.size()){
            s1+=a;
            count++;
        }   
        
        if(s1.find(b)!=string::npos)
          return count;
      
        /*
          We don't need to keep adding more repetitions of a after this. 
          If b isn't found in s1 with a length of 2 * len(b) or slightly more, 
          it won't be found in any number of further repetitions. 
        */
        s1+=a;
        count++;
      
        if(s1.find(b)!=string::npos)
          return count;
      
        return -1;
    }
};

// Using Rabin Karp Algo for String matching creating hash funtion for a and b and only checking the substring when the hash function matches 
#define ll long long
class Solution {
public:

    bool RabinKarp(string source,string target){
        ll p=31, m=1e9 + 9;
        int S=source.size(), T=target.size();
        
        vector<ll> power(max(S,T), 1);

        for(int i=1;i<power.size(); i++){
            power[i]=(power[i-1] * p) % m;
        }

        vector<ll> H(T + 1, 0);
        for(int i=0;i<T;i++){
            H[i+1]=(H[i] + (target[i]-'a'+1) * power[i]) % m;
        }
        
        ll HS=0;

        for(int i=0;i<S;i++){    
            HS=(HS + (source[i]-'a'+ 1)*power[i]) % m;
        }
        
        ll currHS=0;
        for(int i=0;i+S<=T;i++)
        {
            currHS=(H[i+S] - H[i] + m) % m;
            if(currHS == HS*power[i]%m)
                return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {       
        if(a==b)
        return 1;

        int count=1;
        string s=a;

        while(s.size()<b.size()){
            s+=a;
            count++;
        }
        if(s==b) return count;
        if(RabinKarp(b,s)) return count;
        if(RabinKarp(b,s+a)) return count+1;

        return -1;
    }
};
