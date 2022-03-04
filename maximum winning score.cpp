// Maximum winning score

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
// ll max(ll x, ll y)
// {
//     return (x>y)?x:y;
// }
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

long long findMaxScore(Node* root)
    {
        if(root==NULL)
            return 1;
        
        long long right = findMaxScore(root->right);
        long long left = findMaxScore(root->left);
        
        return root->data*1LL*max(right, left);
    }
int main(){
    solve();
    return 0;
}