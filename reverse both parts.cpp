// Reverse both parts

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

Node *reverse(Node *head, int k)
    {
        Node* dummyHead = new Node(0);
        dummyHead->next = head;
        
        Node* end1 = NULL;
        Node* end2 = NULL;
        
        for(int i=0;i<k;i++)
        {
            Node* cur = dummyHead->next;
            Node* nex = cur->next;
            
            cur->next = end1;
            dummyHead->next = nex;
            end1 = cur;
        }
        
        Node* cur = dummyHead->next;
        
        while(cur)
        {
            dummyHead->next = cur->next;
            cur->next = end2;
            end2 = cur;
            
            cur = dummyHead->next;
        }
        
        dummyHead->next = end1;
        
        if(end1==NULL)
            dummyHead->next = end2;
        else
            {
                while(end1->next)
                {
                    end1=end1->next;
                }
                end1->next = end2;
            }
        return dummyHead->next;
    }