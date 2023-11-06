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

    TreeNode* builder(int left,int right,vector<int>& nums){\
        if(right<left)return NULL;
        int mid=(left+right)>>1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left=builder(left,mid-1,nums);
        root->right=builder(mid+1,right,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return NULL;
        return builder(0,nums.size()-1,nums);   
    }
};
