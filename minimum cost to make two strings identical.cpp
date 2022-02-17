// Minimum cost to make two strings identica

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
    int costX, costY;
    cin>>costX>>costY;
    string str1, str2;
    cin>>str1>>str2;

    int a=str1.length();
    int b=str2.length();

    int dp[a+1][b+1];

    for(int i=0; i<=a; i++)
    {
        for(int j=0; j<=b; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int res = costX*(a-dp[a][b]) + costY*(b-dp[a][b]);
    cout<<res<<endl;

    return;
}

int main(){
    solve();
    return 0;
}