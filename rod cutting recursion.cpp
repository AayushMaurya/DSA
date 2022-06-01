// Rod cutting problem
// Recursion

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

int helper(int price[], int n, vector<int>& dp)
    {
        if(n==1)
            return price[0];
        if(dp[n]!=-1)
            return dp[n];
            
        int ans=price[n-1];
        
        for(int i=1; i<n; i++)
            ans = max(helper(price, i, dp) + helper(price, n-i, dp), ans);
         dp[n] = ans;
         return dp[n];
    }
  
    int cutRod(int price[], int n) {
        vector<int> dp(n+1, -1);
        return helper(price, n, dp);
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}