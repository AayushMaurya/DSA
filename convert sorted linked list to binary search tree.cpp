// Convert sorted linked list to binary search tree

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

TreeNode* solve(ListNode **Lnode, int n)
 {
     if(n<=0)
        return NULL;
        
    TreeNode* Left = solve(Lnode, n/2);
    
    TreeNode* root = new TreeNode((*Lnode)->val);
    root->left = Left;
    
    *Lnode = (*Lnode)->next;
    
    root->right = solve(Lnode, n - n/2 - 1);
    
    return root;
 }
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    int n = 0;

    ListNode* temp = A;
    while(temp)
    {
        n++;
        temp = temp->next;
    }
    
    return solve(&A, n);
}