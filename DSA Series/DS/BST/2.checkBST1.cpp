//T.C = O(n * h)

//APPROACH
/*

BST is where root node should be greater than left subtree and less than righ subtree, it is not like root node is greater that left node and less than right node.
  */
int maximum(BinaryTreeNode<int>* root){
  if(root == NULL){
    return INT_MIN;
  }
  // Finding max among root node , lst and rst
  return max(root->data,max(maximum(root->left),maximum(root->right)));
    
}

int minimum(BinaryTreeNode<int>* root){
  if(root == NULL){
    return INT_MAX;
  }
  //finding min among root node and lst and rst
  return min(root->data,min(minimum(root->left),minimum(root->right));
    
}

bool isBST(BinaryTreeNode<int>* root){
  if(root == NULL){
    return NULL;
  }

  //root node should be greater than lst max value so need to find lst max value
  int leftMax = maximum(root->left);
  //root node should be less equal to right sub tree min value
  int rightMin = minimum(root->right);
  bool output = (root->data > leftMax) && (root->data <= rightMin ) && isBST(root->left) && isBST(root->right);
  return output;
}

