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

vector<int> topView(Node *root)
    {
        queue<pair<Node*, int>> q;
        vector<int> ans;
        if(root==NULL)
            return ans;
        
        map<int, int> mp;
        
        q.push({root, 0});
        
        while(!q.empty())
        {
            Node* node = q.front().first;
            int line = q.front().second;
            q.pop();
            
            if(mp.find(line)==mp.end())
                mp[line] = node->data;
            
            if(node->left)
                q.push({node->left, line-1});
            if(node->right)
                q.push({node->right, line+1});
        }
        
        for(auto itr: mp)
            ans.push_back(itr.second);
            
        return ans;
    }