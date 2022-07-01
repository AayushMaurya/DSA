// Edit distance

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

int solve(int n, int m, string s, string t, vector<vector<int>>& dp)
    {
        if(n==0 || m==0)
            return max(n, m);
            
        if(dp[n][m]!=-1)
            return dp[n][m];
            
        if(s[n-1] == t[m-1])
            return solve(n-1, m-1, s, t, dp);

        int replace = (dp[n-1][m-1]==-1) ? solve(n-1, m-1, s, t, dp) : dp[n-1][m-1];
        int rem = (dp[n-1][m]==-1) ? solve(n-1, m, s, t, dp) : dp[n-1][m];
        int add = (dp[n][m-1]==-1) ? solve(n, m-1, s, t, dp) : dp[n][m-1];
            
        dp[n][m] = 1+min(replace, min(rem, add));
        
        return dp[n][m];
    }
  
    int editDistance(string s, string t) {
        
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return solve(n, m, s, t, dp);
    }