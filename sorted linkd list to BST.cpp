// sorted linked list to BST

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

//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

    TNode* solve(int s, int e, vector<int>& arr)
    {
        if(s>e)
            return NULL;
            
        int mid;
        if((s+e)%2==0)
            mid=(s+e)/2;
        else
            mid=(s+e)/2+1;
            
        TNode* node = new TNode(arr[mid]);
        
        node->left = solve(s, mid-1, arr);
        node->right = solve(mid+1, e, arr);
        
        return node;
    }
  
    TNode* sortedListToBST(LNode *head) {
        if(head==NULL)
            return NULL;
        vector<int> arr;
        LNode* temp = head;
        while(temp)
        {
            arr.push_back(temp->data);
            temp=temp->next;
        }
        
        TNode* node = solve(0, arr.size()-1, arr);
        
        return node;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}