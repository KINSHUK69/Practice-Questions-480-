class Solution {
public:
// USING DFS 
// T.C. = O(v+e)
// S.C. = O(v)
    void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,adj,vis);
        }
    }

    int findCircleNum(vector<vector<int>>& m) {
        int n=m.size();
        vector<int>vis(n,0);
        int ans=0;

        vector<int>adj[n];

        // converting adj matrix to adj list
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
        
    }

// USING BFS   
// T.C. = O(v+e)
// S.C. = O(v)
class Solution {
public:
    void bfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;

        queue<int>q;
        q.push(node);

        while(!q.empty()){
            int n=q.size();
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                if(!vis[it]) {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }        
        
    }

    int findCircleNum(vector<vector<int>>& m) {
        int n=m.size();
        vector<int>vis(n,0);
        int ans=0;

        vector<int>adj[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
        
    }
};
};
