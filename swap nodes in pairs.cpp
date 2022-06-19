// Swap Nodes In Pairs

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

ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL || head->next == NULL)
            return head;
        
        ListNode* temp = new ListNode(0);
        temp->next = swapPairs(head->next->next);
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        head->next->next = head;
        dummy->next = head->next;
        head->next = temp->next;
        
        return dummy->next;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}