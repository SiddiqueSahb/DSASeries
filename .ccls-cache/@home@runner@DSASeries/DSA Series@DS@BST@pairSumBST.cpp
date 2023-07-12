/*

Pair sum in a BST
Send Feedback
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of S.
Output format:
You have to print each pair in a different line (pair elements separated by space). The order of different pairs, to be printed, does not matter.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 1:
2 10
5 7



*/


//APPROACH
/*
BRUTE FORCE - For a node check corresponding node and getting a pair so T.C = O(N^2)

METHOD 1 - CONVERTING BST TO SORTED ARRAY AND USING TWO POINTER APPROACH
T.C = O(N) AND S.C = O(N)

METHOD 2 - USING TWO STACK , IN STACK1 CONTAINING INORDER ELEMENT AND STACK2 CONTAINS REVERSEINORDER ELEMENT(DESCENDING ORDER)
POP ELEMENT FROM BOTH THE STACK , DO THE ADDITION OF TOP ELEMENYS AND THEN CHECK WHETHER ITS EQUAL TO SUM

CONDN 1.
1.IF ADDN IS EQUAL TO SUM THEN POP ELEMENT FROM BOTH THE STACK
2.AFTER POPING , INSERTING ELEMENT IN STACK 1 WHICH IS JUST GREATER THAN POPED VALUE
3.SO ELEMENT TO BE PUSH IN STACK 1 IS PRESENT IN RST LEFT MOST ELEMENT
4.AFTER POPING , INSERTING ELEMENT IN STACK 2 WHICH IS JUST LESSER THAN POPED VALUE
5.SO ELEMENT TO BE PUSH IN STACK 2 IS PRESENT IN LST RIGHT MOST ELEMENT

CONDN 2.
1.IF ADDN IS GREATER THAN SUM THEN POP ELEMENT FROM STACK2
2.AFTER POPING , INSERTING ELEMENT IN STACK 2 WHICH IS JUST LESSER THAN POPED VALUE
3.SO ELEMENT TO BE PUSH IN STACK 2 IS PRESENT IN LST RIGHT MOST ELEMENT (going to root left subtree and from LST's root push all right NODE(including LST root))

COND 3.
1.IF ADDN IS LESSER THAN SUM THEN POP ELEMENT FROM STACK1
2.AFTER POPING , INSERTING ELEMENT IN STACK 1 WHICH IS JUST GREATER THAN POPED VALUE
3.SO ELEMENT TO BE PUSH IN STACK 1 IS PRESENT IN RST LEFT MOST ELEMENT (going to rst and pushing all its left node )

do above steps totalnodes - 1




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
#include<stack>

int countNodes(BinaryTreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
	int totalNodes = countNodes(root);
	int count  = 0;

	//creating two stack inorder (all left node) and revinorder(all right node)
	stack<BinaryTreeNode<int>*> inorder;
	stack<BinaryTreeNode<int>*> revinorder;

	BinaryTreeNode<int>* temp = root;

    //push all the left node of root in stack inorder
	while(temp){
		inorder.push(temp);
		temp = temp->left;
	}
	//after pushing all left node of stack , for pushing all right node of root again assgining root value
	temp = root;
   
   //push all right node to the revinorder stack
	while(temp){
		revinorder.push(temp);
		temp = temp->right;
	}

	while(count < totalNodes-1){
        
		//get the top element and add and check whther its equal to s
		BinaryTreeNode<int> *top1 = inorder.top();
		BinaryTreeNode<int> *top2 = revinorder.top();

		if(top1->data + top2->data == s){

			cout << top1->data << " " << top2->data << endl;
			BinaryTreeNode<int> *top = top1;
			inorder.pop();
			count++;
            
			//top1 is the lowest element , as we pop , now we insert value just greater than top1
			// its present in RST left most element
			if(top->right){
				// going to root RST
				top = top->right;
				while(top){
					//pushing RST root and all its left node
					inorder.push(top);
					top = top->left;
				}
			}
			top = top2;
			revinorder.pop();
			count++;
			//top2 is the greatest element , as we pop , now we insert value just lesser than top2
			//its present in LST right most element
			if(top->left){
				top = top->left;
				while(top){
					revinorder.push(top);
					top = top->right;
				}
			}
		}
	else if(top1->data + top2->data > s){
		// as sum of top is greater than s we want smaller no so pop element from revinorder
		BinaryTreeNode<int> *top = top2;
		revinorder.pop();
		count++;
      //we want nos just smaller than element we pop , so it will be present in LST(max value in LST)
	  //max value in LST will be right most element
	  //going to root left subtree and from LST's root push all right(including LST root)
	  if(top->left){
		  top = top->left;
		  while(top){
			  revinorder.push(top);
			  top = top->right;
		  }
	  }
	}
	// as sum of top is lesser than sum , we want greater no so pop element from inorder
	//after poping , pushing value which is just greater than poped value
	//value to be pushed is present in RST left most element
	else {
		BinaryTreeNode<int> *top = top1;
		inorder.pop();
		count++;
		if(top->right){
			top = top->right;
                        while (top) {
                          inorder.push(top);
                          top = top->left;
                        }
                }
        }
   }
}

//takuforward method to avoid code repetition
