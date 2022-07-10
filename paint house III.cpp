// Paint House III

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

int solve(int index, int last, vector<int>& houses, vector<vector<int>>& cost, int n, int target, vector<vector<vector<int>>>& dp)
    {
        if(target<0)
            return INT_MAX;
        
        if(index == houses.size())
        {
            if(target == 0)
                return 0;
            else
                return INT_MAX;
        }
        
        if(dp[index][last][target]!=-1)
            return dp[index][last][target];
        
        int ans=INT_MAX;
        if(houses[index]==0)
        {
            for(int i=0; i<n; i++)
            {
                int res = solve(index+1, i+1, houses, cost, n, (last==i+1)?target:target-1, dp);
                if(res != INT_MAX)
                {
                    ans = min(ans, res + cost[index][i]);
                }
            }
        }
        else{
            ans = min(ans, solve(index+1, houses[index], houses, cost, n, (last==houses[index])?target:target-1, dp));
        }
        
        return dp[index][last][target] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(target+1, -1)));
        
        int ans = solve(0, 0, houses, cost, n, target, dp);
        if(ans == INT_MAX)
            return -1;
        return ans;
    }