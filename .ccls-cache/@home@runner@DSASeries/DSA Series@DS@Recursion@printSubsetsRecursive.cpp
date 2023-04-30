/*
  Print Subsets of Array
Send Feedback
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
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


void printSubsets(int input[],int size,int output[],int m){
if(size == 0){
	for(int i = 0;i<m;i++){
		cout<<output[i]<<" ";
	}
	cout<<endl;
	return;
}
printSubsets(input+1, size-1, output, m);
output[m] = input[0];
m++;
printSubsets(input+1, size-1, output, m);
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
	int output[50];
	printSubsets(input,size,output,0);
    
}


//Approach 2 - 
void printSubsets(int input[],int size,int output[],int m){
// input 1 2 3
// 1st part is done by us and remaining recursion do

  int newoutput[m+1]; // creatin new output of size greater by 1 of output
  int i;
  //when we recieve output by solving with recursion we copy it to newoutput and 1st element which is handle by us is attach
  //to newoutput
  for(i = 0;i<m;i++){
    newoutput[i] = output[i];
  }
  newoutput[i] = input[0];
  printSubsets(input+1,size-1,newoutput,m+1); //inluding 
  printSubsets(input+1,size-1,output,m);// not including
  

  
}

printSubsets(input+1, size-1, output, m);
output[m] = input[0];
m++;
printSubsets(input+1, size-1, output, m);
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
	int output[0];
  int m = 0;
	printSubsets(input,size,output,m);
    
}

