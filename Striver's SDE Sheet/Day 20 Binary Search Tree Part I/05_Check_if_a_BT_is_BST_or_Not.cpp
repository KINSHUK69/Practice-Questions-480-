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

    bool helper(int low,int high,TreeNode* root){
       if(!root)return true;
       if(root->val>=high || root->val<=low)return false;
       return helper(low,root->val,root->left) && helper(root->val,high,root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return false;
        return helper(INT_MIN,INT_MAX,root); 
    }
};
