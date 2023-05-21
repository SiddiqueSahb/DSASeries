/*
Code: Merge Sort
Send Feedback
 Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Input 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
*/

//APPROACH
/*
1.break the LL into two halves
2.call recursion on two halves
3.Merge the two sorted LL
*/

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
Node *midPoint(Node *head)
{
    // Write your code here

	if(head == NULL || head->next == NULL){
		return head;
	}
	
    Node *slow = head;
	Node *fast = head->next;
	//fast != NULL for odd len LL , fast-next != NULL for even Len LL
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


Node *merge(Node *head1, Node *head2)
{
    //Write your code here
	//if LL is empty
	if(head1 == NULL && head2 == NULL ){
		return NULL;
	}
	//if LL1 is empty then return pointer of LL2
	if(head1 == NULL){
		return head2;
	}
	//if LL2 is empty then return pointer of LL1
	if(head2 == NULL){
		return head1;
	}

Node *fHead = NULL;
Node *fTail = NULL;
//Comparing the node , whichever is smaller , creating newHead and newTail and it will point to smaller node.
//increment the head pointer of smaller node as it's node is already compared.
	   if(head1->data <= head2->data){
		   fHead = head1;
		   fTail = head1;
		   head1 = head1->next;
	   }else{
		   fHead = head2;
		   fTail = head2;
		   head2 = head2->next;
	   }

   while(head2 != NULL && head1 != NULL){
	   //Now again do comparison of both node till we one of head reaches NULL
	   //if Tail pointer is used to attach the smaller node to previous node.
	      if(head1->data <= head2->data){
		    fTail->next = head1;
		    fTail = head1;
		    head1 = head1->next;
	   }else{
		  fTail->next = head2;
		  fTail = head2;
		  head2 = head2->next;
	   }
   }

//check head2 reaches NULL then fTail->next will get the value of head which is not null.
   if(head2 == NULL){
	   fTail->next = head1;
   }else if(head1 == NULL){
	   fTail->next = head2;
   }
   return fHead;
}


Node *mergeSort(Node *head)
{
	//Write your code here
	//empty or Single LL are sorted
	if(head == NULL || head->next == NULL){
		return head;
	}
  // LL 10->5->4->1->9->8->NULL
	Node *mid = NULL;
  //mid is Node 4
	mid = midPoint(head);
  //tail points to Node 4
	Node *firstLLTail = mid;
  //1->9->8->NULL
	Node *secondLLHead = mid->next;
	//after dividing LL into two halves 1st LL end should contain NULL 
  //10->5->4->NULL
	firstLLTail->next = NULL;
  //LL1 - 10->5->4->NULL
	Node *h1 = mergeSort(head);
  //LL2 - 1->9->8->NULL
	Node *h2 = mergeSort(secondLLHead);
	Node *mergeHead = merge(h1,h2);
	return mergeHead;

}