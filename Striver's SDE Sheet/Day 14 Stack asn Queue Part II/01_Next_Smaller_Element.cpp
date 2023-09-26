// using monotic increasing stack
// T.C. = O(n)
// S.C. = O(n)

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
    stack<int>s;
    vector<int>ans(n,-1);    
     
    for(int i=0;i<n;i++) {
        while(!s.empty() && s.top()>=A[i]){            
            s.pop();
        }
        if(!s.empty())ans[i]=s.top();
        
        s.push(A[i]);
    }
    
    return ans;
}
