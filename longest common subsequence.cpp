// Longet common subsequence

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
    string S1, S2;
    cin>>S1>>S2;

    int a=S1.length();
    int b=S2.length();

    int dp[a+1][b+1];

    for(int i=0; i<=a; i++)
    {
        for(int j=0; j<=b; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(S1[i-1] == S2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-i], dp[i-1][j]);
        }
    }

    cout<<dp[a][b]<<endl;

    return;
}

int main(){
    solve();
    return 0;
}