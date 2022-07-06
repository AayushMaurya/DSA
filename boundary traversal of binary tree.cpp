// boundary traversal of binary tree
// anti clock wise direction

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

bool isleaf(Node* root)
    {
        if(root->left == NULL && root->right==NULL)
            return true;
        return false;
    }
    
    void addleft(Node* root, vector<int>& ans)
    {
        Node* cur = root->left;
        while(cur)
        {
            if(!isleaf(cur))   ans.push_back(cur->data);
            if(cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return ;
    }

    void addright(Node* root, vector<int>& ans)
    {
        Node* cur = root->right;
        vector<int> temp;
        while(cur)
        {
            if(!isleaf(cur))
                temp.push_back(cur->data);
            if(cur->right)
                cur=cur->right;
            else 
                cur = cur->left;
        }
        for(int i=temp.size()-1; i>=0; i--)
            ans.push_back(temp[i]);
        return ;
    }

    void addleaf(Node* root, vector<int>& ans)
    {
        if(isleaf(root))
            ans.push_back(root->data);
        if(root->left)  addleaf(root->left, ans);
        if(root->right) addleaf(root->right, ans);
    }

    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        
        if(root==NULL)
            return ans;
        if(!isleaf(root))
            ans.push_back(root->data);
        
        addleft(root, ans);
        addleaf(root, ans);
        addright(root, ans);
        
        return ans;
    }