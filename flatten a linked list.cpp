// Flatten a linked list

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

Node* merge(Node* a, Node* b)
{
    Node* temp = new Node(0);
    Node* res = temp;
    
    while(a!=NULL && b!=NULL)
    {
        if(a->data < b->data)
        {
            temp->bottom=a;
            a=a->bottom;
            temp=temp->bottom;
        }
        else{
            temp->bottom=b;
            b=b->bottom;
            temp=temp->bottom;
        }
    }
    
    if(a)   temp->bottom=a;
    else    temp->bottom=b;
    
    return res->bottom;
}
    
Node *flatten(Node *root)
{
    if(root==NULL || root->next==NULL)
        return root;
        
    root->next = flatten(root->next);
    
    root = merge(root, root->next);
    
    return root;
    
}

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}