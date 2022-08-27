// Populating next right pointer in each node

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

void solve(Node* root)
    {
        if(root==NULL || root->left==NULL)
            return ;
        
        Node* right = root->right;
        Node* left = root->left;
        
        left->next = right;
        
        if(root->next)
            right->next = root->next->left;
        else
            right->next = NULL;
        solve(root->left);
        solve(root->right);
    }
    
    Node* connect(Node* root) {
        if(root)
            root->next = NULL;
        solve(root);
        return root;
    }