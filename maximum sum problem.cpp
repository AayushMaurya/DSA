// Maximum Sum Problem

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

void solve()
{
    int n;
    cin>>n;

    int dp[n+1];
    if(n<=10)
        return n;
        
    for(int i=0; i<=10; i++)
        dp[i] = i;
        
    for(int i=11; i<=n; i++)
    {
        int a=i/2, b=i/3, c=i/4;
        dp[i] = max(i, dp[a] + dp[b] + dp[c]);
    }
    cout<<dp[n]<<endl;

    return;
}

int main(){
    solve();
    return 0;
}