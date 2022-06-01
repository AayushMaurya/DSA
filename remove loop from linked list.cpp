// remove loop from linked list

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

void removeLoop(Node* head)
    {
        if(head==NULL || head->next==NULL)
            return ;
        
        Node* slow=head;
        Node* fast=head;
        
        slow=slow->next;
        fast=fast->next->next;
        
        while(slow && fast && fast->next && slow!=fast)
        {
            slow=slow->next;
                
            fast=fast->next->next;
        }
        if(fast==NULL || fast->next==NULL)
            return;
        
        fast=head;
        
        if(fast==slow)
        {
            while(slow->next!=fast)
                slow=slow->next;
        }
        else
        {
            while(slow->next!=fast->next)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
        }
        slow->next=NULL;
        
        return;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}