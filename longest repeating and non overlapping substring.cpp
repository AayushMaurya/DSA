// longest repeating and non-overlapping substring

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

string longestSubstring(string S, int n) {
        int dp[n+1][n+1];
        
        int ans=0;
        int x=0, y=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(S[i-1] == S[j-1] && dp[i-1][j-1] < j-i){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(ans < dp[i][j])
                    {
                        ans = max(ans, dp[i][j]);
                        x=i;
                        y=j;
                    }
                }
                else dp[i][j] = 0;
            }
        }
        
        if(x==0)
            return "-1";
        string res="";
        while(dp[x][y]!=0)
        {
            res += S[x-1];
            x--;
            y--;
        }
        reverse(res.begin(), res.end());
       
        return res;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}