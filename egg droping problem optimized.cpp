// Egg dropping problem
// Using Binary search

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

int egg(int n, int f, vector<vector<int>>& dp)
{
    if(n==1)
        return f;
    if(f<=1)
        return f;
        
    if(dp[n][f]!=-1)
        return dp[n][f];
        
    int ans = f;
    int low = 1, high = f;
    while(low<=high)
    {
        int i = (low+high)/2;
        int brk, saf;
        
        if(dp[n-1][f-i]!=-1)
            brk = dp[n-1][f-i];
        else {
            brk = egg(n-1, f-i, dp);
            dp[n-1][f-i] = brk;
        }
            
        if(dp[n][i-1]!=-1)
            saf = dp[n][i-1];
        else{
            saf = egg(n, i-1, dp);
            dp[n][i-1] = saf;
        }    
        int temp;
        if(brk > saf){
            low = i+1;
            temp = brk;
        }
        else{
            high = i-1;
            temp = saf;
        }
        
        if(temp<ans)
            ans = temp+1;
    }
    
    return dp[n][f] = ans;
}

int solve(int n, int f) {
    vector<vector<int>> dp(n+1, vector<int>(f+1, -1));
    
    return egg(n, f, dp);
}