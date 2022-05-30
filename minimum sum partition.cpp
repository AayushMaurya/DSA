// Minimum sum partition

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

int helper(int nums[], int index, int sum, int total, vector<vector<int>>& dp)
    {
        if(index<0)
            return abs(total-sum-sum);
        if(dp[index][sum]!=-1)
            return dp[index][sum];
            
        dp[index][sum] = min(helper(nums, index-1, sum, total, dp), helper(nums, index-1, sum+nums[index], total, dp));
        return dp[index][sum];
    }
  
    int minDifference(int nums[], int n)  { 
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=nums[i];
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return helper(nums, n-1, 0, sum, dp);
    } 

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}