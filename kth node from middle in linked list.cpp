// Kth node from middle in linked list
// towards beginning

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

int Solution::solve(ListNode* head, int k) {
    int cnt=0;
    ListNode* fast = head;
    ListNode* slow = head;
    
    while(fast && fast->next)
    {
        if(k==0)
            break;
        fast = fast->next->next;
        k--;
    }
    
    if((!fast || !fast->next) && k>0)
        return -1;
        
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow->val;
    
}