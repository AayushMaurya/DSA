// Construct binary search tree from preorder traversal

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

TreeNode* solve(int left, int right, vector<int>& nums)
    {
        if(left>right)
            return NULL;
        
        TreeNode* root = new TreeNode(nums[left]);
        int mid = left;
        
        while(mid+1<=right && nums[mid+1] < nums[left])
            mid++;
        
        root->left = solve(left+1, mid, nums);
        root->right = solve(mid+1, right, nums);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int left = 0, right = preorder.size()-1;
        return solve(left, right, preorder);
    }