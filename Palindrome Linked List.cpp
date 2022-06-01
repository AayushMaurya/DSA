// Palindrome Linked List

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

bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* dummyhead=new ListNode(0);
        dummyhead->next=slow;
        
        ListNode* prev=dummyhead;
        ListNode* curr;
        ListNode* nex;
        
        curr=prev->next;
        nex=curr->next;  
        while(nex)
        {
            curr->next=nex->next;
            nex->next=prev->next;
            prev->next=nex;
            nex=curr->next;
        }
        dummyhead=dummyhead->next;
        while(head != NULL && dummyhead!=NULL)
        {
            if(head->val!=dummyhead->val)
                return false;
            head=head->next;
            dummyhead=dummyhead->next;
        }
        return true;
        
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}