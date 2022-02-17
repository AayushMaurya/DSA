// Corona Vaccine

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

// need vaccine = 1
// no need = -1
// taken vaccine = 0;

int ans=0;
int helper(Node* root)
{
    if(root==NULL)
        return -1;
    int left=helper(root->left);
    int right=helper(root->right);

    // if either child requires vaccine
    // then root will take it
    if(left==1 || right==1)
    {
        ans++;
        return 0;
    }

    // if either child already have vaccine
    // then root will not need it
    if(left==0 || right==0)
        return -1;

    // otherwise root will be needing tha vaccine;
    return 1;
}

int supplyVaccine(Node* root)
{
    if(helper(root) == 1)
        return ans+1;
    else
        return ans;

}

int main(){
    solve();
    return 0;
}