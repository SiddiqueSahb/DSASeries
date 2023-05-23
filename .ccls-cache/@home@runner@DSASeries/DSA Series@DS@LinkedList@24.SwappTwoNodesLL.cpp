/*
Swap two Nodes of LL
Send Feedback
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.
 Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 
 Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
 Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 
*/

//APPROACH
/*
 1.CREATE 4 VARIABLE POINTER FOR SWAPPING TWO NODES
 2.CHECK FOR CASES

CASE 1. IF EITHER OF NODE TO BE SWAPP IS HEAD AND TRAVERSING TO FIND THE POS OF OTHER NODE
//70 80 90 25 65 85 90 -1
//i =0 j= 6 or i = 6 j= 0

CASE 2. IF EITHER OF NODE TO BE SWAPP IS HEAD AND OTHER NODE IS 2ND NODE IN LL
//70 80 90 25 65 85 90 -1
//i =0 j= 1 or j = 0 i = 1

IF i>j then by calculation we are changing i and j value s.t j becomes greater than i
// 3 4 5 2 6 1 9 -1
// i=4 j=2

CASE 3. WHEN SWAPPING NODE PRESENT AT ALTERNATE POS IN LL
//10 20 30 40 50 60
// i = 3 j =4

CASE 4. NO NEED TO SWAP IF I==J JUST RETURN HEAD
// 3 4 5 2 6 1 9 -1
// i =2 j=2

CASE 5. SWAPPING NODE BY GOING TO THERE RESPECTIVE POSN (IF NODE TO BE SWAPPED ARE NOT ALTERNATE )
//10 20 30 40 50 60
// i = 2 j =4
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
// 3 4 5 2 6 1 9 -1
// i=4 j=2

//70 80 90 25 65 85 90 -1
//i =0 j= 6 or i = 6 j= 0

//10 20 30 40 50 60
// i = 3 j =4

// 3 4 5 2 6 1 9 -1
// i =2 j=2

//10 20 30 40 50 60
// i = 2 j =4


Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here

	if(head == NULL){
		return head;
	}

	
	Node *prev1 = head;
	Node *prev2 = head;
	Node *curr1 = head;
	Node *curr2 = head;

	if(i>j){
		//i = 3 j =2
		i = i+j; // i = 3+2 = 5
		j = i-j; // j = 5-2 = 3
		i = i-j; // j = 5-3 = 2
		//i,j = 2,3
	}

// Node to be swapped is at head
	if(i==0){
		// 1st Node is swapped with the 2nd Node (i.e 1st two node of LL need to be swapped)
		if(j == 1){
			curr2 = curr2->next;
			Node *temp = curr2->next;
			curr1->next = temp;
			curr2->next = curr1;
			return curr2;
		}
		//1st Node of LL is swapped with Node present at the position j in LL
		else{
				for(int i = 0;i<j-1;i++){
			prev2 = prev2->next;
		}
		curr2 = prev2->next;
		Node *temp = curr1->next;
		curr1->next = curr2->next;
		curr2->next = temp;
		prev2->next = curr1;
		return curr2;
		}
	}

	// Swapping Node present at Alternate position
	else if(j-i == 1){
		for(int pos = 0;pos<i-1;pos++){
			prev1 = prev1->next;
		}
		curr1 = prev1->next;
		curr2 = curr1->next;
		prev1->next = curr2;
		curr1->next = curr2->next;
		curr2->next = curr1;
		return head;
	}
	//if Node to be swapped is same then no swapping
	else if (i == j){
		return head;
	}
	//When Node to be swapped are not at alternate Positions
	else {
	int pos = 0;
	//Traversing to one step behind the node to be swapped
	while(pos < i-1){
		prev1 = prev1->next;
		pos++;
	}
	//Currently standing at Node to be swapped
	curr1 = prev1->next;
	pos = 0;
  //Traversing to other node which is to be swapped
	while(pos < j-1){
		prev2 = prev2->next;
		pos++;
	}
  //Currently standing at other Node to be swapped
	curr2 = prev2->next;
	//temp is used so that link with other node is not broken while swapping with node
	Node * temp = curr2->next;
	prev1->next = curr2;
	prev2->next = curr1;
	curr2->next = curr1->next;
	curr1->next = temp;
	return head;
	}
  
}