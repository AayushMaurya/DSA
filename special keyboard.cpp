// Special keyboard

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

long long int optimalKeys(int N){
        // code here
        vector<long long int> dp(N+1, 0);
        
        for(int i=1; i<=N; i++)
            dp[i] = i;
            
        for(int i=7; i<=N; i++)
        {
            long long int ans=0;
            for(int j=1; j<=i-3; j++)
                    ans = max(ans, dp[j]*(i-j-1));
            dp[i] = ans;
        }
        
        return dp[N];
    }