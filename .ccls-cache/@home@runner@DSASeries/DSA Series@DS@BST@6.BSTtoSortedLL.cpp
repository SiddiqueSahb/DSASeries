/*
Code: BST to Sorted LL
Send Feedback
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
Note:
In case if you are facing any issue to solve this problem, please prefer to use the helper function.
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10
*/

/*
APPROACH
1.TO GET HEAD AND TAIL BOTH WE CREATE NEW CLASS PAIR HAVING TWO PROPERTY HEAD AND TAIL
2.WE ARE HAVING  ROOT NODE AND ITS HAS LEFT SUBTREE AND RIGHT SUB TREE
3.CREATE NODE OF LL AN CHECK FOR LST AND RST TO GIVE THEIR RESPECTIVE SORTED LL
4.SO HERE 4 CONDITIONS ARE POSSIBLE
  1.IF LST AND RST BOTH NULL (LST AND RST DOESNT HAVE LL)
   HEAD AND TAIL BOTH WILL BE NODE

  2.IF LST IS NULL AND RST IS NOT NULL (ASSUME WE GOT SORTED LL FROM RST)
    LST = NULL   4(NODE) - ROOT  5 6 7 N (RST SORTED LL)
    SO CONNECTING NODE WITH RST SORTED LL
    HEAD WILL BE NODE AND TAIL WILL BE RST LL TAIL

  3.IF LST IS NOT NULL (ASSUME WE GOT SORTED LL FROM LST) AND RST IS NULL 
    LST = 1 2 3  N   4(NODE) - ROOT  5  RST - NULL
    SO CONNECTING NODE WITH LST SORTED LL BY JOINING TAIL OF LST SORTED LL WITH NODE .
    HEAD WILL BE LST LL HEAD AND TAIL WILL BE NODE
    
  4.IF BOTH LST AND RST ARE NOT NULL AND GIVE BACK RESPECTIVE SORTED LL
    1 2 3 N(LST LL)   4   5 6 7 N (RST LL)
    JOIN LST LL TAIL WITH THE NODE(4) AND NODE(4)->NEXT IS CONNECTED WITH RST LL HEAD
    HEAD IS LST LL HEAD AND TAIL IS RST TAIL

`5.`RETURN ANS

*/


/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

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

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/
class Pair {
	public:
	Node<int>* head;
	Node<int>* tail;
};

Pair BST(BinaryTreeNode<int>* root){
	if(root == NULL){
		Pair ans;
		ans.head = NULL;
		ans.tail = NULL;
		return ans;
	}
    
	//creating node of element 
	Node<int>* node = new Node<int>(root->data);
    
	//check its LST and get the LL
	Pair lst = BST(root->left);
	//check its RST and get the LL
	Pair rst = BST(root->right);

	Pair ans;
    
	// if LST and RST are NULL then head and tail both will point to a node
	if(lst.head == NULL && rst.head == NULL){
		ans.head = node;
		ans.tail = node;
	}
	// if LST is  NULL and RST is not NULL then node->next will get right subtree linked list 's head address
	// head will point to node bcz lst linked list is NULL 
	else if (lst.head == NULL && rst.head != NULL){
		node->next = rst.head;
		ans.head = node;
		ans.tail = rst.tail;
	}
	else if (lst.head != NULL && rst.head == NULL){
		lst.tail -> next = node;
		ans.tail = node;
		ans.head = lst.head;
		
	}
	else {
		lst.tail->next = node;
		node->next = rst.head;
		ans.head = lst.head;
		ans.tail = rst.tail;
	}
	return ans;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
	return BST(root).head;

}