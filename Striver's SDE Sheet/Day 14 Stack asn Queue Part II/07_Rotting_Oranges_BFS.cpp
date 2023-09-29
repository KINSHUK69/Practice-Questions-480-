class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time=-1;

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>visited=grid;
        int fresh=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==2) q.push({i,j});
                if(visited[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        if(q.empty()) return -1;

        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,-1},{0,1}}; // up, down, left, right
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                for(auto [dx,dy] : dir){
                    int i = x + dx;
                    int j = y + dy;
                    if(i>=0 && i<m && j>=0 && j<n && visited[i][j]==1){
                        visited[i][j] = 2;
                        fresh--;
                        q.push({i,j});
                    }
                }
            }
            time++;
        }

        if(fresh==0) return time;

        return -1;        
        
    }
};
