// count nodes equal to averge of subtree 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
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

int ans = 0;
    
    pair<int, int> solve(TreeNode* root)
    {
        if(root == NULL)
        {
            return {0, 0};
        }
        
        pair<int, int> left = solve(root->left);
        
        pair<int, int> right = solve(root->right);
        
        int avg = (double)(left.first + right.first + root->val)/(left.second + right.second + 1);
        if(avg == root->val)
            ans++;
        
        return {left.first + right.first + root->val, left.second + right.second + 1};
    }
    
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        pair<int, int> left = solve(root->left);
        
        pair<int, int> right = solve(root->right);
        
        int avg = (left.first + right.first + root->val)/(left.second + right.second + 1);
        if(avg == root->val)
            ans++;
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}