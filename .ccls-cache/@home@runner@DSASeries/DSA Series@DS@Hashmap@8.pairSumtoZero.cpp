/*
Code : Pair Sum to 0
Send Feedback
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0. 
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
Explanation
(2,-2) , (-2,2) will result in 0 , so the answer for the above problem is 2.



//APPROACH

1.TRAVERSING EACH ELEMENT IN AN ARRAY AND STORING ITS COUNT IN HASHMAP
2.IF AN ELEMENT IS NOT PRESENT JUST MARK IT AS 1 IN HASHMAP OTHERWISE INCREMENTS ITS COUNT IN HASHMAP
3.AFTER THAT CHECK ITS NEGATION IS PRESENT OR NOT
4.IF NEGATION IS PRESENT THEN IT MEANS WE GOT THE PAIR AND INCREMENT THE COUNT VALUE
5.REPEAT THE ABOVE STEPS
6.THEN RETURN THE COUNT 

EG. FOR 2 , CHECK -2 IS PRESENT OR NOT 
IF PRESENT THEN INCR THE COUNT 

**special case *****
EDGE CASE FOR INPUT ALL ZEROS
DRY RUN FOR THIS INPUT ARR = [0,0,0,0,0]

HERE WE GET THE PAIR BUT EACH TIME WE GET AN EXTRA PAIR FOR EACH ITERATION
SO WE DECRMENT THE COUNT BY 1
NEGATION OF 0 IS 0
COUNT(0) WE GET 1
DRY RUN AND CHECK THE STEP

What happens if there are multiple 0s in the array. We’ll have to be careful that we don’t
consider (0, 0) where both 0s are on the same index as a valid pair. This problem has
an easy fix. Just make sure that you insert/update the current element after you’ve
printed the pairs (if any) for that iteration.
*/
  

#include <unordered_map>
int pairSum(int *input, int n)
{
    // Write your code here
   //CREATING AN HASHMAP TO STORE THE COUNT
    unordered_map<int, int> m;
    int count = 0;
    //ITERATING TO EACH ELEMENT IN AN ARRAY
    //IF ELEMENT APPEARS FOR FIRST TIME THEN MARK IT AS 1 ELSE INCREMENT THE VALUE
    //CHECK FOR ITS NEGATION IS PRESENT OR NOT
    //IF PRESENT THEN IT MEANS WE HAVE GOT A PAIR AND SO INCREMENT THE COUNT VALUE BY NO OF TIME NEGATION VALUE
    // IS PRESENT
    // EX: -2 -2 1 3 4 2
  // [-2:2 , 1:1, 3:1 , 4:1, 2:1]
  //WHEN REACHING 2 , NEGATION OF 2 IS -2 IS CHECKED , AS IT IS PRESENT THEN 
  // COUNT = COUNT + M[-2];
  // COUNT = 0 + 2 = 2;
  // PAIR [(2,-2),(2,-2)]
    for (int i = 0; i < n; i++)
    {   
        if (m.count(input[i]) == 0)
            m[input[i]] = 1;
        else
            m[input[i]] += 1;
        if (m.count(-input[i]))
        {
            count = count + m[-input[i]];
            // FOR SPECIAL INPUT I.E ARRAY OF ZEROS
            if (input[i] == 0)
                count--;
        }
    }
    return count;
}