// Egg Dropping problem

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

int solve(int n, int f, vector<vector<int>>& dp)
    {
        if(n==1)
            return f;
            
        if(f==0)
            return 0;
        
        if(dp[n][f]!=-1)
            return dp[n][f];
        
        int ans = f;
        
        for(int i=1; i<=f; i++)
        {
            ans = min(ans, max(solve(n-1, f-i, dp), solve(n, i-1, dp)));
        }
        
        return dp[n][f] = 1+ans;
    }
    
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        
        return solve(n, k, dp);
    }