/*
Check Max-Heap
Send Feedback
Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains true if it represents max-heap and false if it is not a max-heap.
Constraints:
1 <= N <= 10^5
1 <= Ai <= 10^5
Time Limit: 1 sec
Sample Input 1:
8
42 20 18 6 14 11 9 4
Sample Output 1:
true
*/

/*
APPROACH
1.FOR MAXHEAP PARENT SHOULD BE GREATER THAN LEFTCHILD AND RIGHTCHILD FOR EACH SUBTREE
2.LEFTCHILD AND RIGHTCHILD SHOULD BE WITHIN THE SIZE
3.CHECK LEFTCHILD IS WITHIN THE SIZE AND PARENT IS LESS THAN LEFTCHILD SO RETURN FALSE
4.SIMILARLY FOR CHECK FOR RIGHTCHILD
5.OTHERWISE RETURN TRUE


 */ 

//Heap should be CBT and Heap Property should be satisfy


bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for(int i = 0 ; i<n;i++){
    int parentIndex = i;
    int LchildIndex = 2*parentIndex + 1;
    int RchildIndex = 2*parentIndex + 2;
    if(LchildIndex < n && arr[parentIndex]<arr[LchildIndex]){
        return false;
    }
    if(RchildIndex < n && arr[parentIndex] < arr[RchildIndex]){
        return false;
    } 
    }
    return true;
}

// bool isMaxHeap(int arr[], int n){
//    for(int child=1; child<n ;child++)
//     {
//         int parent = (child-1)/2;
//         if(arr[parent]<arr[child])
//             return false;
//     }
// }