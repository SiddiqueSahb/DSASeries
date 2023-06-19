/*
Check Balanced
Send Feedback
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.
Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format
The first and only line of output contains true or false.
Constraints
Time Limit: 1 second
Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true
*/

/**********************************************************
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
//APROACH
/*
in this approach height and checking is done together. T.C = O(n)
1.Find height in LST
2.Find height in RST
3.if difference of lST - RST <= 1 , tree is balanced otherwise it is not;


In naive approach T.C = O(N*H), calculating height for each node subtree so T.C increases.

*/




//Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1.
// Return true if given binary tree is balanced, false otherwise.

//optimised approach
int checkBalanced(BinaryTreeNode<int> *root){
	if(root == NULL){
		return 0;
	}
	int lstH = checkBalanced(root->left);
	int rstH = checkBalanced(root->right);
	if(lstH == -1 || rstH == -1){
		return -1;
	}
	//given tree
	if(abs(lstH - rstH) > 1){
		return -1;
	}

	return 1 + max(lstH,rstH);

}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
	int ans = checkBalanced(root);
	if(ans != -1){
		return true;
	}else{
		return false;
	}
}

