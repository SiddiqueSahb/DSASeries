/*
Path Sum Root to Leaf
Send Feedback
For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.
Example:
alt txt

If you see in the above-depicted picture of Binary Tree, we see that there are a total of two paths, starting from the root and ending at the leaves which sum up to a value of K = 13.

The paths are:
a. 2 3 4 4
b. 2 3 8

One thing to note here is, there is another path in the right sub-tree in reference to the root, which sums up to 13 but since it doesn't end at the leaf, we discard it.
The path is: 2 9 2(not a leaf)
 Input Format:
The first line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

The second line of input contains an integer value K.
Output Format:
Lines equal to the total number of paths will be printed. All the node data in every path will be printed in a linear fashion taken in the order they appear from top to down bottom in the tree. A single space will separate them all.
Constriants:
1 <= N <= 10^5
0 <= K <= 10^8
Where N is the total number of nodes in the binary tree.

Time Limit: 1 second
Sample Input 1:
2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1
13
 Sample Output 1:
2 3 4 4 
2 3 8
Sample Input 2:
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13
 Sample Output 2:
5 6 2
5 7 1
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

/*

//APPROACH
1.FROM ROOT TILL LEAF ADD NODE TO THE PATH AND WHEN REACHED END CHECK NODE IS LEAF OR NOT, 
 1.IF IT IS LEAF NODE THEN CHECK LEAF NODE VALUE IS EQUAL TO K
 2.IF ITS EQUAL TO K ,THEN PRINT THE PATH OTHERWISE DONT ADD/REMOVE IT
2.DO THIS FOR LEFT SUBTREE AND RIGHT SUB TREE
3.WHEN RETURNING POP THE VALUE FROM THE PATH



  */




#include<vector>
void pathSum(BinaryTreeNode<int> *root,int k,vector<int> pathNode){
    //IF ROOT IS NULL RETURN
    if(root == NULL){
		return;
	}
  //ADD NODE TO THE PATH VECTOR
	pathNode.push_back(root->data);
//CHECK FOR LEAF NODE
if(root->left == NULL && root->right == NULL){
  //CHECK K == LEAF NODE , IF YES THEN PRINT OTHERWISE REMOVE IT
	if(root->data == k){
		 for(int i = 0;i<pathNode.size();i++){
		cout<<pathNode[i]<<" ";
	}
	cout<<endl;
	}
	else{
    //IF K != LEAFNODE THEN REMOVE IT FROM THE PATH
		pathNode.pop_back();
	}
   
} 
//FINDING PATH IN LST
pathSum(root->left,k-root->data,pathNode);
//FINDING PATH IN RST
pathSum(root->right,k-root->data,pathNode);
//WHILE RETURNING REMOVE NODE FROM PATH
pathNode.pop_back();

}


void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
	if(root == NULL){
		return;
	}
	vector<int> pathNode;
	pathSum(root,k,pathNode);
	 
}

