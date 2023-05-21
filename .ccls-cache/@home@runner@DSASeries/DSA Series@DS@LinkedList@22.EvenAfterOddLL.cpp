/*
Even after Odd LinkedList
Send Feedback
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40
*/

//APPROACH
/*
1.INITIALLY CLUB ALL EVEN ELEMENTS AND ALL ODD ELEMENTS SO THAT WE CAN JOIN BOTH LL LATER
2.CREATING 4 VAR AND INITIALIZE TO NULL 
	Node *OddH = NULL;
	Node *OddT = NULL;
	Node *EvenH = NULL;
	Node *EvenT = NULL;
 3.SCAN THE I/P LL TO CHECK WHETHER IT IS EVEN OR NOT
 4.IF IT IS ODD ELEMENT THEN CHECK WHETHER ODDH IS NULL OR NOT
 5.IF ODDH IS NULL THEN IT MEANS THAT ODD LL IS EMPTY AND MAKE ODDH AND ODDT POINTS TO THAT NODE AND INCREMENT HEAD POINTER
 6.OTHERWISE IT MEANS ODD LL IS NOT EMPTY SO ATTACH THE ODD ELEMENT NODE TO ODD LL AND UPDATE THE ODDT AND INCREMENT THE       HEAD POINTER
 7.SIMILARY FOR EVEN ELEMENTS NODE CHECK FOR BOTH THE CONDITIONS.
 8.REPEAT THIS PROCESS UNTILL HEAD IS NULL
 9.NOW WE GOT TWO LL ONE IS EVEN AND ONE IS ODD
 10.INSERT NULL AT THE END OF THE BOTH LL 
 11.ATTACH BOTH EVEN AND ODD LINKED LIST BY MAKING ODDT->NEXT  = EVENH BUT BEFORE THAT CHECK FOR CORNER CASES TO GET 
    THE PROPER INSIGHT ABOUT THE CONDITIONS.
 //CORNER CASES
 IF LL IS EVEN 
 IF LL IS ODD
 IF LL IS MIX OF BOTH
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

Node *evenAfterOdd(Node *head)
{
	//write your code here
	if(head == NULL){
		return NULL;
	}
	
	Node *OddH = NULL;
	Node *OddT = NULL;
	Node *EvenH = NULL;
	Node *EvenT = NULL;
	while(head != NULL){
		if((head->data %2) == 0){
			//even Node
			if(EvenH == NULL){
				EvenH = head;
				EvenT = head;
				head = head->next;
			}else{
				EvenT->next = head;
				EvenT = head;
				head = head->next;
			}
		}else{
			//odd Node
			if(OddH == NULL){
				OddH = head;
				OddT = head;
				head = head->next;
			}else{
				OddT->next = head;
				OddT = head;
				head = head->next;
			}
		}
	}
 //THIS CONDN IS USED TO CHECK  WHETHER ALL 4 POINTERS ARE NOT NULL SO THAT WE CAN INSERT 
 //NULL AT THE END OF BOTH ODD AND EVEN LL
 //7->3-> NULL  4->2->8->36->NULL
 if((EvenH && EvenT) != NULL && (OddH && OddT) != NULL){
	 	OddT->next = NULL;
		EvenT->next = NULL;
 }
 //corner cases
//LL   7->3->NULL and OddH points to Node 7 and OddT points Node 3 ,
// 4->2->8->36->NULL EvenH points to Node 4 and EvenT points Node 36
//Checking After exiting loop , before accessing OddT checking whether it is NULL or not so that we can combine 
//both the LL and we can get 7->3->4->2->8->36->NULL
	if(OddT != NULL){
		OddT->next = EvenH;
	}

//corner cases
//if OddH is NULL it means that LL contains only even elements
//For LL 36->42 ->18 ->8 ->20->NULL  , after exiting loop EvenH is at Node 36,Event is at Node 20
//OddH = NULL , OddT = NULL
	if(OddH == NULL){
		return EvenH;
	}
	return OddH;
}