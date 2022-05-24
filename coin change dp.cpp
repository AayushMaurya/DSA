// Coin change 
// Dynamic programming using tabulaion 

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


int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=amount; j++)
            {
                if(j==0)
                    dp[i][j] = 0;
                else if(i==0)
                    dp[i][j] = INT_MAX-1;
                else{
                    if(j-coins[i-1]>=0)
                        dp[i][j] = min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
                    else dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][amount] == INT_MAX-1)    return -1;
        return dp[n][amount];
    }
int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}