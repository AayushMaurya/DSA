// Convert sorted arry to binary search tree

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

TreeNode* solve(vector<int>& nums, int left, int right)
    {
        if(left>right)
            return NULL;
        
        int mid = (left+right)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = solve(nums, left, mid-1);
        root->right = solve(nums, mid+1, right);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        
        return solve(nums, left, right);
    }