/*
Quick Sort Code
Send Feedback
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
  */


//	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
//	Skeleton code to achieve this:
	#include <iostream>
	#include<math.h>
	using namespace std;
	
	int doPartition(int input[],int si,int ei){

		//pick 1st element as pivot
		int pivot = input[si];

		//get the count of all elements less than pivot
		int count = 0;
		for(int i = si+1;i<=ei;i++){
			if(input[i]<=pivot){
				count++; 
			}
		}

		//get index to place pivot after adding
		int pIndex = si+count;
		swap(input[pIndex],input[si]);

		//check until i reaches pindex and j reaches pindex
		int i = si,j = ei;
		while(i<=pIndex && j>=pIndex){
			//check if element is less than pivot , if yes then increment index
			while(input[i]<=pivot){
					i++;
			}

			//check if element is greater than pivot , if yes then decrement index
			while(input[j]>pivot){
					j--;
			}

			//if element at index i is not less than pivot and element at index j not greater than pivot then swap it.
			if(i<pIndex && j>pIndex){
				swap(input[i++],input[j--]);
			}
		}

		return pIndex;

	}

	void quickSorts(int input[], int start, int end)
	{
    		// your code goes here
			//base case
			if(start>=end){
				return;
			} 

			int pivotIndex = doPartition(input,start,end);
			//calling quicksort on left part of array
			quickSorts(input,start,pivotIndex-1);
			//calling quicksort on right side of array
			quickSorts(input,pivotIndex+1,end);
	}

		


void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
	quickSorts(input,0, size-1);
}