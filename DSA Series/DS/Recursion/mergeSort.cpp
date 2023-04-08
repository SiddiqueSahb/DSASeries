// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;

//Approach - using index (LB video method)

void merge(int *arr, int s, int e) {

    int mid = s+(e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void mergeSort(int *arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = s + (e-s)/2;

    //left part sort karna h 
    mergeSort(arr, s, mid);
    
    //right part sort karna h 
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}


//Approach 2 - by dividing array into two halves and using mergetwo arrays method to merge

void merge(int input[],int arr1[ ],int arr2[ ],int size1,int size2){
	int i = 0,j=0,k=0;
	while(i<size1 && j<size2){
		if(arr1[i]<arr2[j]){
			input[k++] = arr1[i++];
		}
		else{
			input[k++]=arr2[j++];
		}
	}

	while(i<size1){
		input[k++] = arr1[i++];
	}

	while(j<size2){
		input[k++] = arr2[j++];
	}
}

void mergeSort(int input[], int size){
       	//basecase
	//if array size is zero or 1 then it is already sorted return true
	if(size<=1){
		return ;
	}

	//else divide the array into two parts by finding mid
	int mid = size/2;
	//creating two arrays of halve sizes
	int size1 = mid;
	int size2 = size-mid;
	int arr1[size1];
	int arr2[size2];
	for(int i = 0;i<mid;i++){
		arr1[i] = input[i];
	}
	int j = 0;
	for(int i = mid;i<size;i++){
		arr2[j] = input[i];
		j++;
	}
	mergeSort(arr1,size1);
	mergeSort(arr2,size2);
	merge(input,arr1,arr2,size1,size2); 
}
