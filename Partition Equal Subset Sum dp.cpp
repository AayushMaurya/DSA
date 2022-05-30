// Partition Equal Subset Sum
// Using DP

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

 int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0; i<N; i++)
            sum+=arr[i];
        if(sum%2==1)    return 0;
        sum=sum/2;
        bool dp[N+1][sum+1];
        
        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(j==0)
                    dp[i][j] = true;
                else if(i==0)
                    dp[i][j] = false;
                else{
                    if(arr[i-1]<=j)
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][sum] == true ? 1 : 0;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}