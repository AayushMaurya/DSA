// find all possible path from top to bottom

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

void solve(int x, int y, int n, int m, vector<int>& res, vector<vector<int>>& ans, vector<vector<int>>& grid)
    {
        if(x==n && y==m)
        {
            res.push_back(grid[x][y]);
            ans.push_back(res);
            res.pop_back();
            return;
        }
        res.push_back(grid[x][y]);
        if(x+1<=n)
        {
            solve(x+1, y, n, m, res, ans, grid);
        }
        if(y+1<=m)
        {
            solve(x, y+1, n, m, res, ans, grid);
        }
        res.pop_back();
        return;
    }

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> ans;
        vector<int> res;
        solve(0, 0, n-1, m-1, res, ans, grid);
        
        return ans;
    }