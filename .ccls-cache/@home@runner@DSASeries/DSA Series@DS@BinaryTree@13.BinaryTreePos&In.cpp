/*
Construct Tree from Postorder and Inorder
Send Feedback
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the Postorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
4 5 2 6 7 3 1 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
2 9 3 6 10 5 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 
*/


//APPROACH
/*

*/

/***********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

BinaryTreeNode<int>* buildTreeHelper(int *postorder, int *inorder,int postStart,int postEnd,int inStart,int inEnd) {

if(inStart > inEnd || postStart > postEnd){
	return NULL;
}

// pick root from postorder , in postorder root is at last
int rootData = postorder[postEnd];
//creating rootIndex var to find and store inOrder rootIndex (at which posn rootIndex is present in inorder )
int rootIndex;
for(int i = 0;i<=inEnd;i++){
	if(inorder[i] == rootData){
		rootIndex = i;
		break;
	}
}

//for left subtree we need to find out inorder and postOrder of LST 
int leftinStart = inStart;  // LST inorder start
int leftinEnd = rootIndex - 1; // LST inorder end
int leftpostStart = postStart; // postOrder start in LSt
int leftpostEnd = leftinEnd - leftinStart + postStart; //post Order end in LST. 

//for right subtree we need to find out inorder and postOrder of LST 
int rightinStart = rootIndex + 1;  // inOrder start in RST
int rightinEnd = inEnd; // inOrder end in RST
int rightpostEnd = postEnd - 1; // postOrder end in RST
int rightpostStart = leftpostEnd + 1; // // postOrder start in RST

//creating node of rootData
BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

  // calling recursion for LST 
	root->left = buildTreeHelper(postorder, inorder,leftpostStart,leftpostEnd,leftinStart,leftinEnd); 
	
	//calling recursion for RST
	root->right = buildTreeHelper(postorder,inorder,rightpostStart,rightpostEnd,rightinStart,rightinEnd);

	//After returning root , nodes get connected to its parent as left child and right child;
	return root;

}


BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
	return buildTreeHelper(postorder,inorder,0,postLength-1,0,inLength-1);
}