// Balanced binary tree

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

int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int h1 = solve(root->left);
        int h2 = solve(root->right);
        
        if(h1==-1 || h2==-1)
            return -1;
        
        if(abs(h1-h2)>1)
            return -1;
        
        return 1+max(h1, h2);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
       int h1 = solve(root->left);
        int h2 = solve(root->right);
        
        if(h1==-1 || h2==-1)
            return false;
        
        if(abs(h1-h2)>1)
            return false;
        
        return true;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}