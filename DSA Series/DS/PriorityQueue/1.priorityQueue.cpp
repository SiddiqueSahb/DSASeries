/*
 Complete Binary Tree (CBT) is stored in Array Form but view as Tree Form
 For priorityQueue - it is implemented using heap (CBT or Almost Complete Binary Tree )
 Following Functions are there in PriorityQueue
 1.isEmpty()
 2.getSize()
 3.getMin()
 4.insert()
 5.removeMin

 Heap data structure is a complete binary tree that satisfies the heap property, 
 where any given node is always greater than its child node/s and the key of the root node is the largest among all other nodes. This property is also called max heap property.
 AND
always smaller than the child node/s and the key of the root node is the smallest among all other nodes. This property is also called min heap property.

Heapify
Heapify is the process of creating a heap data structure from a binary tree. It is used to create a Min-Heap or a Max-Heap.

NOTE :
        IF ARRAY INDEX STARTS FROM 1
        Getting  parentIndex from childIndex  = floor(childIndex/2); //initially
        int leftChildIndex = 2*parentIndex;
        int rightChildIndex = 2*parentIndex + 1;

          
           */
#include<vector>

class PriorityQueue {
//create vector to store data
vector<int> pq;

public :
//Constructor
PriorityQueue(){
  
}

int isEmpty(){
  return pq.size() == 0;
}

//Returns the no of element present
int getSize(){
  return pq.size();
}

int getMin(){
  // if tree is empty then dont access the element
  if(isEmpty()){
    return 0;
  }
  //1st element in heap is min (in case of min heap)
  pq[0];
}


/*
APPROACH MIN HEAP INSERTION

1.Insert the new element at the end of the tree.
2.AFTER EVERY INSERTION , CHILD WITH PARENT 
3.IF CHILD IS LESS THAN PARENT DO  SWAP
4.After swapping value of childIndex and parentIndex changes,new value of childIndex and parentIndex is  calculated , while loop ends when childIndex > 0 as childIndex is now root.
*/

//FUNC - INSERT IN HEAP
void insert(int element){
 // insert element at the end of vector 
 pq.push_back(element);

 //HEAPIFY 
  
//To get the parentIndex , we need childIndex
//pq.size() - 1 :- provides index of last element present in vector
 int childIndex =  pq.size() - 1;
 while(childIndex > 0){
    int parentIndex = (childIndex - 1)/2;
 // If childIndex is less than parentIndex do swapping 
 if(pq[childIndex] < pq[parentIndex]){
   int temp = pq[childIndex];
   //child becomes parent
   pq[childIndex] = pq[parentIndex];
   //parent becomes child
   pq[parentIndex] = temp; 
 }else{
   // break is done bcz if childNode is greater than parentNode then no need to swap, so break the loop
   break;
 }
 //after swapping value of childIndex and parentIndex changes,new value of childIndex and parentIndex is  //calculated , while loop ends when childIndex > 0 as childIndex is now root.
  childIndex = parentIndex;
 } 
}

/*

APPROACH
1.Since deleting an element at any intermediary position in the heap can be costly, 
 so we can simply replace the element to be deleted by the last element and 
 delete the last element of the Heap. 
2.Replace the root or element to be deleted by the last element.
3.Delete the last element from the Heap.
4.Since, the last element is now placed at the position of the root node. So, it may not follow the heap property. Therefore, heapify the last node placed at the position of root.




*/


//FUNC - REMOVE MIN FROM HEAP
//T.C = O(logn) - to remove 1 element so for n element O(nlogn)
      int removeMin() {
        // Write your code here
        if(isEmpty()){
            return 0;
        }
        //get the 1st element ,i.e min element
        int ans = pq[0];
       //replacing last element with 1st element in vector
        pq[0] = pq[pq.size() - 1];
        // removing last element
        pq.pop_back();
        

        //Min Heapify (max value will be present downwards )
        // comparing parent with both of its child and find min among all and swap it with parent.
        // Initially root will parent so 0
        int parentIndex = 0; 
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2; 
       
        while(leftChildIndex < pq.size()){
            //initially min will be root.creating var minIndex bcz for further heapify minIndex will be become new Parent
            int minIndex = parentIndex;
             // leftChild is less than Parent then minIndex will be leftChild (min value will be of leftChildNode)
            if(pq[minIndex] > pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            //Comparing MinValue and RightChild and also check rightChildIndex is within the heapSIze
            if(rightChildIndex < pq.size() && pq[rightChildIndex]<pq[minIndex]){
                minIndex = rightChildIndex;
            }
            
            if(minIndex == parentIndex){
                break;
            }
            
            //swapping with parents
            int temp = pq[minIndex]; //min element to temp
            pq[minIndex] = pq[parentIndex]; //parent shifted down
            pq[parentIndex] = temp; // min element becomes parent

            //After swapping  minIndex will become parent,and updates its leftChildIndex and rightChildIndex
            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }
        return ans;
    }
  
};