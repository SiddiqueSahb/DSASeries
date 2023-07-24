/*
Code : K smallest Elements
Send Feedback
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).
Note: Order of elements in the output is not important.
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of k.
Output Format :
The first and only line of output print k smallest elements. The elements in the output are separated by a single space. 
Constraints:
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output 1 :
1 2 3 5 
*/

/*
APPROACH
1.METHOD BRUTE-FORCE
A.SORT THE ARRAY O(NLOGN)
B.GET THE K ELEMENTS FROM THE ARRAY 0(K)
SO T.C = O(NLOGN)

2.METHOD USING MAX HEAP
A.MAKE MAX HEAP OF FIRST K ELEMENTS 
B.FOR REST OF ELEMENTS , PICK EACH ELEMENT AND COMPARE WITH MAX ELEMENT OF HEAP
C.IF ELEMENT < MAXHEAPTOP THEN POP ELEMENT FROM HEAP AND PUSH ELEMENT TO HEAP
D.REPEAT THE ABOVE PROCESS
E.THIS WAY WE GET ALL K SMALLEST ELEMENT

EG : ARR == 7 10 4 20 15   K=4

CREATING MAXHEAP OF FIRST 4 ELEMENT 
MAXHEAP CONTAINS 20 10 4 7
NOW PICK ELEMENT 15 AND COMPARE IT WITH HEAPTOP (ELEMENT 20)
15 < 20 SO REMOVE 20 FROM HEAP AND INSERT 15 IN HEAP
SO THIS WAY WE GET FIRST K SMALLEST ELEMENT IN HEAP
MAXHEAP CONTAINS - 15 10 4 7

*/

#include <queue>
#include<vector>
vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here

    //CREATE HEAP (MAX)
    priority_queue<int> pq;
   
   // create max heap of k elements
    for(int i = 0 ;i<k;i++){
        pq.push(arr[i]);
    }

    //for n-k elements compare with largest element of heap
    //if element is smaller than largest element in heap , 
    //remove max element from heap and push smaller element in heap
    for(int i = k;i<n;i++){
        int max = pq.top();
        if(arr[i] < max){
            pq.pop();
            pq.push(arr[i]);
        }
    }

  //create vector to store all k smallest element of heap
    vector<int> ans;
    while(!pq.empty()){
        //push top element in heap and then remove it from heap so that again we can get max element
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
