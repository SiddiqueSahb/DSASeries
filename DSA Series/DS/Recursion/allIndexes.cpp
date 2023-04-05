/*
All Indices of Number
Send Feedback
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in the output array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
Return the size of the output array
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4
*/



int allIndexes(int input[], int size, int x, int output[]) {

    // If the input array becomes empty
      if(size == 0)
        return 0;
 
         
    // Getting the recursive answer
      int smallAns = allIndexes(input, size - 1, x, output);
     
      // If the last element of input array is equal to x
    if(input[size - 1] == x)
    {
      // Insert the index of last element of the input array into the output array
      // And increment ans
      output[smallAns++] = size - 1;
    }
    return smallAns;
}

