// check if two trees are same

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

bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL || q==NULL)
            return p==q;
        
        if(p->val!=q->val)
            return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }