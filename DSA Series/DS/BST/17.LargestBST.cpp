/*
Largest BST
Send Feedback
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Note :
The binary tree will be consisting of only unique elements.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
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

/*


 A Binary Tree is said to be a BST when the following two conditions are satisfied:
1. The value of the node should be greater than the maximum value of the left subtree and lesser than the minimum of the right subtree.
2. The left and right subtree of every node are BST.
The key observation here is that if a subtree is a BST then all nodes in its subtree will also be a BST. So, we will recurse on the binary tree in a bottom-up manner and use the information of the left subtree and right subtree to store the information for the current subtree.
Steps:
1. Base case: If root is NULL, then return 0 as height of null tree is 0 and it is a BST.
2. For each node of the tree, store the following:
a. ‘isBST’, denoting whether it is a BST
b. ‘height’, denoting the height of the subtree
c. ‘min’, denoting the minimum value of data in the left subtree
d. ‘max’, denoting the maximum value of data in the right subtree
  
3. Recursively call on the left and right subtree to find the height of the subtree which is BST.
4. For the currentnode, check if the left subtree is BST or the right subtree is BST. Also check if the value of the root node is greater than the maximum of left subtree value and lesser than the minimum of right subtree values.
5. If tree is BST and  conditions satisfy, find the maximum of left height of LST BST and right height of the RST  BST and return it.

*/





 
***********************************************************/
#include<climits>
class isBSTReturn {
	public :
	int minVal;
	int maxVal;
	bool isBST;
	int size; //size of largest bst
};

isBSTReturn largestBSTSubtreeHelper(BinaryTreeNode<int> *root){

	if(root == NULL){
		isBSTReturn output;
		output.minVal = INT_MAX;
		output.maxVal = INT_MIN;
		output.isBST = true;
		output.size = 0;
		return output;
	}
    
	//checking LST is BST or not to get the height of largest BST
	isBSTReturn leftST = largestBSTSubtreeHelper(root->left);
	//checking RST is BST or not to get the height of largest BST
	isBSTReturn rightST = largestBSTSubtreeHelper(root->right);
    //finding min value among LST and RST so that later it can be compare with root value
	int mini = min(root->data,min(leftST.minVal,rightST.minVal));
	//finding max value among LST and RST so that later it can be compare with root value
	int maxi = max(root->data,max(leftST.maxVal,rightST.maxVal));
    /*
A Binary Tree is said to be a BST when the following two conditions are satisfied:
1. The value of the node should be greater than the maximum value of the left subtree and
lesser than the minimum of the right subtree.
2. The left and right subtree of every node are BST.
*/
	bool isBSTFinal = (leftST.maxVal < root->data) && (root->data < rightST.minVal) && leftST.isBST && rightST.isBST;
	isBSTReturn output;
	output.minVal = mini;
	output.maxVal = maxi;
	output.isBST = isBSTFinal;
	
	//if tree's LST and RST is BST then calculate the height of LST BST and height of RST BST and as we want largest BST
	// return max amongst them and adding 1 bcz of root.
	// if tree's is not BST then just return max amongst the size of BST present in LST and RST
		if(isBSTFinal){
			output.size = 1 + max(leftST.size,rightST.size);
	}else{
		output.size = max(leftST.size,rightST.size);
	}
	return output;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	 return largestBSTSubtreeHelper(root).size;
}

