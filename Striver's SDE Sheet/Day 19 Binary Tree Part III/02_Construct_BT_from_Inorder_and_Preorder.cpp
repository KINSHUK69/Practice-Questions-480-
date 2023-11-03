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
    TreeNode* builder(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>&m) {

            if(preStart > preEnd || inStart > inEnd)return NULL;
            TreeNode* root=new TreeNode(preorder[preStart]);
      
            int ele=m[root->val];
            int nele=ele-inStart;
      
            root->left=builder(preorder,preStart+1,preStart+nele,inorder,inStart,ele-1,m);
            root->right=builder(preorder,preStart+nele+1,preEnd,inorder,ele+1,inEnd,m);
      
            return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=builder(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
    }
};
