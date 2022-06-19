// Matrix chain multiplication

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

int solve(int arr[], int i, int j, vector<vector<int>>& dp)
    {
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = INT_MAX;
            
        for(int k=i; k<j; k++)
        {
            int left = solve(arr, i, k, dp);
            int right = solve(arr, k+1, j, dp);
            
            ans = min(ans, left+right+(arr[i-1]*arr[k]*arr[j]));
        }
        return dp[i][j] = ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return solve(arr, 1, N-1, dp);
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}