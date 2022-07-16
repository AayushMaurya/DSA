// validate binary search tree

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

void dfs(TreeNode* root, vector<int>& res)
    {
        if(root==NULL)
            return ;
        if(root->left)
            dfs(root->left, res);
        res.push_back(root->val);
        if(root->right)
            dfs(root->right, res);
        
        return ;
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        
        dfs(root, res);
        
        for(int i=1; i<res.size(); i++)
        {
            if(res[i] <= res[i-1])
                return false;
        }
        
        return true;
    }