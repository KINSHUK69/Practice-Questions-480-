/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// T.C. = O(N)  || S.C. = O(N)  
// LCA of two nodes method
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root == p || root == q) return root;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left!= NULL and right!=NULL)return root;

        return (left==NULL)?right:left;
    }
};
// T.C. = O(H)  where H is the height of the BST || S.C. = O(H)  
// LCA of two nodes method
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        int cur=root->val;
      
        if(cur>p->val && cur>q->val)
        return lowestCommonAncestor(root->left,p,q);
        else if(cur<p->val && cur<q->val)
        return lowestCommonAncestor(root->right,p,q);

        return root;
    }
};

