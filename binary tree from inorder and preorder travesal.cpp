// Construct Binary Tree from Preorder and Inorder Traversal

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

int index=0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end)
    {
        if(start>end)
            return NULL;
        
        int mid = -1;
        for(int i=start; i<=end; i++)
        {
            if(inorder[i] == preorder[index])
            {
                mid = i;
                break;
            }
        }
        
        index++;
        TreeNode* root = new TreeNode(inorder[mid]);
        
        TreeNode* left = solve(preorder, inorder, start, mid-1);
        if(left!=NULL)
            root->left = left;
        TreeNode* right = solve(preorder, inorder, mid+1, end);
        if(right!=NULL)
            root->right = right;
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // int index=0;
        return solve(preorder, inorder, 0, inorder.size()-1);
        
    }