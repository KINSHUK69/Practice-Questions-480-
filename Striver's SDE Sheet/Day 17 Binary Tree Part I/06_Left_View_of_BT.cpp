vector<int> leftView(Node *root)
{   
    vector<int>ans;
    if(!root) return ans;
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* temp=q.front();
            if(i==0)ans.push_back(temp->data);
            q.pop();
            if(temp->left!=NULL)q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
        }
    }
    return ans;
}
