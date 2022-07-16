// Partition array to k subsets 
// bit masking

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define pii pair<int, int>
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

bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp((1<<n), -1);
        
        dp[0] = 0;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0)
            return false;
        int target = sum/k;
        
        for(int mask=0; mask<(1<<n); mask++)
        {
//             not possible at this state;
            if(dp[mask] == -1)
                continue;
            
            for(int i=0; i<n; i++)
            {
//                 if visited
                if(mask & (1<<i))
                    continue;
                if(dp[mask]+nums[i] > target)
                    continue;
                
                dp[mask | (1<<i)] = (dp[mask] + nums[i]) %target;
            }
        }
        
        return dp[(1<<n) - 1] == 0;
    }