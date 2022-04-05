// Move all zeros to the front of the linked list

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

ivoid moveZeroes(struct Node **head)
{
    Node *temp=*head;
    while(temp->next)
    {
        Node *t = temp->next;
        
        if(t->data == 0)
        {
            temp->next = t->next;
            t->next = *head;
            *head = t;
        }
        else
            temp=temp->next;
    }
    
}


int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<solve(arr, n)<<endl;
    return 0;
}