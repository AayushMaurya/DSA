// Partition Equal Subset Sum

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

 bool helper(vector<int>& nums, int index, int sum1, int sum2, vector<vector<int>>& dp)
    {
        if(sum1==sum2)
            return true;
        if(sum1<sum2)
            return false;
        if(index<0)
            return false;
        if(dp[index][sum1]!=-1)
            return dp[index][sum1]==1 ? true : false;
        
        bool ans = helper(nums, index-1, sum1-nums[index], sum2+nums[index], dp) || helper(nums, index-1, sum1, sum2, dp);
        if(ans==true)
            dp[index][sum1] = 1;
        else
            dp[index][sum1] = 0;
        
        return ans;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum1=0;
        for(int i=0; i<nums.size(); i++)
            sum1+=nums[i];
        vector<vector<int>> dp(nums.size(), vector<int>(sum1+1, -1));
        return helper(nums, nums.size()-1, sum1, 0, dp);
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}