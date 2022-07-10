// Root to leaf paths

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

bool isleaf(Node* root)
 {
     if(root->left == NULL && root->right == NULL)
        return true;
    return false;
 }
 
 void solve(Node* root, vector<int>& res, vector<vector<int>>& ans)
 {
     if(isleaf(root))
    {
        res.push_back(root->data);
        ans.push_back(res);
        res.pop_back();
        return;
    }
    
    res.push_back(root->data);
    
    if(root->left)  solve(root->left, res, ans);
    if(root->right)  solve(root->right, res, ans);
    
    res.pop_back();
    
    return;
 }
 
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;
    
    vector<int> res;
    
    solve(root, res, ans);
    
    return ans;
}