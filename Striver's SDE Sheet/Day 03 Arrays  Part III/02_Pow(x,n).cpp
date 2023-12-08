class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        if(n==0) return double(1.0);
        if(n==1) return x;
        long long nn = n;
        if(n < 0) nn = -1*nn;
        while(nn){
            if(nn%2!=0){
                ans*=x;
                nn-=1;
            }else{
                x*=x;
                nn/=2;
            }
        }
        if(n < 0) ans = double(1.0)/double(ans);
        return ans;
    }
};
