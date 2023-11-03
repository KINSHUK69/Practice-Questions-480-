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
    TreeNode* builder(vector<int>& inorder,int iStart,int iEnd,vector<int>& postorder,int pStart,int pEnd,map<int,int>&m) {

            if(pStart > pEnd || iStart > iEnd)return NULL;
            TreeNode* root=new TreeNode(postorder[pEnd]);
      
            int ele=m[root->val];
            int nele=ele-iStart;
      
            root->left=builder(inorder,iStart,ele-1,postorder,pStart,pStart+nele-1,m);
            root->right=builder(inorder,ele+1,iEnd,postorder,pStart+nele,pEnd-1,m);
      
            return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;

        TreeNode* root=builder(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
        return root;
    }
    
};
