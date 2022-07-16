// BST to greater sum tree

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

int sum=0;
    void transformTree(struct Node *root)
    {
        if(root==NULL)
            return ;
        transformTree(root->right);
        sum += root->data;
        root->data = sum-root->data;
        transformTree(root->left);
        
        return ;
    }