// Largest BST

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

int ans=0;
    
    vector<int> solve(Node* root)
    {
        if(root == NULL){
            vector<int> res;
            res.push_back(INT_MAX);
            res.push_back(INT_MIN);
            res.push_back(0);
            res.push_back(1);
            
            return res;
        }
        
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        int height;
        int flag=0;
        if(left[3]==1 && right[3]==1)
            flag = 1;
        if(root->data > left[1] && root->data < right[0] && flag==1){
            height = 1 + (left[2]+right[2]);
            ans = max(ans, height);
        }
        else{
            height = 1;
            flag=0;
        }
        
        int ma = root->data;
        int mi = root->data;
        
        ma = max(ma, max(left[1], right[1]));
        mi = min(mi, min(left[0], right[0]));
        
        vector<int> res;
        res.push_back(mi);
        res.push_back(ma);
        res.push_back(height);
        res.push_back(flag);
        
        return res;
    }
    
    int largestBst(Node *root)
    {
        solve(root);
        return ans;
    }