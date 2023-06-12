/*
Delete every N nodes
Send Feedback
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'M,' and 'N,' respectively. A single space will separate them.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= P <= 10^5
Where P is the size of the singly linked list.
0 <= M <= 10^5
0 <= N <= 10^5 

Time Limit: 1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
2 2
Sample Output 1 :
1 2 5 6
Sample Input 2 :
2
10 20 30 40 50 60 -1
0 1
1 2 3 4 5 6 7 8 -1
2 3
Sample Output 2 :
1 2 6 7
Explanation of Sample Input 2 :
For the first query, we delete one node after every zero elements hence removing all the items of the list. Therefore, nothing got printed.

For the second query, we delete three nodes after every two nodes, resulting in the final list, 1 -> 2 -> 6 -> 7.
*/

//APPROACH

/*
CASE 1 - M = 0 N = 3
CASE 2 - M = 3 N = 0
CASE 3 - M = 2 N = 3
//CHECK AND GET THE CORNER CASES IN THIS TWO LL
LL 10 22 10 26 11 7 8 1 23 5 1 -1
LL 1 2 3 4 5 6 7 8 -1
m = 2 n = 3

1.CREATE TWO VARIABLE COUNT1 AND COUNT2 AND INITIALIZE WITH 1 TO TRAVERSE TILL M AND N NODES
2.CREATE TWO VARIABLE TEMP1 AND TEMP2 INITILIZE WITH HEAD POINTER
3.CHECK COUNT1 IS EQUAL TO M OR NOT
4.IF NOT INCREMENT THE TEMP1 POINTER AND COUNT1 VALUE , DO THIS UNTIL COUNT1 IS EQUAL TO M
5.AFTER EXITING LOOP INITIALIZE TEMP2 WITH TEMP1->NEXT
6.CHECK COUNT2 IS EQUAL TO N OR NOT
7.IF NOT INCREMENT TEMP2 POINTER AND COUNT2 VALUE ,  DO THIS UNTIL COUNT2 IS EQUAL TO N
8.INCREMENT TEMP2 POSN BY 1 AFTER EXITING LOOP (CORNER CASE - CHECK WHETHER TEMP2 ISNT NULL THEN ONLY INCREMENT )
9.NOW TEMP1 WILL BECOME TEMP2
10.RESET COUNT1 AND COUNT2 (RESETING BCZ WE WANT TO AGAIN SKIP AND DELETE NODE)
11.DO THIS UNTILL TEMP1 0R TEMP2 NOT NULL

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

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
	//if LL is empty or not
	if(head == NULL){
		return head;
	}

	// Not skipping any node and deleting every node
	if(M == 0 && N != 0){
		return NULL;
	}
	
	//Just Skipping node and not deleting any node so LL will be as it is.
	 if(M != 0 && N == 0){
		return head;
	}


	Node *temp1 = head;
	Node *temp2 = head;
while((temp1 || temp2) != NULL){
	int count1 = 1;
	int count2 = 1;
  //INCLUDING NODE && checking temp1->next != NULL bcz for assigning temp2
	while(count1 != M && temp1->next != NULL){
		temp1 = temp1->next;
		count1++;
	}
	temp2 = temp1->next;
  //DELETING NODE 
	while(count2 != N && temp2 != NULL){
    // node to be deleted is store in temp 
    Node *temp = temp2;
	  delete temp;
		temp2 = temp2->next;;
		count2++;
	}
	//After exiting loop checking whether temp2 has become NULL or not so that we dont access NULL value
	if(temp2 != NULL){
		temp2 = temp2->next;
	}	
  //JOINING AFTER DELETING SOME NODE
	temp1->next = temp2;
	temp1 = temp2;
}
	return head;
}









