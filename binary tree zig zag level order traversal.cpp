// Binary tree zig zag level order traversal

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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        int flag=1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> res;
            
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                res.push_back(node->val);
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(flag==0)
                reverse(res.begin(), res.end());
            flag = 1-flag;
            
            ans.push_back(res);
        }
        return ans;
    }