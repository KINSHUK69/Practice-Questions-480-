/*
Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
*/


class Solution {
public:

      void dfs(int i, vector<vector<int>> & rooms, vector<int> &vis)
      {
        vis[i]=1;
        for(auto key: rooms[i])
            if(!vis[key])dfs(key, rooms, vis);
      }
    
        bool canVisitAllRooms(vector<vector<int>>& rooms) 
        {
            vector<int> vis(rooms.size(), 0);
            
            dfs(0, rooms, vis);
            
            for(auto it:vis)
                if(!it) return false;
            
            return true;
            
        }
};


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        // using bsf
        vector<bool>vis(rooms.size(),0);
        vis[0]=1;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=1;

            for(auto it:rooms[node]){
                if(!vis[it]) q.push(it);
            }

        }
        for(auto it:vis) if(!it)return false;

        return true;
        
    }
};
