/*
Code: Construct Tree from Preorder and Inorder
Send Feedback
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

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
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
5 6 2 3 9 10 
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

BinaryTreeNode<int>* buildTreeHelper(int *preorder, int *inorder,int preStart,int preEnd,int inStart,int inEnd) {
    // Write your code here

	//When only one element is present then start will always be greater than end index
	//so return NULL
	if(preStart > preEnd || inStart > inEnd){
		return NULL;
	}

	//Getting root from preOrder as root is 1st element in preOrder 
	int rootData = preorder[preStart];
	//finding rootIndex in Inorder by comparing with root data
	int rootIndex;
	for(int i = inStart;i<=inEnd;i++){
		if(inorder[i] == rootData){
			rootIndex = i;
			break;
		}
	}

//for left subtree we need to find out inorder and preOrder of LST 
	int leftinStart = inStart;  //left inorder start
	int leftinEnd = rootIndex - 1; //left inorder end
	int leftpreStart = preStart + 1; // + 1 bcz at preStart root is present
	 //for LST
	 // inEnd - inStart (it will give LST of inOrder) and same length will be of preOrder's LST so
	 // inEnd - inStart = preEnd - preStart so leftpreEnd = leftinEnd - leftinStart + leftpreStart; 
	int leftpreEnd = leftinEnd - leftinStart + leftpreStart; //left preorder end

//for right subtree we need to find out inorder and preOrder of RST 
	int rightinStart = rootIndex + 1;  // right inOrder start
	int rightinEnd = inEnd;  // right inorder end
	int rightpreStart = leftpreEnd + 1;  // right preOrder start
	int rightpreEnd = preEnd;  //right preOrder end

	//creating node of rootData
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

  // calling recursion for LST 
	root->left = buildTreeHelper(preorder, inorder,leftpreStart,leftpreEnd,leftinStart,leftinEnd);
  //calling recursion for RST
	root->right = buildTreeHelper(preorder,inorder,rightpreStart,rightpreEnd,rightinStart,rightinEnd);
	return root;

}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
	return buildTreeHelper(preorder,inorder,0,preLength-1,0,inLength-1);

	
}