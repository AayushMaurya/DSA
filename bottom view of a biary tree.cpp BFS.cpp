// bottom view of a binary tree
// queue || BFS

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

void solve(Node* root, map<int, map<int, int>>& mp, int x, int y)
  {
      if(root==NULL)
        return ;
    
    mp[x][y] = root->data;
    solve(root->left, mp, x-1, y+1);
    solve(root->right, mp, x+1, y+1);
    
    return ;
  }
  
    vector <int> bottomView(Node *root) {
        map<int, map<int, int>> mp;
        vector<int> ans;
        if(root==NULL)
            return ans;
            
        solve(root, mp, 0, 0);
            
        for(auto itr: mp)
        {
            int res;
            for(auto it: itr.second)
                res = it.second;
            ans.push_back(res);
        }
            
        return ans;
    }