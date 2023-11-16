class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int>q;
	    vector<int>vis(V,0);
	    vector<int>indegree(V);
	    
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)q.push(i);
	    }
	    
	    vector<int>ans;
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0)q.push(it);
	        }
	    }
	    
	    return ans;
	    
	}
};
