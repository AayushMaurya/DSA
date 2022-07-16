// Ones and Zeros
// recursion + memoization

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

 int solve(int index, int m, int n, vector<pair<int, int>>& arr, vector<vector<vector<int>>>& dp)
    {
        if(index>=arr.size())
            return 0;
        
        if(dp[index][m][n]!=-1)
            return dp[index][m][n];
        
        int take=0, escape=0;
        
        if(m-arr[index].first>=0 && n-arr[index].second>=0)
            take = 1 + solve(index+1, m-arr[index].first, n-arr[index].second, arr, dp);
        
        escape = solve(index+1, m, n, arr, dp);
        
        return dp[index][m][n] = max(take, escape);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> arr;
        
        for(auto itr: strs)
        {
            int a1=0, a2=0;
            for(auto ch: itr)
            {
                if(ch == '0')
                    a1++;
                else
                    a2++;
            }
            arr.push_back({a1, a2});
        }
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        int ans = solve(0, m, n, arr, dp);
        
        return ans;
    }