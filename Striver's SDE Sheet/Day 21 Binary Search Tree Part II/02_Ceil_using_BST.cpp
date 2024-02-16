int findCeil(BinaryTreeNode<int> *root, int X){
  int ceil=-1;
  while(root){
    if(root->val==X){
      ceil=root->val;
      return ceil;
    }
    if(X>root->val) root=root->right;
    else{
      ceil=root->val;
      root=root->left;
    }
  }
  return ceil;
}
