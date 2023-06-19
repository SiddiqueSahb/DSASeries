/*
Min and Max of Binary Tree
Send Feedback
For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
Return the output as an object of Pair class, which is already created.
Note:
All the node data will be unique and hence there will always exist a minimum and maximum node data.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints two integers denoting the minimum and the maximum data values respectively. A single line will separate them both.
Constraints:
2 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 14
Sample Input 2:
10 20 60 -1 -1 3 50 -1 -1 -1 -1 
Sample Output 2:
3 60
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
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree

//APPROACH

1. initally rootnode will be min as well as max.
2. get the min and max value from LST as well as from RST
3. to get the min value in a tree Compare root node value with min of LST AND RST
4.to get the max value in a tree Compare root node value with max of LST AND RST

*/

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root == NULL){
		pair<int,int> p;
		p.first = 9999; //INT_MAX
		p.second = -9999; //INT_MIN
		return p;
	}

  //Intially root Node of tree will be both min and max
	pair<int,int> MaxMin;
	MaxMin.first = root->data;
	MaxMin.second = root->data;
  //calling recursion to get the Min and Max in LST
	pair<int,int> leftST = getMinAndMax(root->left);
  //calling recursion to get the Min and Max in RST
	pair<int,int> rightST = getMinAndMax(root->right);
  //To get the min comparing Min value of LST and Min value of RST then with rootNode of tree
	MaxMin.first = min(MaxMin.first,min(leftST.first,rightST.first));
  //To get the max comparing Max value of LST and Max value of RST then with rootNode of tree
	MaxMin.second = max(MaxMin.second,max(leftST.second,rightST.second));
	return MaxMin;

}