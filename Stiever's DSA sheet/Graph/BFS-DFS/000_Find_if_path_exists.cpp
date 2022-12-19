/*

Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
*/


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        int len=edges.size();
        vector<bool>v(n,0);
        vector<int>total[n];
        for(int i=0;i<len;i++){
            total[edges[i][0]].push_back(edges[i][1]);
            total[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        q.push(source);
        while(!q.empty()){
            int p=q.front();
            q.pop();
            if(p==destination) return true;
            for(int i=0;i<total[p].size();i++){
                if(!v[total[p][i]]){
                    q.push(total[p][i]);
                    v[total[p][i]]=true;
                }
            }

        }
        return false;
    }
};
