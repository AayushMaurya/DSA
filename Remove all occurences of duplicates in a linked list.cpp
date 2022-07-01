// Remove all occurences of duplicates in a linked list

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

Node* removeAllDuplicates(struct Node* head)
    {
        struct Node* dummy = new Node(0);
        dummy->next = head;
        
        if(head == NULL || head->next == NULL)
            return head;
            
        struct Node *prev, *curr;
        
        prev = dummy;
        
        while(prev && prev->next)
        {
            curr = prev->next;
            int flag=0;
            
            while(curr->next && curr->data == curr->next->data){
                curr = curr->next;
                flag=1;
            }
            
            if(flag)
                prev->next = curr->next;
            else{
                prev->next = curr;
                prev = prev->next;
            }
        }
        
        return dummy->next;
    }