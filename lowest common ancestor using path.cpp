// Lowest common accestor usgin path

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

bool findPath(TreeNode* root, vector<int>& path, int k)
{
    if(root==NULL)
        return false;
        
    path.push_back(root->val);
    
    if(root->val == k)
        return true;
        
    if((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k)))
        return true;
    
    path.pop_back();
    
    return false;
}

int lowestCommonAncestor(TreeNode* root, int a, int b)
{
    vector<int> path1, path2;
    
    if(!findPath(A, path1, B) || !findPath(A, path2, C))
        return -1;
        
    int i;
    for(i=0; i<path1.size() && i<path2.size(); i++)
    {
        if(path1[i] != path2[i])
            break;
    }
    
    return path1[i-1];
}