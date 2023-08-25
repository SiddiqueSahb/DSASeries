/*
Buy the ticket
Send Feedback
You want to buy a ticket for a well-known concert which is happening in your city. But the number of tickets available is limited. Hence the sponsors of the concert decided to sell tickets to customers based on some priority.
A queue is maintained for buying the tickets and every person is attached with a priority (an integer, 1 being the lowest priority).
The tickets are sold in the following manner -
1. The first person (pi) in the queue requests for the ticket.
2. If there is another person present in the queue who has higher priority than pi, then ask pi to move at end of the queue without giving him the ticket.
3. Otherwise, give him the ticket (and don't make him stand in queue again).
Giving a ticket to a person takes exactly 1 second and it takes no time for removing and adding a person to the queue. And you can assume that no new person joins the queue.
Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0). Find and return the time it will take until you get the ticket.
Input Format:
The first line of input contains an integer, that denotes the value of total number of people standing in queue or the size of the array of priorities. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array of priorities.
The following contains an integer, that denotes the value of index of your priority. Let us denote it with symbol k.
Output Format :
The first and only line of output contains the time required for you to get the ticket.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
3
3 9 4
2
Sample Output 1 :
2
Sample Output 1 Explanation :
Person with priority 3 comes out. But there is a person with higher priority than him. So he goes and then stands in the queue at the end. Queue's status :  {9, 4, 3}. Time : 0 secs.
Next, the person with priority 9 comes out. And there is no person with higher priority than him. So he'll get the ticket. Queue's status :  {4, 3}. Time : 1 secs.
Next, the person with priority 4 comes out (which is you). And there is no person with higher priority than you. So you'll get the ticket. Time : 2 secs.
Sample Input 2 :
5
2 3 2 2 4
3
Sample Output 2 :
4
*/


/*
APPROACH
1.creating a queue of indexes of priority to maintain sequence of allocation of ticket
(Inserting index in a queue not value as we want a person at index k having priority x )
2.priority of persons(index) are given so push it in a queue 
3.Maintain a priorityQueue of priortites to get the maxpriority (to get the max element)
4.Create a time to know the count i.e after how many people a person get the ticket
5.Priority  doesnt match with highest priority then remove the index from 
  the queue and push to the end of queue
6.Priority matches with highest priority then remove the priority from PriorityQueue , its index from queue
  and increase the time by 1
7.Repeating the Above process untill a person k , having priority x is same as highest priority.

*/  

#include<queue>
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    
    //creating a queue of indexes of priority
    //priority of persons(index) are given .
    queue<int> q;
    for(int i = 0;i<n;i++){
        q.push(i);
    }

   //creating priorityQueue to get the highest priority 
   priority_queue<int> pq;
    for(int i = 0;i<n;i++){
        pq.push(arr[i]);
    }

    // time after which person(i) will get the ticket
    int time = 0;


    // We are calculating a person k time , when he will get the ticket
    // as there may be people with higher priority standing in queue .
    while(q.front() != k || arr[q.front()] != pq.top()){
      //Repeating the below process untill a person k , having priority x is same as highest priority
      //priority of person(i) doesnt match with highest priority then 
      //remove the person i from the the queue and make him stand at the end of the queue
      if(arr[q.front()] != pq.top()){
        int qfront = q.front();
        q.pop();
        q.push(qfront);
         }
       //priority of person(i)  matches with highest priority then 
       //give that person a ticket , remove its priority and remove it from queue.
       //this way other may get chance
        else if(arr[q.front()] == pq.top()){
             pq.pop();
             q.pop();
             time++;
        }
    }
    //as after x no of people , person k gets the ticket
    return time + 1;
}
