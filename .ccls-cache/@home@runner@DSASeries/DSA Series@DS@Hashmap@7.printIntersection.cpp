/*
Code : Print Intersection
Send Feedback
You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the second array/list (ARR2).


Input format :
The first line of input contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
Print the intersection elements. Each element is printed in a separate line.
Constraints :
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec 
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2
3 
4
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 
2 
2


//APPROACH

ARR1 = 2 6 1 2
ARR2 = 1 2 3 4 2

1.TRAVERSE AN ARRAY1 (CAN TAKE ANY ARRAY) AND STORE THE COUNT OF ELEMENT IN HASHMAP
<1:1> < 2:2> <6:1>
2.TRAVERSE AN ARRAY AND IF COUNT OF PARTICULAR ELEMENT IS GREATER THAN 0 THEN PRINT THE ELEMENT AND
  EACH TIME GOING TO HASHMAP AND DECREMENTING ITS COUNT 
  <1:0> <2:1> <3:-1> <4:-1> <2:0>
3.IF COUNT IN HASHMAP BECOMES -VE THEN INTERSECTION NOT PRESENT
 INTERSECTION - 1 2 2
*/
  
#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
   
    //storing count in hashmap 
    //<1:1> <2:3> 2 - is key and 3 is the count of 2
    unordered_map<int,int> hashmap; 

    //traversing each element of an array and storing its count in hashmap
    for(int i = 0;i<n;i++){
        hashmap[arr1[i]]++;
    }
 
   //traversing 2nd array and decrementing the count in hashmap
   //In hashmap if count of element becomes -ve then it means all its intersection are printed
   // and an extra element is present which doesn't have an intersection
    for(int i =0;i<m;i++){
        if(hashmap[arr2[i]]>0){
            cout<<arr2[i]<<endl;
            hashmap[arr2[i]]--;
        }
    }
}