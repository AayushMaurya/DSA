// Vertical Order Traversal of a Binary Tree

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

void solve(TreeNode* root, map<int, map<int, vector<int>>>& mp, int x, int y)
    {
        if(root==NULL)
            return;
        mp[x][y].push_back(root->val);
        solve(root->left, mp, x-1, y+1);
        solve(root->right, mp, x+1, y+1);
        
        return;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        vector<vector<int>> ans;
        
        if(root==NULL)
            return ans;
        
        solve(root, mp, 0, 0);
        
        for(auto itr: mp)
        {
            vector<int> res;
            for(auto m: itr.second)
            {
                sort(m.second.begin(), m.second.end());
                res.insert(res.end(), m.second.begin(), m.second.end());
            }
            ans.push_back(res);
        }
        
        return ans;
    }