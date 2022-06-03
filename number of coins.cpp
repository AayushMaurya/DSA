// Number of coins

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

int minCoins(int coins[], int M, int V) 
    { 
        vector<int> dp(V+1, INT_MAX);
        dp[0] = 0;
        
        for(int i=0; i<=V; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
        if(dp[V] == INT_MAX)
            return -1;
        return dp[V];
    } 

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}