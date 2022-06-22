// Diameter of binary tree

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
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

int ans=0;
    
    int solve(Node* root)
    {
        if(root==NULL)
            return 0;
            
        int left = solve(root->left);
        int right = solve(root->right);
        
        ans = max(ans, 1+left+right);
        
        return 1+max(left, right);
    }
    
    int diameter(Node* root) {
        
        int temp = solve(root);
        
        return ans;
    }