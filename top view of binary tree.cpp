// Top View of binary tree 

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

void solve(Node* root, map<int, map<int, vector<int>>>& mp, int x, int y)
    {
        if(root==NULL)
            return;
            
        mp[x][y].push_back(root->data);
        solve(root->left, mp, x-1, y+1);
        solve(root->right, mp, x+1, y+1);
        
        return;
    }
    
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, map<int, vector<int>>> mp;
        vector<int> ans;
        
        if(root == NULL)
            return ans;
            
        solve(root, mp, 0, 0);
        
        for(auto itr: mp)
        {
            for(auto m: itr.second)
            {
                ans.push_back(m.second[0]);
                break;
            }
        }
        
        return ans;
    }