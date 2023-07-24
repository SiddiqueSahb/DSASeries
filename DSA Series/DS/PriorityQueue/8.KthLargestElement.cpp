/*
Kth largest element
Send Feedback
Given an array A of random integers and an integer k, find and return the kth largest element in the array.
Note: Try to do this question in less than O(N * logN) time.
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following contains an integer, that denotes the value of k.
Output Format :
The first and only line of output contains the kth largest element
Constraints :
1 <= N, Ai, k <= 10^5
Time Limit: 1 sec
Sample Input 1 :
6
9 4 8 7 11 3
2
Sample Output 1 :
9
Sample Input 2 :
8
2 6 10 11 13 4 1 20
4
Sample Output 2 :
10

*/

/*
APPROACH

2.METHOD USING MAX HEAP
A.MAKE MIN HEAP OF FIRST K ELEMENTS 
B.FOR REST OF ELEMENTS , PICK EACH ELEMENT AND COMPARE WITH SMALLEST ELEMENT OF HEAP
C.IF ELEMENT > MINHEAPTOP THEN POP SMALLEST ELEMENT FROM HEAP AND PUSH ELEMENT TO HEAP
D.REPEAT THE ABOVE PROCESS
E.THIS WAY WE GET ALL K LARGEST ELEMENT
F.NOW PICK TOP OF MIN HEAP WE WILL GET KTH LARGEST ELEMENT 

CAN TRY FOR THIS INPUT
EG : ARR == 7 10 4 20 15   K=4

*/

#include<queue>
int kthLargest(int* arr, int n, int k) {
    // Write your code here

    
    priority_queue<int , vector <int> , greater<int>> minHeap;

  // create min heap of k elements
    for(int i = 0 ;i<k;i++){
        minHeap.push(arr[i]);
    }

    //if element is greater than smallest element in heap , 
    //remove smallest element from heap and push greater element in heap
    for(int i = k;i<n;i++){
        int min = minHeap.top();
        if(arr[i] > min){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
   return minHeap.top();
}
