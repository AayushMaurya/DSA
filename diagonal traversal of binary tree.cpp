// diagonal traversal of binary tree

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

vector<int> diagonal(Node *root)
{
   vector<int> ans;
   if(root==NULL)
        return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        while(node)
        {
            if(node->left)  
                q.push(node->left);
            ans.push_back(node->data);
            node = node->right;
        }
    }
    
    return ans;
}