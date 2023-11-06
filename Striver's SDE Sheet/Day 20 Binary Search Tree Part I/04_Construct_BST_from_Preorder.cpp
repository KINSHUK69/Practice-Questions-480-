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
    TreeNode* builder(int& i,int MAX,vector<int>& preorder){
      
        if(i==preorder.size() || preorder[i]>MAX) return NULL;

        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=builder(i,root->val,preorder);
        root->right=builder(i,MAX,preorder);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)return NULL;
        int i=0;
        return builder(i,INT_MAX,preorder);
    }
};
