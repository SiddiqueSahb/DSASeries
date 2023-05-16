/*
Length of LL
Send Feedback
For a given singly linked list of integers, find and return its length. Do it using an iterative method.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains elements of the singly linked list separated by a single space. 
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
Output format :
For each test case, print the length of the linked list.

Output for every test case will be printed in a separate line.
 Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
Sample Output 1 :
7
Sample Input 2 :
2
10 76 39 -3 2 9 -23 9 -1
-1
Sample Output 2 :
8
0
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
int length(Node *head)
{
    int count = 0;
  //if LL is empty return 0
    if(head == NULL){
        return 0;
    }
  //Get the input till data is -1
    while(head->data != -1){
        if(head == NULL){
            return 0;
        }
        while(head != NULL){
            head = head->next;
            count = count + 1;
        }
        return count;
    }
  //if we enter -1 intially -1 then returning count = 0;
    return count;
} 

//aproach 2
int length(Node *head)
{
  int count = 0;
  Node *temp = head;
  while(temp != NULL){
    temp = temp->next;
    count++;
  }
return count;
}