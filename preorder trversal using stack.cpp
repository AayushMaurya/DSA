// preorder traversal using stack

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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;

    if(root==NULL)
        return ans;

    TreeNode* node;
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty())
    {
        node = st.top();
        st.pop();
        ans.push_back(node->val);
        if(node->right)
            st.push(node->right);
        if(node->left)
            st.push(node->left);
    }

    return ans;
}