/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Using BFS 
    // T.C. = O(N)
    // S.C. = O(N)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                level.push_back(temp->val);
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
    // Using DFS 
    // T.C. = O(N)
    // S.C. = O(N)
    void dfs(TreeNode* root,vector<vector<int>>&ans,int d=0){
      
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        dfs(root,ans);
        return ans;
    }

};
