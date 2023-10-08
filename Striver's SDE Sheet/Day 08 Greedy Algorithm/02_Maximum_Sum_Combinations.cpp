// TLE 
// O(N^2)+O(C+logN)

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int>ans;    
    priority_queue<int>pq;
    int n=A.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(A[i]+B[j]);
        }
    }
    while(C--){
        int num=pq.top();
        ans.push_back(num);
        pq.pop();
    }
    return ans;
}

// O(NlogN)+O(NlogN)+ O(C+logN)

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int n=A.size();
    
    vector<int >ans;
    
    priority_queue<pair<int,pair<int,int>>>pq;   // (sum, (i, j)) i and j are the indices
    
    set<pair<int,int>>s;   // (i, j) i and j are the indices  // set to store the indices so it does not repeat inside max heap.
    
    pq.push({A[n-1]+B[n-1],{n-1,n-1}});  // pushing the max sum with the indices
    s.insert({n-1,n-1});  // pushing the indices
    
    while(C--){
        pair<int,pair<int,int>>temp=pq.top();
        pq.pop();
        ans.push_back(temp.first);
        
        int i=temp.second.first;
        int j=temp.second.second; 
        
        if(i-1>0){
            int sum=A[i-1]+B[j];            
            pair<int,int>t1={i-1,j};

            // insert only if the pair (i - 1, j) is
            // not already present inside the map i.e.
            // no repeating pair should be present inside
            // the heap.
            if(s.find(t1)==s.end()){
                pq.push({sum,t1});
                s.insert(t1);
            }
        } 

      
        if(j-1>0){
            int sum=A[i]+B[j-1];
            pair<int,int>t1={i,j-1};

            // insert only if the pair (i, j - 1)
            // is not present inside the heap.
            if(s.find(t1)==s.end()){
                pq.push({sum,t1});
                s.insert(t1);
            }
        }            
        
    }
    return ans;
    
}

