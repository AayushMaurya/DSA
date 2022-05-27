// Detect loop in linked list

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

bool detectLoop(Node* head)
    {
        Node* fast = head;
        Node* slow = head;
        
        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast == slow)
                return true;
        }
        return false;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}