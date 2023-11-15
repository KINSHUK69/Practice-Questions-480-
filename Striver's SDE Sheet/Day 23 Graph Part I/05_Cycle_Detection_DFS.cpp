class Solution {
public:
    
  public:
    bool dfs(int src,int parent,vector<int>&vis,vector<int>adj[]){
      
        vis[src] = 1;    
      
        for(auto it: adj[node]) {                
                if(!vis[it]) {
                    if(dfs(it,src,vis,adj)) return true;
                }
                else if(parent != it) return true;                 
            }
        }
       return false; 
    }

    bool canFinish(int V,vector<int>adj[]) {
       vector<int>vis(V,0); 
       
       for(int i=0;i<V;i++) {
           if(!vis[i] && dfs(i,-1,vis,adj)) return false;            
       }
       return true; 
    }
};
