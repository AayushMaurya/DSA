// Target sum 
// Dynamic programming

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

int findTargetSumWays(vector<int>& arr, int target) {
        int s1=0;
        for(int i=0; i<arr.size(); i++)
            s1+=arr[i];
        
        int sum = (s1+target)/2;
        
        if(sum<0 || (s1+target)%2!=0){
            return 0;
        }
        
        int n=arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = 1;
                else if(i==0)
                    dp[i][j] = 0;
                // else if(j==0 && arr[i-1]!=0)
                //     dp[i][j] = 1;
                else{
                    if(j<arr[i-1])
                        dp[i][j]=dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[n][sum];
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}