//APPROACH

/*

HERE CHECKINg IS DONE THROUGH CONSTRAINT OF VALUE
SUPPOSE ROOT NODE IS THERE AND VALUE WE CAN PUT IN ROOT NODE IN RANGE OF 2..10(MIN = 2, MAX = 10)
ASSUME ROOT NODE IS 5 SO VALUE IN LST  CAN BE IN RANGE 2..4 (MIN CAN BE 2 AND MAX CAN BE 4)
SO VALUE IN RST  CAN BE IN RANGE 5..10 (MIN CAN BE ROOT DATA AND MAX CAN BE MAX)
REPEAT THIS PROCESS

ROOT DATA > MIN || ROOT DATA < MAX RETURN FALSE

*/


bool isBST3(BinaryTreeNode<int>* root,int min = INT_MIN ,int max = INT_MAX){
  if(root == NULL){
    return true;
  }
  if(root->data < min || root->data > max){
    return false;
  }
  bool  isleftOK = isBST3(root->left,min,root->data - 1);
  bool isRightOK = isBST3(root->right,root->data,max);
  return isleftOK && isRightOK;
  
}