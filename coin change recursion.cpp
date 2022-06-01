// Coin Change
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


int help(vector<int>& coins, int amount, int n,vector<vector<int>>&dp)
    {
        if(amount == 0) return 0;
        if(n < 0 || amount < 0) return INT_MAX-1;
        if(dp[n][amount]!= -1) return h[n][amount];
        int escape = help(coins,amount,n-1,h);
        int take = 1+help(coins,amount-coins[n],n,h);
        h[n][amount] = min(take,escape);
        return dp[n][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans = help(coins,amount,coins.size()-1,h);
        return (ans < INT_MAX-1)?ans:-1;
    }
int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}