// Burn a tree

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

TreeNode* markParent(TreeNode* root, map<TreeNode*, TreeNode*>& parent, int t)
 {
     queue<TreeNode*> q;
     TreeNode* target;
     q.push(root);
     while(!q.empty())
     {
         TreeNode* node = q.front();
         q.pop();
         if(node->val == t)
            target = node;
         if(node->right)
         {
             parent[node->right] = node;
             q.push(node->right);
         }
         if(node->left)
         {
             parent[node->left] = node;
             q.push(node->left);
         }
     }
     return target;
 }
 
int Solution::solve(TreeNode* A, int B) {
    map<TreeNode* , TreeNode*> parent;
    TreeNode* target = markParent(A, parent, B);
    map<TreeNode*, bool> vis;
    
    queue<TreeNode*> q;
    q.push(target);
    int ans=-1;
    while(!q.empty())
    {
        int n = q.size();
        ans++;
        for(int i=0; i<n; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->right && !vis[node->right])
            {
                q.push(node->right);
                vis[node->right] = true;
            }
            if(node->left && !vis[node->left])
            {
                q.push(node->left);
                vis[node->left] = true;
            }
            if(parent[node] && !vis[parent[node]])
            {
                q.push(parent[node]);
                vis[parent[node]] = true;
            }
        }
    }
    return ans;
}