// Ceil in BST

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

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    int ans;
    if(input  == root->data)
        return input;
    if(input < root->data)
    {
        ans = findCeil(root->left, input);
        if(ans == -1)
            return root->data;
    }
    
    if(input > root->data)
    {
        ans = findCeil(root->right, input);
    }
    
    return ans;
    
    
    // Your code here
}