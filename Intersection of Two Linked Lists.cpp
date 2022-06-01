// Intersection of Two Linked Lists

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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1=headA;
        ListNode* l2=headB;
        int flag=3;
        while(l1!=l2 && flag>0)
        {
            l1=l1->next;
            if(l1==NULL){
                l1=headB;
                flag--;
            }
            
            l2=l2->next;
            if(l2==NULL){
                l2=headA;
                flag--;
            }
            
            // if(l1==headA || l2==headB)   return 0;
        }
        if(flag<=0)
            return 0;
        return l1;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}