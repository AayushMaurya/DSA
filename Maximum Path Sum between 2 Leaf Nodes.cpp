// Maximum Path Sum between 2 Leaf Nodes

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

int ans=INT_MIN;
    
    int solve(Node* root)
    {
        if(root == NULL)
            return 0;
            
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(!root->left)
            return right + root->data;
            
        if(!root->right)
            return left + root->data;
            
        ans = max(ans, root->data + left + right);    
            
        return root->data + max(left, right);
    }
    
    int maxPathSum(Node* root)
    {
        
        if(!root->left)
            root->left = new Node(0);
        
        if(!root->right)
            root->right = new Node(0);
            
        solve(root);
        
        return ans;
    }