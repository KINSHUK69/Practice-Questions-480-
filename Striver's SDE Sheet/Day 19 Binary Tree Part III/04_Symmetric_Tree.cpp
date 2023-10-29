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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> sl, sr;
        sl.push(root);
        sr.push(root);
        TreeNode * lp = root->left, *rp = root->right;
        while(lp || !sl.empty() || rp || !sr.empty())
        {
            if((!lp && rp) || (lp && !rp)) 
                return false;
            if(lp && rp){
                if(lp->val != rp->val) 
                    return false;
                sl.push(lp);
                sr.push(rp);
                lp = lp->left;
                rp = rp->right;
            }
            else{
                lp = sl.top()->right;
                rp = sr.top()->left;
                sl.pop();
                sr.pop();
            }
        }
        return true;
}

};
