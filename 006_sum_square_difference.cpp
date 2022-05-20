#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int

void solve()
{
    ll n;
    cin>>n;
    ll sum1, sum2;
    sum1 = n*(n+1)/2;
    sum2 = n*(n+1)*(2*n + 1)/6;
    ll res = abs(sum2 - sum1*sum1);
    cout<<res<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
