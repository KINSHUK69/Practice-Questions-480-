vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int n=A.size();
    
    vector<int>ans;
    
    priority_queue<pair<int,pair<int,int>>>pq;  // sum , {index A, index B}
    
    set<pair<int,int>>s;  // {index A, index B}
    
    pq.push({A[n-1]+B[n-1],{n-1,n-1}});
    s.insert({n-1,n-1});
    
    while(C--){
        pair<int,pair<int,int>>temp=pq.top();
        pq.pop();
        ans.push_back(temp.first);
        
        int i=temp.second.first;
        int j=temp.second.second; 
        
        if(i-1>0){
            int sum=A[i-1]+B[j];
          
            if(s.find({i-1,j})==s.end()){
                pq.push({sum,{i-1,j}});
                s.insert({i-1,j});
            }
        }  
        if(j-1>0){
            int sum=A[i]+B[j-1];
            
            if(s.find({i,j-1})==s.end()){
                pq.push({sum,{i,j-1}});
                s.insert({i,j-1});
            }
        } 
    }
    return ans;
    
}
