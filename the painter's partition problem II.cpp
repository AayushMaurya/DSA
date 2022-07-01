// The painter's partition problem II

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

int ans = INT_MAX;
    
    long long solve(int index, int k, int arr[], int n, vector<vector<long long>>& dp)
    {
        if(index==n)
            return 0;
        if(k==0)
            return INT_MAX;
            
        if(dp[index][k]!=-1)
            return dp[index][k];
        
        long long initial_sum=0;
        long long ans=INT_MAX;
        
        for(int i=index; i<n; i++)
        {
            initial_sum += arr[i];
            long long post_sum = solve(i+1, k-1, arr, n, dp);
            
            ans = min(ans, max(initial_sum, post_sum));
        }
        
        return dp[index][k] = ans;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        vector<vector<long long>> dp(n+1, vector<long long>(k+1, -1));
        
        long long ans = solve(0, k, arr, n, dp);
        
        if(ans == INT_MAX)
            return -1;
        return ans;
    }