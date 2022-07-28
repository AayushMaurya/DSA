// Levels of game

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


int solve(int h, int m, int path, vector<vector<int>>& dp)
        {
            if(h<=0 || m<=0)
                return -1;
                
            if(dp[h][m]!=-1)
                return dp[h][m];
                
            int a=0, b=0, c=0;
            if(path!=1)
                a = solve(h+3, m+2, 1, dp) + 1;
            if(path!=2)
                b = solve(h-5, m-10, 2, dp) + 1;
            if(path!=3)
                c = solve(h-20, m+5, 3, dp) + 1;
                
            return dp[h][m] = max(a, max(b, c));
        }
    
        int maxLevel(int h,int m)
        {
            vector<vector<int>> dp(2005, vector<int>(2005, -1));
            
            return solve(h, m, -1, dp);
        }