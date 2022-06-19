// Linked list in binary tree
// https://leetcode.com/problems/linked-list-in-binary-tree/

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

bool check(ListNode* head, TreeNode* root)
    {
        if(head==NULL)
            return true;
        if(root == NULL)
            return false;
        
        if(root->val != head->val)
            return false;
        
        return check(head->next, root->left) || check(head->next, root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(head==NULL)
            return true;
        if(root==NULL)
            return false;
        
        if(root->val == head->val)
        {
            if(check(head->next, root->left) || check(head->next, root->right))
                return true;
        }
        
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}