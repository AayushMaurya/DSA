// Count possible ways to construct buildings

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

int TotalWays(int N)
    {
        long long t=1;
        long long e=1;
        int mod = 1000000007;
        
        for(int i=1; i<N; i++)
        {
            long long temp = e;
            e = (t+e)%mod;
            t = temp%mod;
        }
        
        long long ans = (t+e)*(t+e)%mod;
        
        return (int)ans;
    }