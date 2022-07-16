// ones and zeros 
// using tabulation

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

int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(auto itr: strs)
        {
            int ones=0;
            int zeros=0;
            
            for(auto ch: itr)
            {
                if(ch=='0')
                    zeros++;
                else
                    ones++;
            }
            
            for(int i=m; i>=zeros; i--)
            {
                for(int j=n; j>=ones; j--)
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zeros][j-ones]);
            }
        }
        
        return dp[m][n];
    }