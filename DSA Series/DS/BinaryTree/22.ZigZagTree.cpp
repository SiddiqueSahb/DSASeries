/*
ZigZag tree
Send Feedback
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.
Constraints
Time Limit: 1 second
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9
*/

/*
//APPROACH
In zigzag order, level 1 is printed from left to right 
1.WITH THE HELP OF TWO STACK WE ARE PRINTING IN ZIGZAG WAY
2.INITIALLY ROOT IS PUSH TO STACK 1
3.PRINTING STACK1 TOP ELEMENT AND THEN CHECK IF ITS HAVING LEFT CHILD THEN PUSH TO STACK2
4.IF ITS HAVING RIGHT CHILD THEN PUSH TO STACK2
5.(WE ARE PUSHING ELEMENT IN STACK2 FIRST LEFT CHILD AND THEN RIGHT CHILD ,BCZ WE WANT TO PRINT RIGHT CHILD THEN LEFT CHILD)
6.DO THIS UNTILL STACK1 IS NOT EMPTY
7.PRINTING STACK2 TOP ELEMENT AND THEN CHECK IF ITS HAVING RIGHT CHILD THEN PUSH TO STACK1
8.(WE ARE PUSHING ELEMENT IN STACK1 FIRST RIGHT CHILD  AND THEN LEFT CHILD ,BCZ WE WANT TO PRINT LEFT CHILD THEN RIGHT CHILD)
9.DO THIS UNTILL STACK2 IS NOT EMPTY
10.REPEAT ABOVE STEP UNTILL STACK 1 IS NOT EMPTY

STACK S2 (L->R) PUSH
STACK S1 (R->L) PUSH
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
#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root == NULL){
		return;
	}

  stack<BinaryTreeNode<int>*> s1;
  stack<BinaryTreeNode<int>*> s2;
  s1.push(root);

	while(!s1.empty()){

	  while(!s1.empty())
	  {
	  BinaryTreeNode<int> *top = s1.top();
	  s1.pop();
	  cout<<top->data<<" ";
	  if(top->left != NULL){
		  //in stack2 push  1st left child and then right child 
		  s2.push(top->left);
	  }
	   if(top->right != NULL){
		  //in stack2 push  1st left child and then right child 
		  s2.push(top->right);
	  }
  }

//new level starts
cout<<endl;

  while(!s2.empty())
  {
	  BinaryTreeNode<int> *top = s2.top();
	  s2.pop();
	  cout<<top->data<<" ";
	  if(top->right != NULL){
		  //in stack1 push  1st right child and then left child 
		  s1.push(top->right);
	  }
          if (top->left != NULL) {
            // in stack1 push  1st right child and then left child
            s1.push(top->left);
          }
  }
  cout << endl;

	}
}



//METHOD 2 APPROACH 2
/*

1.Create an queue and store root
2.Create a vector of vector to store the zigzag traversal
3.Create a flag to decide to move either leftToright or rightToLeft
4.if flag is true , insert value in same sequence otherwise in reverse way
5.Go through each level , pop value from the queue  and insert its value to vector based on value of flag
6.After every level change flag value and push vector to result vector
  */

vector<vector<int>> zigZaglevelOrder(BinaryTreeNode<int>* root){
  //to store output of each level
  vector<vector<int>> result;
  if(root == NULL){
    return result;
  }

  //create an queue and push root node to queue
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  bool LeftToRight = true;

  while(pendingNodes.size() != NULL){
    //getting the size of the queue
    int size = pendingNodes.size();
    //creating a vector of size to store each level values 
    vector<int> row(size);

    //loop each level
    for(int i = 0;i<size;i++){
      //pop value of queue
      BinaryTreeNode<int>* front = pendingNodes.front();
      pendingNodes.pop();

      //After poping the queue value , inserting to the vector.
      //finding the index position in vector to store the value
      //for lefttoright store as it is , for righttoleft store in reverse way so (size of vector - 1 - i)
      int index = LeftToRight ? i : size - 1 - i
      row[index] = front->value;

      //if root is having left child push to queue
      if(front->left != NULL){
        pendingNodes.push(front->left);
      }
      //if root is having right child push to queue
      if(front->right != NULL){
        pendingNodes.push(front->right);
      }
    }
    //level wise done so change flag value of LeftToRight
    LeftToRight = !LeftToRight;
    //push each level vector to result vector 
    result.push_back(row); 
  }
return result;
  
}