/*
  Return subset of an array
Send Feedback
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.


Note : The order of subsets are not important.


Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)

Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 

*/


//proper
int subset(int input[], int n, int output[][20]) {
    // Write your code here
	if(n==0)
	{
		output[0][0]=0;
		return 1;
	}
	else
	{
		//calling recursive call till we reach array of size 0
		int size=subset(input+1,n-1,output);
		int i,j;
		
		for(i=0;i<size;i++)
		{
			output[size+i][0]=output[i][0]+1; // filling 1st column of 2D array with len of i/p
			output[size+i][1]=input[0]; //filling 2nd column with array's 1st elemnt 
			for(j=1;j<=output[i][0]+1;j++)
				output[size+i][j+1]=output[i][j];
		}
		return 2*size; //new 2d row will always be double.
	}
}