int height(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}

	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(option1, max(option2, option3));
}

/*

Brute Force method
In a tree if we want to get the diameter of the tree , we can  calculate the height of left tree and height of right tree and maximum of both will be diameter.But this doesnt work for 
e.g Consider a tree having left subtree with many children and right subtree with having only one child . Here diameter is suppose 6. with calculation of sum of LSTheight and RSTHeight we got 5.
So finding LST diameter , RST diameter , and sum of LSTHeight a& RSTHeight and finding max among them will be diameter of tree.


For Finding height we are going to each node in a tree ,I.e visiting every node once
So T(n) = O(n)

For finding diameter , we are not doing constant work , we are calling height function each time.
Consider two type of tree for checking T.C , first is complete Tree and second one is skew tree.
Complete Tree T.C -> 
Finding Height is O(n) and then calling diameter two times i.e for LST and RST so 2T(n/2) which means now n size problem is divided into two sub problem.
T(n) = kn + 2T(n/2) = O(NLOGN)


Same process for Skew Tree T.C -> 
Finding Height is O(n) and then calling diameter but here now n size problem is not divided into two sub problem but size is decreased by 1 so T(n-1).
T(n) = kn + T(n-1) = O(N^2);

With above observation we get that T.c depends on height of TREE
N*LOGN  (HEIGHT = LOGN)
N^2 = N * N  (HEIGHT N)
SO T.C = N*HEIGHT

T.C IS HIGHER BCZ EACH NODE FOR FINDING DIAMETER CALLS HEIGHT FUNCTION 
SO REPETITIVE WORK IS DONE. TO AVOID THIS PROBLEM WE COME UP WITH SOLUTION
OF GETTING DIAMETER AND HEIGHT TOGETHER.

*/

