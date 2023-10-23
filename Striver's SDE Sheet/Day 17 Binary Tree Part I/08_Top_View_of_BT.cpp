class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(!root) return ans;
        
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        
        q.push({root,0});
        
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            
            Node* node=t.first;
            int line=t.second;
            if(mp.find(line)==mp.end()) mp[line]=node->data;
            
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
         return ans;
    }
};
