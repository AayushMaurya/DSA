// Flatten binary tree to linked list

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

void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        
        flatten(root->left);
        flatten(root->right);
        
        if(root->left)
        {
            TreeNode* right = root->right;
            
            root->right = root->left;
            root->left = NULL;
            
            while(root->right)
                root = root->right;
            root->right = right;
        }
        
    }