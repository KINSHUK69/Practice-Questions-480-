// TLE :
// 94/99 test cases passed
class StockSpanner {
public:
    int ctr;
    stack<int>s1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        s1.push(price);
        stack<int>s2=s1;
        ctr=0;
        while(!s2.empty()){
            int prev=s2.top();
            if(price>=prev){
                ctr++;
                s2.pop();                
            }
            else break;
        }
        return ctr;
    }
};

// Optimal Solution : Monotonic Stack
//  Amortized : O(1)
class StockSpanner {
public:
    stack<pair<int,int>>st; // count,price
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=1;
        while(!st.empty() && st.top().second<=price){
            ans+=st.top().first;
            st.pop();
        }
        st.push({ans,price});
        return ans;
    }
};
