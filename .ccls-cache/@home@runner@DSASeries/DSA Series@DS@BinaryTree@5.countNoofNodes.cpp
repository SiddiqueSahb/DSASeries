
#include <iostream>
#include<queue>
using namespace std;
template<typename T>
class BinaryTreeNode {
public:
  T data;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(T data){
    this->data = data;
    left = NULL;
    right = NULL;
  }

  ~BinaryTreeNode(){
    delete left;
    delete right;
  }

};

//Count no of Nodes
// Adding  noofNodes in LST and noofNodes in RST plus rootNode
//if there is only rootNode and no left sub tree and no right sub tree
//then 1 + 0 + 0 = 1
int numofNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return (1 + numofNodes(root->left) + numofNodes(root->right));
    
    /*
    if(root == NULL){
        return 0;
    }
    int l , r;
    l = numofNodes(root->left);
    r = numofNodes(root->right);
    return (1 + l + r);
    */
}

//inputLevelWise
// BinaryTreeNode<int>* takeInputLevelWise() {
//     int rootData;
//     cout<<"Enter root data"<<endl;
//     cin>>rootData;
//     if(rootData == -1){
//         return NULL;
//     }
    
//     BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
//     queue<BinaryTreeNode<int>*> pendingNodes;
//     pendingNodes.push(root);
    
//     while(pendingNodes.size() != 0){
//         BinaryTreeNode<int>* front = pendingNodes.front();
//         pendingNodes.pop();
        
//         cout<<"Enter leftChild of "<<front->data<<endl;
//         int leftChildData;
//         cin>>leftChildData;
        
//         if(leftChildData != -1){
//             BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
//             front->left = child;
//             pendingNodes.push(child);
//         }
        
//         cout<<"Enter rightChild of "<<front->data<<endl;
//         int rightChildData;
//         cin>>rightChildData;
        
//         if(rightChildData != -1){
//             BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
//             front->right = child;
//             pendingNodes.push(child);
//         }
//     }
//     return root;
// }

// void printBinaryTree(BinaryTreeNode<int>* root){
//     if(root == NULL){
//         return;
//     }
//     cout<<root->data<<":";
//     if(root->left != NULL){
//         cout << "L" <<root->left->data;
//     }
    
//      if(root->right != NULL){
//         cout << "R" <<root->right->data;
//     }
//     cout<<endl;
//     printBinaryTree(root->left);
//     printBinaryTree(root->right);

// }

// BinaryTreeNode<int>* takeInput(){
//     int rootData;
//     cout<<"Enter data"<<endl;
//     cin>>rootData;
//     if(rootData == -1){
//         return NULL;
//     }
//   BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
//   BinaryTreeNode<int>* leftChild = takeInput();
//   BinaryTreeNode<int>* rightChild = takeInput();
//   root->left = leftChild;
//   root->right = rightChild;
//   return root;
// }

int main() {
    // Write C++ code help
//   BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
//   BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
//   BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
//   root->left = node1;
//   root->right = node2;
  BinaryTreeNode<int>* root = takeInputLevelWise();
	printBinaryTree(root);
	delete root;

}