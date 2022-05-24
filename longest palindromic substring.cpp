// Longest palindromic substring

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


string longestPalindrome(string s) {
    int start=0, end=0;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i=0; i<N; i++)
    {
        for(int j=i; j<n-i; j++)
        {
            int x=j, y=i+j;
            if(x==y)
                dp[x][y] = 1;
            else if(y-x==1)
            {
                if(s[x]==s[y])  dp[x][y]=1;
                else dp[x][y] = 0;
            }
            else{
                if(s[x]==s[y] && s[x+1][y-1]==1)
                    dp[x][y] = 1;
                else    dp[x][y]=0;

            }
            if(dp[x][y]==1 && y-x+1>ans)
                {
                    ans=y-x+1;
                    start=x;
                    end=y;
                }
        }
    }
    retrun s.substr(start, end-start+1);
}

int main(){
    
   int t;
   while(t--)
    solve();
return 0;
}