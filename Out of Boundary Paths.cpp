// Out of Boundary Paths

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

long long int solve(int m, int n, int move, int x, int y, vector<vector<vector<int>>>& dp)
    {
        if(x>=m || y>=n || x<0 || y<0)
            return 1;
        if(move == 0)
            return 0;
        
        if(dp[x][y][move]!=-1)
            return dp[x][y][move];
        
        long long int ans = 0;
        ans += solve(m, n, move-1, x+1, y, dp)%1000000007;
        ans += solve(m, n, move-1, x, y+1, dp)%1000000007;
        ans += solve(m, n, move-1, x-1, y, dp)%1000000007;
        ans += solve(m, n, move-1, x, y-1, dp)%1000000007;
        
        return dp[x][y][move] = ans%1000000007;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        
        long long int ans = solve(m, n, maxMove, startRow, startColumn, dp);
        
        return ans%1000000007;
    }