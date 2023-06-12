/*
Delete node
Send Feedback
You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.
Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.
Illustration :
The following images depict how the deletion has been performed.
Image-I :
Alt txt

Image-II :
Alt txt

Input format :
The first line contains an Integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the linked list separated by a single space. 

The second line of each test case contains the integer value of 'POS'. It denotes the position in the linked list from where the node has to be deleted.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Note:
You are not required to print the output, it has already been taken care of. Just implement the function. 
Constraints :
1 <= T <= 10^2
0 <= N <= 10^5
POS >= 0

Time Limit: 1sec
Sample Input 1 :
1 
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0
10 20 30 40 50 60 -1
7
Sample Output 2 :
4 5 2 6 1 9
10 20 30 40 50 60
  */

/*
Edge Cases: This way of thinking will almost always work. There are a couple of edge
cases that we need to consider separately. These cases are:
1. The node to be deleted is the head node.
2. The node to be deleted is the tail node.

The first case is very easy to handle. If we need to delete the head node, we can simply
return the next node of head.
For the second one, our “ABC” approach will work fine because in that case node ‘C’ will
be ‘null’ and we assign that to node ‘A’ which will run perfectly fine.


Special Cases: There are some special cases to be considered as well but they are easy
to handle. They are:
1. ‘head’ node is null: an empty linked list has been passed
2. The index is out of bounds of the linked list: The index is negative or it’s greater
than or equal to the size of the linked list.
In both these cases, we can simply return head
  */

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
	Node *curr = head;
	int count = 0;
	Node *next = NULL;
  Node *temp = NULL;

//checking LL is empty or not
    if(head == NULL){
        return NULL;
    }

	//if position is 0
	if(pos == 0 ){
		temp = head;
		head = head->next;
		return head;
    delete temp;
	}

   
    //Traversing and standing just before the node to be deleted
	while(curr != NULL && count < pos-1){
		curr = curr->next;
		count++;
	}

  //traversing and checking whether pos is greater than length of linked list
	if(curr == NULL || curr->next == NULL){
		return head;
	}
   

      //if node is not null then deleteing the node at particular posn
    if(curr != NULL){
        temp = curr->next;
        curr->next = temp->next;
        return head;
        delete temp;
    }
}
