// right view of binary tree
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

vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        map<int, int> mp;
        q.push(root);
        int level = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                mp[level] = node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
            }
            level++;
        }
        
        for(auto itr: mp)
            ans.push_back(itr.second);
        
        return ans;
    }