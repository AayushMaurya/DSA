// Maximum width of a binary tree

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

int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});
        long long ans=0;
        while(!q.empty())
        {
            int n = q.size();
            int val = q.front().second;
            long long first, last;
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front().first;
                long long curr_id = q.front().second-val;
                q.pop();
                if(i==0)
                    first = curr_id;
                if(i==n-1)
                    last = curr_id;
                if(node->left)
                    q.push({node->left, curr_id*2+1});
                if(node->right)
                    q.push({node->right, curr_id*2+2});
            }
            ans = max(ans, last-first+1);
        }
        return (int)ans;
    }