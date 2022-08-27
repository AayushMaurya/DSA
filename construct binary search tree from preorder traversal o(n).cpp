// Construct Binary search tree using preorder traversal
//  O(n) by placing every element at its correct position while
// iterating over the pre-order array

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

int index = 0;
TreeNode* pre_order(vector<int>& pre, int parent = INT_MAX)
{
    if(index == pre.size() || pre[index] > parent)
        return NULL;

    TreeNode* root = new TreeNode(pre[index++]);

    root->left = pre_order(pre, root->val);
    root->right = pre_order(pre, parent);

    return root;
}