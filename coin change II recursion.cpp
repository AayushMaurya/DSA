// Coin Change II
// recursion + memoization

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

int solve(vector<int> &coins, int index, int amount, vector<vector<int>> &dp){
        if(index==0){
            return amount%coins[index] == 0;
        }
        
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        
        int take = 0;
        if(amount>=coins[index]){
            take =  solve(coins, index, amount-coins[index], dp); 
        }
        int escape = solve(coins, index-1, amount, dp);
        
        
        return dp[index][amount] = take + escape;
        
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return solve(coins, n-1, amount, dp);
    }


int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}