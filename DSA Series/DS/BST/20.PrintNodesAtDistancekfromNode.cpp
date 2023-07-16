/*

Print nodes at distance k from node
Send Feedback
You are given a Binary Tree of type integer, a target node, and an integer value K.
Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
Example:
For a given input tree(refer to the image below):
1. Target Node: 5
2. K = 2
alt txt

Starting from the target node 5, the nodes at distance K are 7 4 and 1.
Input Format:
The first line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

The second line of input contains two integers separated by a single space, representing the value of the target node and K, respectively.
Output Format:
All the node data at distance K from the target node will be printed on a new line.

The order in which the data is printed doesn't matter.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3 1
Sample Output 1:
9
6
Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
3 3
Sample Output 2:
4
5


*/

/*

APPROACH
1.INITIALLY FINDING THE TARGET NODE
2.IF TARGET NODE IS NOT ROOT NODE THEN PRINT NODE PRESENT AT DEPTH K
3.IF TARGET NODE IS NOT ROOT NODE THEN SEARCH IN LST AND RST FOR TARGET NODE
4.IF LST DOESN'T RETURNS -1 THEN TARGETNODE IS PRESENT IN LST OTHERWISE ITS NOT PRESENT
5.TWO CASE FOR PRINTING NODE AT DISTANCE K FROM TARGET NODE
    A. NODE SUBTREE (PRINTING NODE AT DEPTH K FROM TARGET NODE) - DOWNWARD DIRECTION
    B. NODE ANCESTORS - UPWARDS FROM TARGET NODE
       a finding distance of all ancestors from target node .
       b.for all ancestors search other subtree nodes at distance k - ld or rd .
          i. if target node is present in Ancestor leftSide then Search in RST and print nodes
          ii.if target node is present in Ancestor righttSide then Search in LST and print nodes.
*/





/**********************************************************

        Following is the Binary Tree Node class structure

        template <typename T>
        class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
        };

***********************************************************/
void printAtDepthKDown(BinaryTreeNode<int> *root, int k){
        // Base Case 
         if (root == NULL || k < 0)  return; 

        if(k == 0){
                cout<<root->data<<endl;
                return;
        }
        printAtDepthKDown(root->left,k-1);
        printAtDepthKDown(root->right,k-1);
}


// Prints all nodes at distance k from a given target node. 
// The k distant nodes may be upward or downward.
// This func Returns distance of root from target node, 
//it returns -1 if target node is not present in tree rooted with root.

int nodeAtDistanceKHelper(BinaryTreeNode<int> *root,int node,int k){
        
        // If tree is empty return -1
        if(root == NULL){
                return -1;
        }
        
          // If target is same as root.
          // use printAtDepthKDown to print all nodes at distance k in subtree rooted with 
          // target or root 
        if(root->data == node){
           printAtDepthKDown(root,k);
           //After printing nodes , returning distance to Ancestor Node
           //As root node is target  and distance b/w them is Zero.
           return 0;
        }

        // Search for target node in LST if target Node is not equal to RootNode
        int leftD = nodeAtDistanceKHelper(root->left,node,k);
        // if leftDistance is not equal to -1 then target node is present in LST
        if(leftD != -1){
               // If root is at distance k from target, print root 
                 if(leftD + 1 == k){
                   cout << root->data << endl; 
                   }  
                    else{
                         printAtDepthKDown(root->right,k-leftD-2);   
                }
         // Add 1 to the distance and return value for parent calls 
        return 1 + leftD;
        }


        // Note that we reach here only when node was not found in left subtree 

       // Search for target node in RST
        int rightD = nodeAtDistanceKHelper(root->right,node,k);
        // if rightDistance is not equal to -1 then target node is present in RST
        if(rightD != -1){
                 if(rightD + 1 == k){
                   cout << root->data << endl; 
                   }  
                    else{            
                // calculating distance to go to Ancestor of TargetNode then from Ancestor to its LeftChild and from its
                // leftChild finding node at depth (k-rightD-2) 
                // (TargetNode to its Ancestor is (rightD + 1) - After this operation standing at Ancestor)
                //Now going to Ancestor's leftChild so add 1.  (i.e (rightD + 1) + 1)
                // Print Node at distance of [k-[(rightD + 1) + 1]) from Ancestors leftChild
                  printAtDepthKDown(root->left,k-rightD-2);   
                }
        return 1 + rightD;
        }

        // If target was neither present in left nor in right subtree 
        return -1;
       
}


void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
   int x = nodeAtDistanceKHelper(root,node,k);

}

