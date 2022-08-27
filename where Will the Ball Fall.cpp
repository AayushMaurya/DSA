// Where Will the Ball Fall

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

int solve(int x, int y, vector<vector<int>>& grid, int m, int n)
    {
        if(x==m)
            return ((y>=n) ? -1 : y);
        if(y < 0 || y >= n)
            return -1;
        
        if(grid[x][y]==1)
        {
            if(y+1<n && grid[x][y+1]==-1)
                return -1;
            
            return solve(x+1, y+1, grid, m, n);
        }
        else{
            if(y-1>=0 && grid[x][y-1]==1)
                return -1;
            
            return solve(x+1, y-1, grid, m, n);
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> ans(n);
        
        for(int i=0; i<n; i++)
            ans[i] = solve(0, i, grid, m, n);
        
        return ans;
    }