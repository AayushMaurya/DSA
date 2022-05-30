// Reverse a linked list

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

struct Node* reverseList(struct Node *head)
    {
        struct Node* temp=head;
        if(temp->next == NULL)
            return head;
            
        temp=temp->next;
        head->next=NULL;
        struct Node* temp2;
        while(temp)
        {
            temp2=temp->next;
            temp->next=head;
            head=temp;
            temp=temp2;
        }
        return head;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}