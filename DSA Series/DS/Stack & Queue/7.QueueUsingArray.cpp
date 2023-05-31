// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray {
  T *data;
  int nextIndex;
  int frontIndex;
  int size;
  int capacity; //size of an array
  
  public :
    QueueUsingArray(int s){
       data = new T[s];
       nextIndex = 0;
       frontIndex = -1;
       size = 0;//elements in a queue
       capacity = s;
       
    }
    
    int getSize(){
        return size;
    }
    
    bool isEmpty(){
        return size == 0; 
    }
    
    //insert element
    void enqueue(T element){
        if(size == capacity){
            cout<<"Queue is full "<<endl;
            return;
        }
        data[nextIndex] = element;
        //using modula to make an array circular
        nextIndex = (nextIndex + 1) % capacity ;
        //After inserting 1st element making firstIndex = 0 as we have entered an element
        if(frontIndex == -1){
            frontIndex = 0;
        }
        //after every insertion , increasing size (no of elements in an array)
        size++;
    }
    
    T front(){
        if(isEmpty()){
            cout<<"Queue is empty "<<endl;
            return 0;
        }
        return data[frontIndex];
    }
    
    T dequeue(){
        //Checking Queue whether it is empty or not before removing value
         if(isEmpty()){
            cout<<"Queue is empty "<<endl;
            return 0;
        }
        T ans = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        //When no elements are present reset firstIndex and nextIndex
        if(size == 0){
            frontIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};

int main() {
    // Write C++ code here
   QueueUsingArray<int> q(5);
   q.enqueue(10);
   q.enqueue(20);
   q.enqueue(30);
   q.enqueue(40);
   q.enqueue(50);
   
   cout<<q.front()<<endl;
   cout<<q.dequeue()<<endl;
   cout<<q.dequeue()<<endl;
    cout<<q.getSize()<<endl;
     cout<<q.isEmpty()<<endl;
   

    return 0;
}