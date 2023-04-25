/*
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
Input format :
Integer N
Output Format :
Integer W
Constraints :
1 <= N <= 30
Sample Input 1 :
4
Sample Output 1 :
7
Sample Input 2 :
5
Sample Output 2 :
13
*/

int staircase(int n){
  
     //base case
     //we can't go below staircase
     if(n<0){
         return 0;
     }

  //if we are standing on ground no movement is also 1 way and 1 is represent by only 1.
  //like 3 is (1+1+1) or (2+1) or (1+2)
     if(n ==1 || n==0){
         return 1;
     }

    int x,y,z;
    //taking 1 step
    x = staircase(n-1);
    //taking step 2
    y = staircase(n-2);
    //taking step 3
    z = staircase(n-3);

    return x + y + z;
    
}