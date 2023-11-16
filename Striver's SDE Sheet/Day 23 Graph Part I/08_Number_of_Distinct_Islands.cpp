class Solution {
public:

    void bfs(int &row,int &col,vector<vector<int>>&vis,vector<vector<char>>grid,int drow[],int dcol[]){

        vis[row][col]=1;

        int n=grid.size();
        int m=grid[0].size();        

        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty()){
            int crow=q.front().first;
            int ccol=q.front().second;
            q.pop();            
            
            for(int i=0;i<4;i++){
                int nrow=crow+drow[i];
                int ncol=ccol+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                    && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int row=0;row<n;row++){
            for( int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    ans++;                    
                    bfs(row,col,vis,grid,drow,dcol);
                }
            }
        }

        return ans;
    }
};
