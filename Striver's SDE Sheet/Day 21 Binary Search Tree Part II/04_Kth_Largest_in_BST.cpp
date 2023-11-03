class Solution
{
    public:
    void dfs(Node* root,vector<int>&v){
        if(!root)return;

        dfs(root->left,v);
        v.push_back(root->data);
        dfs(root->right,v);
    }
    int kthLargest(Node* root, int k) {
        vector<int>in;
        dfs(root,in);
        // for(auto it:in)cout<<it<<" ";
        return in[in.size()-k];
    }
    
};
