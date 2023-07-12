//time for hasNext(): O(1)
//time for next(): O(n) in worst case, amortized O(1)
//space: O(h)

/*
Approach
1.push root node and all its left node till the leaf
2.pop element from the stack (it will give inorder value and value will be min)
3.if node is having right node then push all its left node.
4.if stack becomes empty then hasNext will return false.



*/




class BSTIterator {
public:
    stack<TreeNode*> stk;
    
    void push_left(TreeNode* node){
        while(node){
            stk.push(node);
            node = node->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        //Initially push root and all its left node till the leaf
        push_left(root);
    }
    
    /*
    NEXT -  gives next inorder value , return the next smallest number
    */
    int next() {
        //get the top element
        TreeNode* cur = stk.top(); 
        stk.pop();
        //visit itself
        int val = cur->val;
        //if node's right is present then push all its left node in stack
        if(cur->right){
            push_left(cur->right);
        }
        return val;
    }
    
    /*return whether we have a next smallest number */
    bool hasNext() {
       // When stack becomes empty then hasNext will return false
      // if it’s true then push all the left node till the leaf.
        return !stk.empty();
    }
};






