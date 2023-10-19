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
