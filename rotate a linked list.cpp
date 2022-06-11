// Rotate a linked list

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

Node* rotate(Node* head, int k)
    {
        if(head==NULL || k==0)
            return head;
        Node* end=head;
        while(end->next!=NULL)
            end=end->next;
        
        Node* H = new Node(0);
        H->next = head;
        Node* temp = H;
        while(k--)
            temp=temp->next;
        
        // cout<<temp->data<<endl;
        
        
        end->next = H->next;
        H->next = temp->next;
        temp->next = NULL;
        
        return H->next;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}