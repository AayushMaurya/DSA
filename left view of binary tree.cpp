// left view of binary tree

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

vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
        
    map<int, int> mp;
    queue<Node*> q;
    int level = 0;
    q.push(root);
    
    while(!q.empty())
    {
        int n = q.size();
        for(int i=0; i<n; i++)
        {
            Node* node = q.front();
            q.pop();
            
            mp[level] = node->data;
            
            if(node->right)
                q.push(node->right);
                
            if(node->left)
                q.push(node->left);
        }
        level++;
    }
    
    for(auto itr: mp)
        ans.push_back(itr.second);
        
    return ans;
}