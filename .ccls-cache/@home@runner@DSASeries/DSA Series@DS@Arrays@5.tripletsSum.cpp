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



//Approach 3 (includes duplicate) two pointer approach

//check for the input 
//]]={ -2,-2,-2,0,0,0,-1,-1,-1,1,1,-1,0,-2};

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //removing duplicates for each iteration 
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
          //calculating sum for fixed i and moving 2 pointers j and k
            int sum = arr[i] + arr[j] + arr[k];
          //moving j pointers as we want greater sum
            if (sum < 0) {
                j++;
            }
            //moving k pointers as we want lesser sum
            else if (sum > 0) {
                k--;
            }
            //if sum is 0 then we have found triplet
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                  cout<<"i "<<i<<endl;
                ans.push_back(temp);
               //increment j and k pointer 
                j++;
                k--;
                //skip the duplicates i.e after getting triplets for fixed i and after that check whether incremented j and    previous j are same or not.if they are same increment j as we  will get same triplets again.similartly for j
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = { -2,-2,-2,0,0,0,-1,-1,-1,1,1,-1,0,-2};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}