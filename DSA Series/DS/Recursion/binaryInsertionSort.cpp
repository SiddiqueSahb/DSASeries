/*

Binary insertion sort is a sorting algorithm similar to insertion sort, but instead of using linear search 
to find the position where the element should be inserted, we use binary search. 
Thus, we reduce the number of comparisons for inserting one element from O(N) to O(log N).


Binary Insertion Sort Algorithm
1.We will start by iterating the element from the second element to the last element.
2.Then, we will store the currently considered element in a key.
3.Now, find the position of the elements which are just greater than A[i] elements. We will search for these elements in the subarray from A[0] to A[i-1] using binary search. Let’s say this element is at the index position.
4.So, we will shift all the elements from the index position to [i-1] towards the right.
5.In the end, A[index position] element value will be stored in the key. And it will then get interchanged.


Binary Insertion Sort Complexities
Time Complexity of Binary Insertion Sort
⭐The time complexity of binary insertion sort in the average and worst case is O(N2). While for the best case, the time complexity will be O(NlogN). It is because the num of comparisons for inserting one element is O(log N), and for N elements, it will be O(NlogN).
*/




Implementation of Binary Insertion Sort
#include <bits/stdc++.h>
using namespace std;

//---------------------------Function for binary search---------------------------//
int binarySearchfxn(int arr[], int element, int l, int h)
{
    int m = (l + h) / 2;
		if (element == arr[m])
			return m + 1;
		
		if (h <= l)
			if (element > arr[l]) 
    			return (l + 1);
			else
    			return l;

		if (element > arr[m])
			return binarySearchfxn(arr, element, m + 1, h);

		return binarySearchfxn(arr, element, l, m - 1);
}

//---------------------------Function for insertion sort---------------------------//
void insertionSortfxn(int arr[], int num)
{
	int i, j, k, select, position;

		for (i = 1; i < num; ++i)
		{
			j = i - 1;
			select = arr[i];

		// finding a location where elements should be inserted
			position = binarySearchfxn(arr, select, 0, j);

		// Moving elements from the positions
			while (j >= position)
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = select;
		}
}

//---------------------------Main Function---------------------------//
int main()
{
    FAST;
	int array[] = { 9,7,2,6,4 };
	int size = sizeof(array) / sizeof(array[0]), i;

	insertionSortfxn(array, size);

	cout <<"The Sorted Array is:";
	for (i = 0; i < size; i++)
	cout <<" "<< array[i];

	return 0;
}


