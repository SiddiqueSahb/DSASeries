/*
Merge K sorted arrays
Send Feedback
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format:
The first line of input contains an integer, that denotes value of k.
The following lines of input represent k sorted arrays. Each sorted array uses two lines of input. The first line contains an integer, that denotes the size of the array. The following line contains elements of the array.
Output Format:
The first and only line of output contains space separated elements of the merged and sorted array, as described in the task.
Constraints:
0 <= k <= 1000
0 <= n1, n2 <= 10000
Time Limit: 1 second
Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234

*/

/*

APPROACH

METHOD - BRUTE FORCE
1.INSERT ALL ELEMENTS OF K ARRAYS TO ANS ARRAY (N*K ELEMENTS)
2.APPLY SORTING ON IT - O(N*K LOG N*K)
T.C = O(N*Klog(N*K))

METHOD - USING HEAP
1.CREATING A MIN HEAP BY TAKING FIRST ELEMENT OF EACH SORTED ARRAY AND INSERT IT INTO HEAP.
2.HEAP MUST CONTAIN DATA , POSN OF ARRAY , POSN OF DATA IN AN ARRAY 
3.POPPED ELEMENT IS INSERTED INTO ANSWER ARRAY.
4.STORING THIS INFO BCZ WHEN ELEMENT IS POP FROM MIN HEAP  , NEXT ELEMENT TO BE INSERTED FROM SAME ARRAY (if present) IN WHICH THIS POPPED ELEMENT WAS PRESENT.


*/


//OPTIMIZED METHOD
#include<vector>
#include<queue>

class node {
    public:
    int value;
    int arrPosn;
    int valPosn;

    node(int value,int row,int col){
        this->value = value;
        row = arrPosn;
        col = valPosn;
    }
};

//minHeap Comparator
class compare {
    public :
    bool operator(node* a,node* b){
        return a->value > b->value;
    }
};



vector<int> mergeKSortedArrays(vector<vector<int>*> input,int k) {
    // Write your code here

    //creating PriorityQueue
   priority_queue<node*, vector<node*>, compare>  minHeap;

   //push first element of all k arrays into heap
  //T.C = O(KLOGK) - FOR LOOP
   for(int i = 0;i<k;i++){
       //first element of k rows , its array index and position 0 bcz first element to be push
       ////[[4,5,6,7] .[1,3,6],[2,8,9]]
      // pushing in minHeap element 4 , 1, 2 from k sorted array
       node* temp = new node(input[i][0] , i , 0);
       minHeap.push(temp);
   }
  
   vector<int> ans;

  //T.C = O(N*KLogK) = (total n*k element - k(element)) approx = n*k (logk - insertion deletion in heap)
   // pop min element from min heap and insert into ans array 
   //and insert next element from same array(if present)
 //do this untill minHeap doesn't becomes empty
   while(!minHeap.empty()){
      //minHeap - 1,2,4
      //push min element to ans array
       node *temp = minHeap.top();
       ans.push_back(temp);
       //minHeap top - element 1 so pop 1
       minHeap.pop();

       //check if next element is present in an array 
       //arrPosn = 1
       //valPosn = 0
       //next Element from array 1 is to be inserted in minHeap , if its present
        int arrPosn = temp->arrPosn;
        int valPosn = temp->valPosn;
       
       //[[4,5,6,7] .[1,3,6],[2,8,9]]
       // to insert 3 , checking posn of 3 is within the size of an array at posn 1 in 2D array
       if(valPosn + 1 < input[arrPosn].size()){
           node* nextElement = new node(input[arrPosn][valPosn+1],arrPosn,valPosn+1);
           minHeap.push(nextElement);
       }
   }

   return ans;
    
}


//T.C = O(N*KLogN*K)
#include <queue>
vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    // Write your code here
    //create minHeap
    priority_queue<int, vector<int>, greater<int>> pq;
    //push all n*k elements in minHeap
    for (int i = 0; i < input.size(); i++)
        for (int j = 0; j < input[i]->size(); j++)
            pq.push(input[i]->at(j));
    vector<int> v;
    //remove min element from heap each time and push it to ans vector
    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}
