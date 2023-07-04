/*
Find Path in BST
Send Feedback
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of k.
Output Format :
The first line and only line of output prints the data of the nodes in the path from node k to root. The data of the nodes is separated by single space.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1:
2 5 8

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
/*
//APPROACH

1. if root is null return null
2. if data that we want is equal to root then create a vector and push data in that vector and return vector
3. if data that we want is not equal to root and root is not null then check in LST
4.if lST doesnt return NULL then add that node to the vector and return vector , if LST return NULL then check RST.
5.if RST doesnt return NULL then add that node to the vector and return vector, if RST return NULL then check RST.

  */



vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
	if(root == NULL){
		return NULL;
	}

	if(root->data == data){
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}

	vector<int>* lstOutput = getPath(root->left, data);
	if(lstOutput != NULL){
		 lstOutput->push_back(root->data);
		return lstOutput;
	}

	vector<int>* rstOutput = getPath(root->right, data);
	if(rstOutput != NULL){
		 rstOutput->push_back(root->data);
		return rstOutput;
	}else{
		return NULL;
	}
}