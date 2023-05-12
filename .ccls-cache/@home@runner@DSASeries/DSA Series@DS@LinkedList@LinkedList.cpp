#include<iostream>
using namespace std;
#include "Node.cpp";

Node insertNode(Node *head,int i,int data){
  Node *newNode = new Node(data);
  int count = 0;
  Node *temp = head;

  //inserting node at front
  if(i == 0){
    newNode->next = head;
    head = newNode;
    return head;
  }
  
  while(temp != NULL && count < i-1){
    temp = temp->next;
    count++;
  }
  //if temp not null and reach at correct node
  if(temp != NULL){
      newNode->next = temp->next;
      temp->next = newNode;
  }
}

Node* takeInputTwo(){
  int data;
  cin>>data;

  //assigning p0inter variable head of type node to NULL
  Node *head = NULL;
  Node *tail = NULL;

  //taking input untill data is -1
  while(data != -1){

    //creating newNode of type Node with data as parameter
    Node *newNode = new Node(data);
    //if there is only one Node then both head and tail will point to same Node
    if(head == NULL){
      head = newNode;
      tail = newNode;
    }else{
      tail->next = newNode;
      tail = tail->next; // or tail = newNode; tail will point to newNode;
    }

    cin>>data;
  }
  return head;
}

Node* takeInput(){
  int data;
  cin>>data;

  //assigning pinter variable head of type node to NULL
  Node* head = NULL;

  //taking input untill data is -1
  while(data != -1){

    //creating newNode of type Node with data as parameter
    Node *newNode = new Node(data);
    if(head == NULL){
      head = newNode;
    }else{
      //creating temp variable to store head value so that it doesn't get lost while traversing
      Node *temp = head;

      //traversing whole list and then after leaving the loop appending the newNode address to last node . NULL is replaced by newNode address.
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next = newNode; 
    }

    cin>>data;
  }
  return head;
}

void print(Node *head){
  //making temp head so that head doesn't get lost
  Node *temp = head;
  while(temp->next != NULL){
    cout<<temp->data <<" ";
    temp = temp -> next;
  }
}

int main(){

Node *head = takeInputTwo();
  int i,data;
  cout>>i>>data;
  head = insertNode(head, i, data);




  
  //Statically
  //creating an object n1 of type Node
  Node n1(1);
  Node n2(2);
  Node n3(3);
  Node n4(4);
  Node n5(5);
  

  //storing first node address to head 
  Node *head = &n1;
  
  //head->1->2
  //giving address of n2 to n1
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  print(head);

    /*
  //Dynamically
  Node *n3 = new Node(10);
  Node *head = n3;
  
  Node *n4 = new Node(20);
  n3->next = n4;
  */
}