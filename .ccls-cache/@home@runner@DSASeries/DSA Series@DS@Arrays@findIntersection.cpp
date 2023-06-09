// Online C++ compiler to run C++ program online
/*

Array Intersection
Send Feedback
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in ascending order.


Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
For each test case, print the intersection elements in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec 
Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10
Sample Output 1 :
2 3 4
10
Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 2 2
Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array. Similarly, the second '2' of the first array matches with the second '2' if the second array.
  */



#include <iostream>
using namespace std;

// void printArray(int arr[],int n){
//     for(int i= 0 ; i<n;i++){
//         cout<<arr[i]<<"";
//     }
//     cout<<endl;
// }

int main() {
    // Write C++ code here
 int arr1[3] = {6,2,3};
 int arr2[5] = {2,6,2,3,4};
 int arr3[1000] = {0};
 int size1 = sizeof(arr1)/sizeof(arr1[0]);
 int size2 = sizeof(arr2)/sizeof(arr2[0]);
    for (int i = 0; i < size1; i++) {
      for (int j = 0; j < size2; j++) {
        if (arr1[i] == arr2[j]) {
          arr3[i] = arr1[i];
          cout << arr2[j]<<" ";
          arr2[j] = -2;
          break;
        }
      }
    }
//printArray(arr3,size3);
}

//Approach 2
//With less time complexity 
void intersection(int *input1, int *input2, int size1, int size2)
{
    //Write your code here
  
  //sort both the input array
  sort(input1,input1+size1);
  sort(input2,input2 + size2);


  int i=0,j=0;
 while(i<size1 && j<size2){
        if(input1[i]==input2[j]){
             cout<<input1[i]<<" ";
             i++;
  }
if(input1[i] < input2[j]){
  i++;
} else {
  j++;
}
 }
}

//check if else part
void intersection(int *input1, int *input2, int size1, int size2)
{
    //Write your code here
  
  //sort both the input array
  sort(input1,input1+size1);
  sort(input2,input2 + size2);


  int i=0,j=0;
 while(i<size1 && j<size2){
        if(input1[i]==input2[j]){
             cout<<input1[i]<<" ";
             i++;
             j++;
  }
else if(input1[i] < input2[j]){
  i++;
} else {
  j++;
}
 }
}

