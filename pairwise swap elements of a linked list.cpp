// Pairwise swap elements of linked list

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

Node* pairWiseSwap(struct Node* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
            
        struct Node* temp = head->next;
        struct Node* node = pairWiseSwap(head->next->next);
        
        head->next->next = head;
        head->next = node;
        
        return temp;
    }