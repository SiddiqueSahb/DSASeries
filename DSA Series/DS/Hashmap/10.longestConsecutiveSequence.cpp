/*
Longest Consecutive Sequence
Send Feedback
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
Output format:
The first and only line of output contains starting and ending element of the longest consecutive sequence. If the length of  the longest consecutive sequence is 1, then just print the starting element.
Constraints :
0 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 12 
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16
  */




#include<unordered_map>
#include<vector>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here

    //creating hashmap to store an element and also to keep track whether 
    // element is visited when finding consecutive sequence so that redudant checking for the
    // sequence will be avoided
    unordered_map<int,bool> m;
    unordered_map<int,int> index;
    int maxSeqLength = 0;
    int start = -1 ;
    vector<int> ans;

    //element visiting 
    for(int i = 0;i<n;i++){
        m[arr[i]] = true;
    }

    //storing index of an element in an array
    for(int i = 0;i<n;i++){
        if(index.count(arr[i])== 0){
            index[arr[i]] = i;
        }
    }
   
   //iterating each element one by one 
   for(int i = 0;i<n;i++){
      //check already visited 
      if(m[arr[i]] == false){
          continue;
      }

      //initally seq length will be zero
      //sequence checking will be start from 1st unvisited element
      int seqLength = 0;
      int seqStart = arr[i];
      int curElement = arr[i];

       //checking increasing order way from curElement and not visited
      while(m.count(curElement)>0){
         seqLength++;
          //marking as element is visited
          m[curElement] = false;
          //incrementing value to check next subsequent element
          curElement = curElement + 1;
      }

       //checking decreasing order way from curElement and not visited
       curElement = arr[i]-1;
      while(m.count(curElement)>0){
          seqStart = curElement;
          seqLength++;
          //marking as element is visited
          m[curElement] = false;
          //incrementing value to check next subsequent element

          curElement = curElement - 1;
      }
      

      // start of sequence
      //comparison of maxSequence length and seqlength is done after computing seqlength
      // in forward and backward direction
      // if seqlength is greater than maxSeqlength then update maxSeqlength and start so
      // that start now points to longest consecutive Sequence
     
      if(maxSeqLength <= seqLength){

          //we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] 
          //because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9,
          if(maxSeqLength == seqLength){
              //if size is equal then we check start of both 
              //to know either of which comes first in a given array
         
              if(index[start]>index[seqStart]){
                  // arr 3 7 2 1 9 8 41
                  //Seq = [1, 2, 3]-> start = 1.    Seq = [7, 8, 9] -> seqStart = 7
                  // index[1] is greater than index[7]
                  // we want  start of sequence  which appears before in an array 
                  // 7 appears before so update start
                    
                  start = seqStart;
                
              }

          } else{
               start = seqStart;
               maxSeqLength = seqLength;
          }
         
      }
    
    
      }
    //to get whole sequence
    //   for (int i = 0; i < maxSeqLength; i++) {
    //   ans.push_back(start);
    //   start++;
    //   }
     ans.push_back(start);
     //to get last element of sequence
     int lastELe = start + maxSeqLength - 1;
     ans.push_back(lastELe);
     return ans;
}




