/*
Palindrome LinkedList
Send Feedback
You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
 Output format :
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.
  */

//APPROACH Optimized
/*

1.Find the middle element of the linked list.
2.Reverse a linked list from the next element of the middle element. 
3.Iterate through the new list until the middle element reaches the end of the list.
(i.e comparing the LL with reversed LL , one from the start and 
 other from the next element of middle element which we reversed )
4.if not same return false other wise true.

//APPROACH FIINDING MIDDLE
1.JUST GET THE COUNT AND THEN TRAVERSE TILL COUNT/2 TO GET THE MIDDLE (NAIVE APPROACH)
2.SLOW FAST APPROACH (Tortoise-Hare approach)
we increment slow ptr by 1 and fast ptr by 2, so if take a close look fast ptr will travel double that of the slow pointer. So when the fast ptr will be at the end of the Linked List, slow ptr would have covered half of the Linked List till then. So slow ptr will be pointing towards the middle of Linked List.


//APPROACH REVERSE (ITERATIVE)
1. Using three-pointers to traverse through the entire list and interchange links between nodes. 
 One pointer to keep track of the current node in the list.
 The second one is to keep track of the previous node to the current node and change links.
 third pointer to keep track of nodes in front of current nodes.
*/


//CODE
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

//Reversing from the next element of middle element and it will become 2nd LL from given LL
Node *reverse(Node *curr){
	Node *prev = NULL;
	Node *next = NULL;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

bool isPalindrome(Node *head)
{
    //Write your code here
	//For empty LL or LL having 1 Node
	if(head == NULL || head->next == NULL){
		return true;
	}
    
	//LL   1->2->3->2->1->NULL (odd)
	//LL.  1->2->2->1->NULL (even)
	//Mid of LL
	Node *slow = head;
	Node *fast = head;
	while( fast->next != NULL  &&  fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
  
  //From next element of mid we are calling reverse to reverse the LL and it will become our 2nd LL
  //LL   1->2->3->.  mid is Node 3  reversing  - 2->1->NULL (odd)
  //LL.  1->2->.  mid is Node 2 reversing 2->1->NULL (even)
  //pointer that will be return will be store in mid element next so that it we get after reversing.
  slow->next = reverse(slow->next);
   	//LL   1->2->3->1->2->NULL (odd) 
	//LL.  1->2->1->2->NULL (even)
	Node *newHead = slow->next; //points to starting of reversed LL
	Node *oldHead = head;  //points to starting of LL;

	//comparing if same then increment the pointer
	while(newHead != NULL){
		if(oldHead->data != newHead->data){
			return false;
		}
		oldHead = oldHead->next;
		newHead = newHead->next;
	}
	return true;

}