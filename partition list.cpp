// Partion List

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

ListNode* partition(ListNode* head, int x) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* end = prev->next;
        
        while(end && end->val < x)
        {
            prev = end;
            end = end->next;
        }
        
        while(end && end->next)
        {
            ListNode* nxt = end->next;
            if(nxt->val >= x)
                end = end->next;
            else{
                end->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                prev = nxt;
            }
        }
        
        return dummy->next;
    }