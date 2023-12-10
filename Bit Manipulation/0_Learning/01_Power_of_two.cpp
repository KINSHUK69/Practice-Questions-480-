class Solution {
public:
    //  Using Reminder-divident method
    // T.C. = O(log N)
    // S.C. = O(1)
    bool isPowerOfTwo(int n) {    
        if(n<0 || n==0)return false;    
        while(n%2==0) n/=2;
        return n==1;
    }

    // Using BitWise Operation
    // bit representation of 7  -> 0111
    // bit representation of 8  -> 1000
    // bitwise AND of 7 and 8 -> 0000
    // T.C. = O(1)
    // S.C. = O(1)
    bool isPowerOfTwo(int n) {    
        return n>0 && (n & n-1)==0;
    }
};
