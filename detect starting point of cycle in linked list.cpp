// detect starting point of cycle in linked list

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

ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        slow=slow->next;
        fast=fast->next->next;
        while(slow && fast && fast->next && slow!=fast)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast==NULL || fast->next==NULL)
            return NULL;
        fast=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}