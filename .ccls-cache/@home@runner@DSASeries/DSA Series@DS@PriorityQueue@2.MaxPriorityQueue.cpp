// class PriorityQueue {
//     // Declare the data members here

//    public:
//     PriorityQueue() {
//         // Implement the constructor here
//     }

//     /**************** Implement all the public functions here ***************/

//     void insert(int element) {
//         // Implement the insert() function here
//     }

//     int getMax() {
//         // Implement the getMax() function here
//     }

//     int removeMax() {
//         // Implement the removeMax() function here
//     }

//     int getSize() { 
//         // Implement the getSize() function here
//     }

//     bool isEmpty() {
//         // Implement the isEmpty() function here
//     }
// };



#include <vector>
class PriorityQueue
{
    // Declare the data members here
    vector<int> pq;

public:
    PriorityQueue()
    {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    int getSize()
    {
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }

    void insert(int element)
    {
        // Implement the insert() function here
        // insert element at the end of vector 
        pq.push_back(element);

        //To get the parentIndex , we need childIndex
        //pq.size() - 1 :- provides index of last element present in vector
        int childIndex = pq.size() - 1;

        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            // if parentNode is less than childNode
            if(pq[parentIndex] < pq[childIndex]){
                //store parent in temp
                int temp = pq[parentIndex];
                //replace parent with childNode
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }else {
                break;
            }

           //after swapping value of childIndex and parentIndex changes,new value of childIndex and parentIndex is  
           //calculated , while loop ends when childIndex > 0 as childIndex is now root.
            childIndex = parentIndex;
        }
    }

    int getMax()
    {
        // Implement the getMax() function here
        if (isEmpty())
            return 0;
        return pq[0];
    }

    int removeMax()
    {
        // Implement the removeMax() function here
        if(isEmpty()){
            return 0;
        }
        // get the max element
        int max = pq[0];
        //replace last element with 1st element
        pq[0] = pq[pq.size() - 1];
        //remove last element
        pq.pop_back();

          // initially root node is parent
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while(leftChildIndex > 0){
            
          //initially max will be root.creating var minIndex bcz for further heapify maxIndex will be become new Parent
          int maxIndex = parentIndex;

        // Comparing parentNode and leftChild
        if(pq[maxIndex] < pq[leftChildIndex]){
              maxIndex = leftChildIndex;
        }
        //Comparing maxValue with rightChild to get new  maxValue and 
        //also check rightChildIndex is within the heapSize
        if(rightChildIndex < pq.size() && pq[maxIndex] < pq[rightChildIndex]){
            maxIndex = rightChildIndex;
        }

        if (maxIndex == parentIndex) {
          break;
        }

        // swapping with parents
        int temp = pq[maxIndex];        // max element to temp
        pq[maxIndex] = pq[parentIndex]; // parent shifted down
        pq[parentIndex] = temp;         // max element becomes parent

        // After swapping  maxIndex will become parent,and updates its
        // leftChildIndex and rightChildIndex
        parentIndex = maxIndex;
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = 2 * parentIndex + 2;
        }
        return max;
    }
};