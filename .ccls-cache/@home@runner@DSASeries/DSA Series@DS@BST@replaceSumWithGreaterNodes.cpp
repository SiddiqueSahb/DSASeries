/*
Replace with Sum of greater nodes
Send Feedback
Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.
That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.
Note: You don't need to return or print, just change the data of each node.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
In the output, data of the nodes of the tree are printed in level order form. Each level of the tree is printed on a separate line.
Constraints:
Time Limit: 1 second
Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1 :
18 
36 10 
38 31 
25 
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
1.using inorder traversal in reverse way 
2.inorder of BST gives sorted no in ascending order and reverse inorder gives sorted no in descending order
3.Rst Root Lst
4.going extreme right then in second visit doing addition and changing the node value and then going LST and in        third visit returning the value.


*/  


int replaceSum(BinaryTreeNode<int> *root, int sum){
  if(root == NULL ){
	  return sum;
  }
//getting RST sum
int sRST = replaceSum(root->right,sum);
//adding rootdata with sum
sum = sRST + root->data;
//replacing rootnode value with sum
root->data = sum;
//going left subtree for sum
//third visit of node we are returning the value thats why we are just returning the value received by LST
sum = replaceSum(root->left,sum);
//return sum
return sum;
}


void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root == NULL){
		return;
	}
	int ans = replaceSum(root,0);
	return;
}
