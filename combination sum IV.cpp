// Combination Sum IV

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

int helper(vector<int>& nums, int target, vector<int>& dp)
    {
        if(target==0)
            return 1;

        if(dp[target]!=-1)
            return dp[target];
        
        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(target-nums[i] >= 0)
                ans+=helper(nums, target-nums[i], dp);
        }
        dp[target] = ans;
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return helper(nums, target, dp);
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}