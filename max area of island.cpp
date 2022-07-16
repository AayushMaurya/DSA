// Max area of island

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

int solve(int x, int y, vector<vector<int>>& grid)
    {
        if(grid[x][y] == 0)
            return 0;
        int ans = 1;
        grid[x][y] = 0;
        
        if(x+1<grid.size())
            ans += solve(x+1, y, grid);
        if(y+1<grid[0].size())
            ans += solve(x, y+1, grid);
        if(x-1>=0)
            ans += solve(x-1, y, grid);
        if(y-1>=0)
            ans += solve(x, y-1, grid);
        
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0)
                    continue;
                ans = max(ans, solve(i, j, grid));
            }
        }
        
        return ans;
    }