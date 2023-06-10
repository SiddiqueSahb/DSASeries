//Depth means from root node to level k

void printAtLevelK(TreeNode<int>* root , int k){
  if(k == 0){
    cout<<root->data<<endl;
    return;
  }
  printAtLevelK(root->children[i],k-1);
}