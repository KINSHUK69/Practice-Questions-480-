
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int>q;
        vector<int>vis(V,0);
        vector<int>ans;
        
        vis[0]=1;
        q.push(0);
        
        while(!q.empty()){
            int i=q.front();
            ans.push_back(i);
            q.pop();
            
            for(auto it:adj[i]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
            
        }
        return ans;
    }
};
