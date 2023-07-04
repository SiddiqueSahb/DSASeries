#include <iostream>
#include "BinaryTreeNode.h"
#include "BinarySearchTree.h"
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
	public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		delete left;
		delete right;
	}
};

/*

1. if root is null return null
2. if data that we want is equal to root then create a vector and push data in that vector and return vector
3. if data that we want is not equal to root and root is not null then check in LST
4.if lST doesnt return NULL then add that node to the vector and return vector , if LST return NULL then check RST.
5.if RST doesnt return NULL then add that node to the vector and return vector, if RST return NULL then return NULL




  */

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data) {
	if (root == NULL) {
		return NULL;
	}
	
	if (root->data == data) {
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	
	vector<int>* leftOutput = getRootToNodePath(root->left, data);
	if (leftOutput != NULL) {
		leftOutput->push_back(root->data);
		return leftOutput;
	}

	vector<int>* rightOutput = getRootToNodePath(root->right, data);
	if (rightOutput != NULL) {
			rightOutput->push_back(root->data);
			return rightOutput;
	} else {
		return NULL;
	}

}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << isBST(root) << endl;
    delete root;
}

