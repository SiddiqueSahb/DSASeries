/*
Code : Maximum Frequency Number
Send Feedback
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements are having the maximum frequency, return the element which occurs in the array first.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains most frequent element in the given array.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1

//APPROACH
1.We create a hash table to store frequency of each element of an array as key value pair
2.We traverse each element of an array ,check in hashtable frequency of an element
3.if not present , mark it as 1 else increments its count by 1.
4.Compare max with frequency of an element , if max is lesser then max value will frquency of an element
5.update max and its index
6.After iterating all elements return max freqeuncy element from an array.
*/  


#include<unordered_map>
int highestFrequency(int arr[], int n) {
    // Write your code here
   //creating hashmap (bucket)
    unordered_map<int,int> bucket;
    int max = 0;
    int index = 0;
   //travering each element in an array and for that element checking the count 
   //in the bucket and each time updating the max and index.
    for(int i =0;i<n;i++){
        if(bucket[arr[i]] == 0){
            bucket[arr[i]] = 1;
        }else{
            bucket[arr[i]] += 1;
            if(max<=bucket[arr[i]]){
                max = bucket[arr[i]];
                index = i;
            }
        }
    }
    return arr[index];
}
