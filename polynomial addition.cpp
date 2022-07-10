// Polynomial addition

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

 Node* addPolynomial(Node *p1, Node *p2)
    {
        Node* d1 = new Node(0, 0);
        d1->next = p1;
        
        Node* d2 = new Node(0, 0);
        d2->next = p2;
        
        Node *cur1 = d1->next, *cur2 = d2->next;
        Node* prev = d1;
        
        while(cur1 && cur2)
        {
            if(cur1->pow == cur2->pow){
                cur1->coeff += cur2->coeff;
                prev = cur1;
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            else if(cur1->pow > cur2->pow){
                prev = cur1;
                cur1 = cur1->next;
            }
            else{
                Node* temp = cur2->next;
                prev->next = cur2;
                cur2->next = cur1;
                cur2 = temp;
                prev=prev->next;
            }
            
        }
        
        if(cur2)
            prev->next = cur2;
            
        return d1->next;
    }