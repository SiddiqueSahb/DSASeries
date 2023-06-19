/*
Level wise linkedlist
Send Feedback
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
Each level linked list is printed in new line (elements are separated by space).
Constraints:
Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9
*/

/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

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
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

/*
//APPROACH

1.DOING LEVEL ORDER TRAVERSAL AND FOR EACH LEVEL CREATING LINKED LIST AND STORING ITS HEAD VALUE


  
*/





***********************************************************/
#include<queue>
#include<vector>
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
  
	//create an vector of type Node to store level wise head of LL
	vector<Node<int>*> output;

	if(root == NULL){
		return output;
	}


	//create an queue
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0){
		Node<int> *head = NULL;
		Node<int> *tail = NULL;
		int n = pendingNodes.size();
		while(n != 0){
			BinaryTreeNode<int>* current = pendingNodes.front();
			pendingNodes.pop();
			if(current != NULL){
				//creating newNode of currentData;
				Node<int> *newNode = new Node<int>(current->data);
				if(head == NULL){
					head = newNode;
					tail = newNode;
				}else{
					tail->next = newNode;
					tail = tail->next;
				}	
			  //checking left child , if its present then push to queue
				if(current->left != NULL){
				pendingNodes.push(current->left);
				}
				//checking rightt child , if its present then push to queue
				if(current->right != NULL){
					pendingNodes.push(current->right);
				}
			}
			n--;
		}
		//For each level creating a LL and its head is push to vector
		output.push_back(head);
	}
	return output;
}