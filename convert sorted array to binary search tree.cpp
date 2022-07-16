// Convert sorted array to binary search tree

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

TreeNode* solve(int start, int end, vector<int>& nums)
    {
        if(start>end)
            return NULL;
        
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = solve(start, mid-1, nums);
        root->right = solve(mid+1, end, nums);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        TreeNode* root = new TreeNode();
        root = solve(0, nums.size()-1, nums);
        return root;
    }