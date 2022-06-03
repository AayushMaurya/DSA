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

 ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp = head;
        int length=0;
        while(temp->next){
            temp=temp->next;
            length++;
        }
        length++;
        // cout<<"length = "<<length<<endl;
        temp->next=head;
        temp=temp->next;
        head=temp->next;
        
        int count = length - k%length;
        // cout<<"count = "<<count<<endl;
        for(int i=1; i<count; i++){
            temp=temp->next;
            head=head->next;
        }
        temp->next = NULL;
        
        return head;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}