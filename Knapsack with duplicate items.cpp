// Knapsack with duplicate items

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

void solve()
{
    int n, w;
    cin>>n>>w;
    int val[n], wt[n];
    for(int i=0; i<n; i++)
        cin>>wt[i];
    for(int i=0; i<n; i++)
        cin>>val[i];

    int dp[n+1][w+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(j<wt[i-1])
                dp[i][j]=d[i-1][j];
            else{
                int temp=val[i-1] + dp[i][j-wt[i-1]];
                dp[i][j] = max(dp[i-1][j],temp);
            }
        }
    }

    cout<<dp[n][w]<<endl;

    return;
}

int main(){
    solve();
    return 0;
}