// Nodes in a complete binary tree

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define pii pair<int, int>
ll max(ll x, ll y)
{
    return (x>y)?x:y;
}
ll min(ll x, ll y)
{
    return (x>y)?y:x;
}
void swap(ll *x, ll *y)
{
    ll temp = *x;
    *x = *y;
    *y = temp;
}

int leftHeight(TreeNode* root)
    {
        int height=0;
        while(root)
        {
            height++;
            root = root->left;
        }
        return height;
    }
    
    int rightHeight(TreeNode* root)
    {
        int height=0;
        while(root)
        {
            height++;
            root = root->right;
        }
        
        return height;
    }
    
    int countNodes(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        
        if(lh == rh)
            return (1<<lh)-1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }