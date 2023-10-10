class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int check(Node *node)
    {
        if(node == NULL)
            return 0;
        int left = check(node->left);
        if(left == -1)
            return -1;
        int right = check(node->right);
        if(right == -1)
            return -1;
        
        if(left - right >= 2 || right-left >= 2)
            return -1;
        
        return 1 + max(left, right);
    }
    bool isBalanced(Node *root)
    {
        if(check(root) == -1)
            return false;
        return true;
    }
};
