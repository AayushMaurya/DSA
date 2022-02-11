// Prime numbers in given range

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

bool isPrime(int x)
{
    for(int i=2; i<=sqrt(x); i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

void solve()
{
    int m, n;
    cin>>m>>n;

    std::vector<int> res;
    for(int i=m; i<=n; i++)
    {
        if(i==1)    continue;

        if(isPrime(i))
            res.pb(i);
    }

    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;

    return;
}

int main(){
    solve();
    return 0;
}