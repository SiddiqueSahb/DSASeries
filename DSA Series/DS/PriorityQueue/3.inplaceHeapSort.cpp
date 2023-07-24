/*
Code : In-place heap sort
Send Feedback
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
*/  

/*
APPROACH

TWO STEPS TO FOLLOW

STEP 1 - BUILD HEAP IN INPUT ARRAY

1.INITIALLY ASSUMING 1ST ELEMENT OF AN ARRAY IS ALREADY IN A HEAP
  AND FOR REMAINING N-1 ELEMENTS WE HAVE TO ADD IN HEAP
2.AFTER EVERY INSERTION OF AN ELEMENT , CHECK HEAPY PROPERTY AND DO HEAPIFY PROCESS
  BY CALCULATING CHILDINDEX AD PARENT INDEX.(i.e IF PARENT IS GREATER THAN CHILD DO SWAP )
  NOW PARENTINDEX WILL BECOME CHILD INDEX

AFTER STEP 1 HEAP PROPERTY IS SATIFIED
AS HEAP IS BUILD FROM AN ARRAY BUT IT IS NOT SORTED


STEP 2 - SORTING HEAP USING REMOVE MIN PROCEDURE
1. SWAPPING 1ST AND LAST ELEMENT OF HEAP
2. DECREASING THE SIZE OF AN ARRAY/HEAP (ASSUMING LAST ELEMENT IS ALREADY SORTED)
3. AFTER SWAPPING AND DECREASING THE SIZE , CHECK HEAP PROPERTY AND APPLY HEAPIFY PROCESS
   TO MAINTAIN HEAP



*/  
#include <iostream>
using namespace std;


void inplaceHeapSort(int pq[], int n) {

  //STEP 1
	// Build the heap in input array
	for(int i = 1; i < n; i++) {
		
		int childIndex = i;
		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}
	}

  //AFTER STEP 1 HEAP PROPERTY IS SATIFIED
  //AS HEAP IS BUILD FROM AN ARRAY BUT IT IS NOT SORTED
  //STEP 2 - SORTING HEAP USING REMOVE MIN PROCEDURE
	// Remove elements
	int size = n;

  //DOING SORTING UNTILL SIZE OF AN ARRAY BECOMES 1
	while(size > 1) {
    
    //SWAPPING 1ST AND LAST ELEMENT OF HEAP
		int temp = pq[0];
		pq[0] = pq[size - 1];
		pq[size-1] = temp;

    //DECREASING THE SIZE OF AN ARRAY
		size--;

    //CALCULATING PARENT , LEFTCHILD AND RIGHT CHILD OF HEAP
		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndex = 2 * parentIndex + 2;

    //AFTER EVERY DELETION DOING HEAPIFY PROCESS TO MAINTAIN HEAP PROPERTY
		
        //LEFTCHILD SHOULD BE WITHIN THE HEAP SIZE
        while(leftChildIndex < size){
            //initially min will be root.creating var minIndex bcz for further heapify minIndex will be become new Parent
            int minIndex = parentIndex;
             // leftChild is less than Parent then minIndex will be leftChild (min value will be of leftChildNode)
            if(pq[minIndex] > pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            //Comparing MinValue and RightChild and also check rightChildIndex is within the heapSIze
            if(rightChildIndex < size && pq[rightChildIndex]<pq[minIndex]){
                minIndex = rightChildIndex;
            }
            
            if(minIndex == parentIndex){
                break;
            }
            
            //swapping with parents
            int temp = pq[minIndex]; //min element to temp
            pq[minIndex] = pq[parentIndex]; //parent shifted down
            pq[parentIndex] = temp; // min element becomes parent

            //After swapping  minIndex will become parent,and updates its leftChildIndex and rightChildIndex
            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }
	}









}


int main() {
	int input[] = {5, 1, 2, 0, 8};
	inplaceHeapSort(input, 5);
	for(int i = 0; i < 5; i++)
	{
		cout << input[i] << " ";
	}
	cout << endl;



}