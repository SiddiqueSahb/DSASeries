


/*
APPROACH
1.CREATING MIN HEAP OF SIZE K,INSERTING INTIALLY K ELEMENTS IN HEAP
2.


 ELEMENT THAT WILL BE PRESENT AT INDEX 0 IN OUTPUT(SORTED ARRAY) WILL BE PRESENT WITHIN K-1 POSN BEFORE OR AFTER IN GIVEN ARRAY .
//eg arr = 12 15 7 4 9
 OUTPUT : -  15(INDEX 0)
 IN GIVEN ARRAY 15 MAY BE PRESENT WITHIN K-1 POSN AFTER FROM INDEX 0 OR BEFORE FROM INDEX 0 (i.e 15 MAY BE PRESENT IN GIVEN 
 ARRAY AT INDEX 0,1,2) so traverse given array from index 0 to k and push all element in priority queue.

Remove max element from heap and place it at index 0 in an array.
REMOVE 15 FROM HEAP AND PLACED IT AT INDEX 0 IN  ARRAY
//eg arr = 12 15 7 4 9
 OUTPUT : -  15(INDEX 0) 

  FINDING ELEMENT TO PLACE AT INDEX 1 IN OUTPUT ARRAY .
  IN HEAP 12 7 ARE PRESENT, NOW CHECK WITHIN 2 POSN RIGHT AND TWO POSN LEFT FROM INDEX 1 IN GIVEN ARRAY 
  AS 12 7 ARE ALREADY IN HEAP , ADD 4 IN HEAP AND NOW FINDING MAX AMONG 12 7 4 
  Max element among it is 12  so add it IN OUTPUT(SORTED ARRAY) AT INDEX 1
//eg arr = 12 15 7 4 9
 OUTPUT : -  15(INDEX 0) 12(INDEX 1)

SIMILARLY FOR OTHER ELEMENTS OF AN ARRAY.
IF HEAP IS HAVING ELEMENT(LAST K ELEMENTS) AND IN  ARRAY INITAL ELEMENTS ARE SORTED,
 SO NOW REMOVE ELEMENTS FROM HEAP ONE BY ONE AND ADD IT TO SORTED ARRAY.
*/  

#include <iostream>
using namespace std;
#include <queue>

void kSortedArray(int input[], int n, int k) {

  //Creating priorityQueue
	priority_queue<int> pq;
  //Push all k elements in priorityqueue
  //eg arr = 12 15 7 4 9
	for(int i = 0; i < k; i++) {
    //ELEMENT IN HEAP 15 12 7
		pq.push(input[i]);
	}
  // MAINTAINING INDEX J TO INSERT MAX ELEMENT
	int j = 0;
	for(int i = k; i < n; i++) {
    //PICK AND INSERT MAX ELEMENT OF HEAP (15) AT POSN J IN ARRAY
		input[j] = pq.top();
    //REMOVE MAX ELEMENT AND HEAPIFY PROCESS IS DONE (INBUILT FUNCTION)
		pq.pop();
    //ADD ELEMENT IN HEAP WHICH IS AT POSN K  (SO NOW AGAIN ELEMENT IN HEAP ARE 3)
   // PUSH ELEMENT 4 FROM ARRAY 12 15 7 4 9 AS 12 7 ARE PRESENT IN HEAP 
   // NOW IN HEAP WE HAVE 12 7 4  
		pq.push(input[i]);
    //INCR J i.e now next element will be placed at index 1 
		j++;
	}

 //WHEN N-K ELEMENTS ARE SORTED IN AN ARRAY AND K ELEMENTS ARE PRESENT IN HEAP
 //SO K TIMES DO POP AND ADD IT TO ARRAY ONE BY ONE
	while(!pq.empty()) {
		input[j] = pq.top();
		pq.pop();
    j++;
	}

}
	
int main() {
	int input[] = {10, 12, 6, 7, 9};
	int k = 3;
	kSortedArray(input, 5, k);
	for(int i = 0; i < 5; i++) {
		cout << input[i] << " ";
	}
}