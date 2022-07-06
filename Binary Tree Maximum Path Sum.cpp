// Binary Tree Maximum Path Sum

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

int ans = INT_MIN;
    
    int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int left = max(solve(root->left), 0);
        int right = max(solve(root->right), 0);
        
        int sum = root->val + left + right;

        ans = max(ans, sum);
        
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
     int x = solve(root);
        
        return ans;
    }