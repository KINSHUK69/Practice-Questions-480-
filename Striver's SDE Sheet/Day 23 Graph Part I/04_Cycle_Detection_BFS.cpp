class Solution {
public:
    
  public:
    bool bfs(int src,vector<int>&vis,vector<int>adj[]){
        vis[src] = 1; 
        queue<pair<int,int>> q; 
        // <source,parent>
        q.push({src, -1}); 
        
        while(!q.empty()) {
            int node = q.front().first; 
            int parent = q.front().second; 
            q.pop(); 
            
            for(auto adjacentNode: adj[node]) {
                
                if(!vis[adjacentNode]) {
                    vis[adjacentNode] = 1; 
                    q.push({adjacentNode, node}); 
                }
                else if(parent != adjacentNode) {
                    return true; 
                }
            }
        }
        // there's no cycle
        return false; 
    }

    bool canFinish(int V,vector<int>adj[]) {
       vector<int>vis(V,0); 
       
       for(int i=0;i<V;i++) {
           if(!vis[i] && bfs(i,vis,adj)) return false;            
       }
       return true; 
    }
};
