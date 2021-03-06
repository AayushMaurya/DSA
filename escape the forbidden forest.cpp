// Escape the forbidden forest

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

void solve()
{
    string str1, str2;
    cin>>str1>>str2;

    int n=str1.length(), m=str2.length();

    int dp[n+1][m+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout<<dp[n][m]<<endl;

    return;
}

int main(){
    solve();
    return 0;
}