// Nth node from las

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

int getNthFromLast(struct Node *head, int n)
{
    struct Node *temp = head;
    int count=0;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    if(count<n)
        return -1;
    
    n=count-n+1;
    
    temp=head;
    while(--n)
        temp=temp->next;
    return temp->data;
}

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}