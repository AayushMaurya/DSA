// Maximum path sum from any node

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
        
        int temp = max(root->data, root->data + max(left, right));
        
        ans = max(temp, ans);
        ans = max(ans, root->data+left+right);
        
        return temp;
    }
    
    int findMaxSum(Node* root)
    {
        int temp = solve(root);
        
        return ans;
    }