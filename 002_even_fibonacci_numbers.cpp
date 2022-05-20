#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n;
    cin>>n;
    ll t1 = 1, t2 = 2, t3 = t1+t2, sum = 2;
    while(t3<=n)
    {
        if(t3%2 == 0)
            sum += t3;
        t1 = t2;
        t2 = t3;
        t3 = t1+t2;
    }
    
    cout<<sum<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
