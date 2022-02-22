// Optimal Binary Search

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

int helper(int i, int j, vector<vector<int>>& dp, int wt[], int freq[])
{
    if(i>=j)
        return 0;
    else if(j-i == 1)
        return freq[i];
    else if(dp[i][j] != INT_MAX)
        return dp[i][j];
    
    int sum = wt[j]-wt[i];
    for(int k=i; k<j; k++)
        dp[i][j] = min(dp[i][j], sum + helper(i, k, dp, wt, freq) + helper(k+1, j, dp, wt, freq));

    return dp[i][j];
}

void solve()
{
    int n;
    cin>>n;

    int key[n], freq[n];

    for(int i=0; i<n; i++)
        cin>>key[i];
    for(int i=0; i<n; i++)
        cin>>freq[i];

    vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
    int wt[n+1];
    wt[0] = 0;

    for(int i=1; i<=n; i++)
        wt[i] = wt[i-1]+freq[i-1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i>=j)
                dp[i][j] = 0;
            else if(j-i == 1)
                dp[i][j] = freq[i];
            else
            {
                int sum = wt[j]-wt[i];
                for(int k=i; k<j; k++)
                    dp[i][j] = min(dp[i][j], sum + helper(i, k, dp, wt, freq) + helper(k+1, j, dp, wt, freq));
            }
        }
    }

    cout<<dp[0][n]<<endl;

    return;
}

int main(){
    solve();
    return 0;
}