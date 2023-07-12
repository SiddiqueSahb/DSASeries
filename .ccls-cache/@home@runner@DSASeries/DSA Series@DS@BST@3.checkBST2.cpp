//T.C = 2T(N/2) + K  FOR( NOT FOR SKEW TREE)
//T.C = T(N-1) + K(CONSTANT)

//checking at a same time max , min and whether lst and rst is bst or not

class isBSTReturn(BinaryTreeNode<int>* root){
  public:
  bool isBST:
  int minimum;
  int maximum;
};

isBSTReturn isBST2(BinaryTreeNode<int>* root){
  if(root == NULL){
    isBSTReturn output;
    output.isBST = true;
    output.minimum = INT_MAX;
    output.maximum = INT_MIN;
    return output;
  }

  isBSTReturn leftST = isBST2(root->left);
  isBSTReturn rightST = isBST2(root->right);
  int minimum = min(root->data,min(leftST.minimum,rightST.minimum));
  int maximum = min(root->data,max(leftST.maximum,rightST.maximum));
  bool isBSTFinal = (root->data > leftST.maximum) && (root->data <= rightST.minimum) && leftST.isBST && rightST.isBST
  isBSTReturn output;
  output.isBST = isBSTFinal;
  output.minimum = minimum;
  output.maximum = maximum;
  return output;
}