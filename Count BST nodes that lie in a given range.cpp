// Count BST nodes that lie in a given range

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

int getCount(Node *root, int l, int h)
    {
        stack<Node*> st;
        st.push(root);
        
        int ans=0;
        
        while(!st.empty())
        {
            Node* node = st.top();
            st.pop();
            if(node->data>=l && node->data<=h)
                ans++;
            if(node->left && node->data>=l)
                st.push(node->left);
            if(node->right && node->data<=h)
                st.push(node->right);
        }
        
        return ans;
    }