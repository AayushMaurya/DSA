// Copy list with random pointer

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

Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
       
        map<Node*, Node*> mp;
        
        Node* temp = head;
        while(temp)
        {
            Node* node = new Node(temp->val);
            node->next = NULL;
            node->random = NULL;
            mp[temp] = node;
            temp=temp->next;
        }
        
        Node* ans = new Node(0);
        Node* curr = ans;
        
        temp = head;
        
        while(temp)
        {
            curr->next = mp[temp];
            curr=curr->next;
            if(temp->next == NULL)
                curr->next = NULL;
            else
                curr->next = mp[temp->next];
            
            if(temp->random == NULL)
                curr->random = NULL;
            else
                curr->random = mp[temp->random];
            
            temp=temp->next;
        }
        return ans->next;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}