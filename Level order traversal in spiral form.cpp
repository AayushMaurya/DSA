// Level order traversal in spiral form

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

vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    stack<Node*> ltr;
    stack<Node*> rtl;
    rtl.push(root);
    while(!ltr.empty() || !rtl.empty())
    {
        while(!rtl.empty())
        {
            Node *temp = rtl.top();
            rtl.pop();
            ans.push_back(temp->data);
            if(temp->right)
                ltr.push(temp->right);
            if(temp->left)
                ltr.push(temp->left);
        }
        while(!ltr.empty())
        {
            Node *temp = ltr.top();
            ltr.pop();
            ans.push_back(temp->data);
            if(temp->left)
                rtl.push(temp->left);
            if(temp->right)
                rtl.push(temp->right);
        }
    }
    return ans;
}


int main(){
    
solve();
    return 0;
}