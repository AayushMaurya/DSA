// Rod cutting problem
// Dynamic programming

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

int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else{
                    if(j-i>=0)
                        dp[i][j] = max(price[i-1] + dp[i][j-i], dp[i-1][j]);
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][n];
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}