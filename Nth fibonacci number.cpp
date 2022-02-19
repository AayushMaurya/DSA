// Nth Finonacci number
// return ans in mod 10^9+7

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

int solve()
{
    int n;
    cin>>n;

    int x=1, y=1;

    if(n==1 || n==2)
        return 1;

    int res=0;
    for(int i=3; i<=n; i++)
    {
        res = (x+y)%1000000007;
        x=y;
        y=res;
    }

    return res;
}

int main(){
    cout<<solve()<<endl;
    return 0;
}