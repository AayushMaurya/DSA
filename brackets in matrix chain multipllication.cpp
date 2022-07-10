// Brckets in matrix chain multiplication

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

pair<int, string> solve(int p[], int n, int low, int high, pair<int, string> dp[27][27])
    {
        if(low==high)
        {
            char ch = 'A' + low;
            string s = "";
            s += ch;
            pair<int, string> ans = {0, s};
            return ans;
        }
        
        if(dp[low][high].first!=-1)
            return dp[low][high];
            
        pair<int, string> ans;
        
        ans.first = INT_MAX;
        for(int i=low; i<high; i++)
        {
            pair<int, string> p1 = solve(p, n, low, i, dp);
            pair<int, string> p2 = solve(p, n, i+1, high, dp);
            
            int temp = p1.first + p2.first + (p[low]*p[i+1]*p[high+1]);
            if(ans.first > temp)
            {
                ans.first = temp;
                ans.second = "(" + p1.second + p2.second + ")";
            }
        }
        
        return dp[low][high] = ans;
    }

    string matrixChainOrder(int p[], int n){
        pair<int, string> dp[27][27];
        pair<int, string> empty;
        empty.first = -1;
        
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
                dp[i][j] = empty;
        }
        
        return solve(p, n, 0, n-2, dp).second;
    }