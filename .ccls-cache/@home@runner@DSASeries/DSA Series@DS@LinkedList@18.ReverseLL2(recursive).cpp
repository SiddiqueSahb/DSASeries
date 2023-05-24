class Node {
public:
  int data;
  Node *next;

  //constructor calling
  Node(int data){
    this->data = data;
    this->next = NULL;
  }

}

//creating class pair so that we can access its properties and can return two parameters
class Pair(Node *head){
  public:
    Node *head;
    Node *tail;
};

//In previous reverse of LL, we were traversing and then attaching the node but here we are having two pointer head and tail 
//so we dont need to travel at the end , we can directly connect the node.
Pair *reverseLinkedListRec(Node *head)
{
    //Write your code here
	//if list is empty or LL is single
	if(head == NULL || head->next == NULL){
    //creating an object ans of type pair which will return two properties
    //LL - empty so head will be empty , both property will be NULL or
    //LL 1->NULL , both head and tail will point to single node i.e Node 1
		Pair ans;
    ans.head = head;
    ans.tail = head;
    return ans;
	}
//LL 1->2->3->4->NULL
//assuming after calling recursion LL is sorted
// suppose small ans is having head = &Node 4 and tail = &Node 2
	Pair smallAns = reverseLinkedListRec(head->next);
  //4->3->2-> NULL and now we want to connect Node 1 to reversed LL
  //4->3->2->1
  smallAns.tail->next = head;
  //4->3->2->1->NULL
  head->next = NULL;
  Pair ans;
   //IN LL 4->3->2->1->NULL ans.head will point to Node 4 and ans.tail will point to Node 1
  ans.head = smallAns.head
  ans.tail = head;
  return ans;
}

Node *reverseLL(Node *head){
  return reverseLinkedListRec(*head).head;
}