/*
Eliminate duplicates from LL
Send Feedback
You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements(in ascending order) of the singly linked list separated by a single space.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
 Output format :
For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
1
1 2 3 3 3 3 4 4 4 5 5 7 -1
Sample Output 1 :
1 2 3 4 5 7 
Sample Input 2 :
2
10 20 30 40 50 -1
10 10 10 10 -1
Sample Output 2 :
10 20 30 40 50
10
*/

/*
Approach
1.Create two pointer , t1 and t2
2.t1 points to 1st element and t2 points to adjacent node
3.if both node are same then increment t2 .
4.otherwise attach both the nodes which are not same and skip the same node ,make t1 = t2 and make t2 points to adjacent node of t1.
5.check for the corner cases when standing at lastNode and 2nd Last node
 1->1->1->2->3->3->NULL and for 1->1->1->2->3->4->5->6->7->NULL


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

Node *removeDuplicates(Node *head)
{
    //Write your code here

	//if LL is empty
	if(head == NULL){
		return NULL;
	}

	Node *temp1 = head;
	Node *temp2 = temp1->next;
	while(temp2->next != NULL ){
		if(temp1->data == temp2->data){
			temp2 = temp2->next;
		}else{
		temp1->next = temp2;
		temp1 = temp2;
		temp2 = temp1->next;
		}
	}
	//after while loop temp2 is pointing to last node

	//corner cases for 1->1->1->2->3->3->NULL and for 1->1->1->2->3->4->5->6->7->NULL
	//checking last and 2nd last Node
	if(temp1->next != NULL){
		// after while loop we get this o/p - 1->2->3->3->NULL
		//here we are checking whether last and 2nd last Node are same so making 2nd last node next NULL
		if(temp1->data == temp2->data){
			//so maing 2nd last node next as NULL
			//1->2->3->NULL
			temp1->next = NULL;
		}else{
			//1->2->3->4->5->6->7->NULL
			temp2->next = NULL;
		}
	}
	return head;
}