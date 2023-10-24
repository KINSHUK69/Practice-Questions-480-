class Solution {
public:
    // Using BFS
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
      
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
      
        return max(left,right)+1;
    }


    // Using BFS
    int maxDepth(TreeNode* root) {
        int ans=0;
        if(!root)return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* t=q.front().first;
                int h=q.front().second;
                ans=max(ans,h);
                q.pop();

                if(t->left)q.push({t->left,h+1});
                if(t->right)q.push({t->right,h+1});
            }
        }
        return ans;
    }
};
