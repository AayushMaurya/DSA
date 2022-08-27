// Largest Local Values in a Matrix

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

vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        
        for(int i=0; i<=n-3; i++)
        {
            for(int j=0; j<=n-3; j++)
            {
                int res = INT_MIN;
                for(int x=i; x<i+3; x++)
                {
                    for(int y=j; y<j+3; y++)
                        res = max(res, grid[x][y]);
                }
                ans[i][j] = res;
            }
        }
        return ans;
    }