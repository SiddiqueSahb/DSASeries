/*
Given a singly linked list of integers, sort it using 'Bubble Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
0 <= M <= 10^3
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Input 2 :
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
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
int length(Node *head){
	Node *temp = head;
	if(temp == NULL){
		return 0;
	}
	int len = length(temp->next);
	return 1 + len;
}

Node *bubbleSort(Node *head)
{
	//if LL is empty or contain only one node
	if(head == NULL || head->next == NULL){
		return head;
	}

//looping one less than size bcz last element will be already sorted
	for(int i = 0;i<length(head)-1;i++){
		Node *prev = NULL;
		Node *curr = head;
		Node *fwd = curr->next;
		while(curr->next != NULL){
			//left node is greater than right node
			if(curr->data > curr->next->data){
				//check if 1st node is greater than 2nd Node 
				if(curr == head){
				curr->next = fwd->next;
				fwd->next = curr;
				prev = fwd;
				head = prev;
			}
			else{
				//swapping Adjacent Node other than 1st Node 
				fwd = curr->next;
				curr->next = fwd->next;
				prev->next = fwd;
				fwd->next = curr;
				prev = fwd;
			}
      } 
		 //if Adjacent Node are already sorted
		 else {
               prev = curr;
               curr = curr->next;
            }
        }
    }
  return head;	
}


