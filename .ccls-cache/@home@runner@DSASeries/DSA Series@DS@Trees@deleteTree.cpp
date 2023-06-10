void deleteTree(TreeNode<int>* root){
  for(int i = 0;i<root->children.size();i++){
    deleteTree(root->children[i]);
  }
  delete root;
}

#include <iostream>
#include<vector>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    //vector containing TreeNode pointers
    vector<TreeNode<T>*> children;
    
    //constructor
    TreeNode(T data){
        this->data = data;
    }

    ~TreeNode(){
      for(int i = 0;i<root->children.size();i++){
        delete children[i];
      }
    }
};