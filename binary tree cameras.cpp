// Binary Tree Cameras


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


int ans;
    
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 1;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left == 0 || right == 0)
        {
            ans++;
            return 2;
        }
        
        if(left == 2 || right == 2)
            return 1;
        
        return 0;
        
    }
    
    int minCameraCover(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left==0 || right==0)
            ans++;
        else if(left==1 && right==1)
            ans++;
        
        return ans;
    }
