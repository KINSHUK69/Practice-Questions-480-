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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        if(!root) return ans;

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});

        while(!q.empty()){
            long long currMin=q.front().second;
            int n=q.size();
            long long left,right;

            for(int i=0;i<n;i++){
                long long cid=q.front().second-currMin;
                TreeNode* t=q.front().first;
                q.pop();

                if(i==0) left=cid;
                if(i==n-1) right=cid;

                if(t->left) q.push({t->left,(long long)2*cid+1});
                if(t->right) q.push({t->right,(long long)2*cid+2});
            }
            ans=max(ans,right-left+1);
        } 
        return ans;
    }
};
