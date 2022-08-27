// Inorder traversal using stack

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
        
        if(root==NULL)
            return {};
        
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* current;
        
        vector<int> ans;
        
        while(!st.empty())
        {
            current = st.top();
            if(current->left)
            {
                st.push(current->left);
                current->left = NULL;
            }
            else{
                ans.push_back(current->val);
                st.pop();
                if(current->right){
                    st.push(current->right);
                    current->right = NULL;
                }
            }
        }
        return ans;
    }