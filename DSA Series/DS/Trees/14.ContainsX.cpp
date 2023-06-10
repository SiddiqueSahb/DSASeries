/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
//APPROACH - 83%
//First comparing the the node then calling the recursion
bool isPresent(TreeNode<int>* root, int x) {
    // Write your code here
    bool ans;
   if(root == NULL){
        return false;
    }
  
    if(root->data == x){
        return true;
    }
    for(int i = 0;i<root->children.size();i++){
        ans = isPresent(root->children[i],x);
    }
    if(ans == true){
        return true;
    }else{
        return false;
    }
   
}

//APPROACH 2 100%
//calling recursion till the end and then while returning comparing nodes
bool isPresent(TreeNode<int>* root, int x) {
    // Write your code here
    bool ans;
     if(root == NULL){
        return false;
    }
    for(int i = 0;i<root->children.size();i++){
       ans = isPresent(root->children[i],x);
       if(ans == true){
           return true;
       }
    }
      if(root->data == x){
        return true;
    }else{
        return false;
    }
   
}


bool isPresent(TreeNode<int>* root, int x) {
    // Write your code here
     if(root->data == x){
        return true;
    }
    for(int i = 0;i<root->children.size();i++){
       bool ans = isPresent(root->children[i],x);
       if(ans == true){
           return true;
       }
    }
    return false;
   
}

