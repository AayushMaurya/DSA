// Number of Ways

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define pii pair<int, int>
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

long long int solve(int n, vector<long long int>& dp)
    {
        if(n<4)
            return 1;
            
        if(dp[n]!=-1)
            return dp[n];
            
        return dp[n] = solve(n-4, dp) + solve(n-1, dp);
    }

    long long int arrangeTiles(int N){
        
        vector<long long int> dp(N+1, -1);
        
        return solve(N, dp);
        
    }