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
    int dfs(TreeNode* root,int &d){
        if(!root)return 0;

        int left= max(0,dfs(root->left,d));
        int right= max(0,dfs(root->right,d));

        d=max(d,left+right+root->val);

        return max(left,right)+root->val;
        
    }
    int maxPathSum(TreeNode* root) {

        if(!root)return 0;
        int maxSum=INT_MIN;
        dfs(root,maxSum);
        return maxSum;
    }
};
