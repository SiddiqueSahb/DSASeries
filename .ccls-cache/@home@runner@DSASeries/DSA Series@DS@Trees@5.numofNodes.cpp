// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector<TreeNode<T>*> children;
    
    //constructor
    TreeNode(T data){
        this->data = data;
    }
};

//Number of Nodes
int numofNode(TreeNode<int>* root){
  int ans = 1;
  for(int i = 0;i<root->children.size();i++){
     ans = ans + numofNode(root->children[i]);
  }
  return ans;
}






//Input Level Wise
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter a root data "<<endl;
    cin>>rootData;
    //making root Node
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    //creating queue so that enqueue each node so that 
    //for that particular node we can insert child
    //Why pushing Node not only data ?
    //ans - bcz for connecting children we require address and then we can connect
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size() != 0){
        //selecting node from queue
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        
        //For each nodes enter no of children you want
        int numChild;
        cout<<"Enter a no of children of "<<front->data<<endl;
        cin>>numChild;
        for(int i = 0;i < numChild;i++){
            int childData;
            cout<<"Enter "<< i <<"th child of "<<front->data<<endl;
            cin>>childData;
            //Creating a childNode 
            TreeNode<int> *child = new TreeNode<int>(childData);
            //Attaching child node with parentNode
            front->children.push_back(child);
            //pushing childNode to queue so that it can be later be
            //selected and for that node , no of children can be inserted
            pendingNodes.push(child);
        }
    }
    return root;
}

//Take Input
TreeNode<int>* takeInput(){
    int rootData;
    
    cout<<"Enter data"<<endl;
    cin>>rootData;
    
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter no of children of "<<rootData<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
    
}

void printTree(TreeNode<int>* root){
    
    //not a basecase
    if(root == NULL){
        return;
    }
    
    //Print root
    cout<<root->data<<":";
    
    //printing root children
    for(int i = 0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i = 0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}


int main() {
    /*
    //creating root node and children node but they are not connected
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    
    //Now doing connection of rootnode and its children
    //root node having 2 child
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    
    TreeNode<int>* root = takeInputLevelWise();
    printTree(root);
    
}

/*
Root Node is 1 and its children are 2,3
Node 2 and 3 are not having children
1:2,3,
2:
3:

//takeInputLevelWise

Enter a root data 
1
Enter a no of children of 1
3
Enter 0th child of 1
2
Enter 1th child of 1
3
Enter 2th child of 1
4
Enter a no of children of 2
2
Enter 0th child of 2
5
Enter 1th child of 2
6
Enter a no of children of 3
0
Enter a no of children of 4
0
Enter a no of children of 5
0
Enter a no of children of 6
0
1:2,3,4,
2:5,6,
5:
6:
3:
4:

*/