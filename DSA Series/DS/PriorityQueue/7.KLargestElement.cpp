/*
Code : K largest elements
Send Feedback
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k
Output Format :
k largest elements
Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output :
12
16
20
25

*/


#include<vector>
#include<queue>
vector<int> kLargest(int input[], int n, int k){
    /*
    The	first	element	of	the	template	defines	the	class	of	each	element.	It	
    can	be	user-defined	classes	or	primitive	data-types.	Like	in	you	case	it	
    can	be	int,	float	or	double.
    • The	second	element	defines	the	container	to	be	used	to	store	the	
    elements.	The	standard	container	classes	std::vector	and	std::dequeue	
    fulfil	these	requirements.	It	is	usually	the	vector	of	the	class	defined	in	
    the	first	argument.	Like	in	your	case	it	can	be	vector<int>,	vector<float>,	
    vector<double>.
    • The	third	element	is	the	comparative	class.	By	default	it	is	less<T>	but	
    can	be	changed	to	suit	your	need.	For	min	heap	it	can	be	changed	to	
    greater<T>.
    */
  
priority_queue<int , vector <int> , greater<int>> minHeap;

  // create min heap of k elements
    for(int i = 0 ;i<k;i++){
        minHeap.push(input[i]);
    }

    //if element is greater than smallest element in heap , 
    //remove smallest element from heap and push greater element in heap
    for(int i = k;i<n;i++){
        int min = minHeap.top();
        if(input[i] > min){
            minHeap.pop();
            minHeap.push(input[i]);
        }
    }

    //create vector to store all k largest element in heap
    vector<int> ans;
    while(!minHeap.empty()){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    return ans;

}
