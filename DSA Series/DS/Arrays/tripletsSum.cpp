/*
Triplet sum
Send Feedback
You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
Note :
Given array/list can contain duplicate elements.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'X'.
Output format :
For each test case, print the total number of triplets present in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5
Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5


 Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)
 */


int tripletSum(int *input, int size, int x)
{
	//Write your code here
        int count = 0;
        for (int i = 0; i < size; i++) {
          for (int j = i + 1; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
              if ((input[i] + input[j] + input[k]) == x) {
				  count++;
                }
              }
            }
          }
          // printArray(arr3,size3);
          return count;
        }


//Approach 2 (includes duplicate) two pointer approach

int tripletSum(int *input, int size, int x)
{
	sort(input,input+size);
		
	//Write your code here
		int count = 0;
	for(int i = 0;i<size;i++)
	{
	 
		int l = i+1;
		int r = size-1;
		
	
		while(l<r){
			int sum = input[i]+input[l]+input[r];
			if(sum == x){

				//for eg. 13333 sum = 7
				//l=1 r=4 n = 4-1+1 = 4 elements then getting sum of that elements
				if(input[l]==input[r]){
					int n = r-l+1;
					count = count + n*(n-1)/2;
					break;
				}
				else{
					//for eg . 12233 sum = 6
					//here we 1+2+3 = 6,as here elements are same we are getting the frequency of 2 and frequency of 3
					int countl=0, countr=0;
					int y = l;
					while(l<=r && input[l] == input[y]){
						l++;
						countl++;
					}
					y = r;
					while(l<=r && input[r] == input[y]){
						r--;
						countr++;
					}
					count = count + countl*countr;
				}
			
			}
			//if we add and we get sum greater than x then we want lesser element so decrement right index
			else if (sum>x){
				r--;
                        } else {
				// if we get sum less than x then we want greater element	so increment left index	
                          l++;
                        }
                }
	
        }
		return count;
}