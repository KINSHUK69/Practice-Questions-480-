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
// USING INORDER TRAVERSAL : inorder traversal of BST gives a perfectly sorted array
// T.C. = O(n)
// S.C. = O(n)
class Solution {
public:
    void dfs(TreeNode* root,vector<int>&v){
        if(!root)return;
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>in;
        dfs(root,in);        
        return in[k-1];
    }
};
// USING INORDER TRAVERSAL : starting from the left most for the minimun || and the right most for the maximum
// T.C. = O(min(k,n))
// S.C. = O(min(k,n))
class Solution {
public:
    
    void solve(TreeNode* root,int& ctr,int& ans,int& k){
       if(!root)return;

       solve(root->left,ctr,ans,k);
       ctr++;

       if(ctr==k){
           ans=root->val;
           return;
       }

       solve(root->right,ctr,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
       int ctr=0,ans;
       solve(root,ctr,ans,k);
       return ans;
    }
};
