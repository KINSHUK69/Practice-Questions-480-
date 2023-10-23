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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;

        queue<pair<TreeNode*,pair<int,int>>>q;        //   node, x, y  |  x represents left ot right  |  y represent level
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>mp;            //   vertical, level,multiple nodes  |  so use multiset as it stores in sorted order and stores duplicates 

        while(!q.empty()){
            auto t=q.front();
            q.pop();

            TreeNode* node=t.first;
            int x=t.second.first,y=t.second.second;

            mp[x][y].insert(t.first->val);

            if(node->left)q.push({node->left,{x-1,y+1}});      // y+1 because moving to new level , x-1 because moving to left
            if(node->right)q.push({node->right,{x+1,y+1}});    // y+1 because moving to new level , x+1 because moving to right
        }
        for(auto it:mp){
            vector<int>level;
            for(auto i:it.second) level.insert(level.end(),i.second.begin(),i.second.end());
            ans.push_back(level);
        }
        return ans;

    }
};
