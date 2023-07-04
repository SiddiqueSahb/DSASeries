/*
Code: BST Class
Send Feedback
Implement the BST class which includes following functions -
1. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
2. search
Given an element, find if that is present in BST or not. Return true or false.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in in the following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
*/

/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
class BST {
    // Define the data members
    BinaryTreeNode<int>*  root;
   public:
    BST() { 
        // Implement the Constructor
        root = NULL;
    }

    ~BST() {
		delete root;
	}

	/*----------------- Public Functions of BST -----------------*/


   private:
   BinaryTreeNode<int>* deleteData(int data,BinaryTreeNode<int>* node){
     
     //if root node is NULL return NULL
     if(node == NULL){
       return NULL;
     }
     
     // if data is greater than root Node then go to right sub tree
     if(data > node->data){
       node->right = deleteData(data,node->right);
       return node;
     }
     // if data is less than root Node then go to left sub tree
     else if (data < node->data){
       node-> left = deleteData(data,node->left);
       return node;
     }
     // if root Node is equal to data to be deleted
     else {
         // 0 child
         // if root node is not having any child
         if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
         }
         //1 child
         // root node is having left child and not having right child
         else if (node->left != NULL && node->right == NULL){
                //storing root node address to temp so that root node is deleted and still we have address of its child
                BinaryTreeNode<int>* temp = node->left;
                //disconnecting root node with its left child
                 node->left = NULL;
                 //delete node
                 delete node;
                 //returning pointer of left child
                 return temp;
         }
         // root node is having right child and not having left child
         else if (node->left == NULL && node->right != NULL){
               //storing root node address to temp so that root node is deleted and still we have address of its child
                BinaryTreeNode<int>* temp = node->right;
                //disconnecting root node with its right child
                 node->right = NULL;
                //delete node
                delete node;
                //returning pointer of right child
                 return temp;
         }
         // root node is having both left child and right child
         else {
            // In this case replace root node with either left subtree max value or right subtree min value
            // to get the min value in RST go to extreme left of tree and get the value
            BinaryTreeNode<int>* minNode = node->right;
            while(minNode->left != NULL){
                     minNode = minNode->left;
            }
            // got the min value in RST
            int rightMin = minNode->data;
            //copy/replacing node value with min value of RST
            node->data = rightMin;
            // after replacing the root node value with min value of RST , now deleting the min value in RST
            node->right = deleteData(rightMin,node->right);
            return node;
         }
     }

   }

    public:
    void remove(int data) { 
        // Implement the remove() function 
        root = deleteData(data,root);
    }
    
   
 
  private:
   void printTree(BinaryTreeNode<int>* root) {
		if (root == NULL) {
			return;
		}
		cout << root->data << ":";
		if (root->left != NULL) {
			cout << "L:" << root->left->data<<",";
		}

		if (root->right != NULL) {
			cout << "R:" << root->right->data;
		}
		cout << endl;
		printTree(root->left);
		printTree(root->right);
	}


   public:
    void print() { 
        // Implement the print() function
        printTree(root);

    }


private:
	BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node) {
		if (node == NULL) {
			BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
			return newNode;
		}

		if (data <= node->data) {
			node->left = insert(data, node->left);
		} else {
			node->right = insert(data, node->right);
		}
		return node;
	}
    
    public:
    void insert(int data) { 
        // Implement the insert() function 
        this->root = insert(data,this->root);
        
    }




  private:
bool hasData(BinaryTreeNode<int>* node,int data){
  if(node == NULL){
    return false;
  }
  if(node->data == data){
    return true;
  }else if(node->data > data){
    return hasData(node->left,data);
  }else {
    return hasData(node->right,data);
  }
  
}

   public:
    bool search(int data) {
		// Implement the search() function 
        return hasData(root,data); 
    }
};