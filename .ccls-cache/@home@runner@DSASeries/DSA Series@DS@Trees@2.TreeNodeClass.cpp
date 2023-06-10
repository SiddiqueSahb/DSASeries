// Online C++ compiler to run C++ program online
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
};


int main() {
    //creating root node and children node but they are not connected
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    
    //Now doing connection of rootnode and its children
    //root node having 2 child
    root->children.push_back(node1);
    root->children.push_back(node1);
    
}