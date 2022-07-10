// all nodes distance k in a binary tree

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

void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, TreeNode* target)
   {
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty())
       {
           TreeNode* node = q.front();
           q.pop();
           if(node->left)
           {
               parent[node->left] = node;
               q.push(node->left);
           }
           if(node->right)
           {
               parent[node->right] = node;
               q.push(node->right);
           }
       }
       return ;
   }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, bool> visited;
        unordered_map<TreeNode*, TreeNode*> parent;
        
        markParent(root, parent, target);
        
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int level = 0;
        while(!q.empty())
        {
            int n = q.size();
            if(level++ == k)    break;
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent[node] && !visited[parent[node]])
                {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        
        return ans;
    }