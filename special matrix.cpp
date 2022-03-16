// Special Martix

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
// ll max(ll x, ll y)
// {
//     return (x>y)?x:y;
// }
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

int FindWays(int n, int m, vector<vector<int>>blocked_cells){
        int mod = 1000000007;
        int dp[n][m];
        int k=blocked_cells.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                dp[i][j] = -1;
        }
        for(int i=0; i<k; i++)
        {
            int x = blocked_cells[i][0], y = blocked_cells[i][1];
            dp[x-1][y-1] = 0;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(dp[i][j] == 0)
                    continue;
                else if(i==0 && j==0)
                    dp[i][j] = 1;
               else if(i==0 && j!=0)
                    dp[i][j] = dp[i][j-1];
               else if(j==0 && i!=0)
                    dp[i][j] = dp[i-1][j];
               else
                    dp[i][j] = (dp[i][j-1]+dp[i-1][j])%mod;
                    
               //cout<<dp[i][j]<<" ";
            }
           // cout<<endl;
        }
        return dp[n-1][m-1];
    }

int main(){
    solve();
    return 0;
}