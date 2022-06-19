// Longest possible routes in matrix with hurdles

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


int dfs(vector<vector<int>> matrix, int x, int y, int xd, int yd)
    {
        if(x == xd && y == yd)
        {
            return 0;
        }
        
        if(x>=matrix.size() || y>=matrix[0].size() || x<0 || y<0 || matrix[x][y] == 0)
            return -1;
        
        if(matrix[x][y] == 2)
            return -1;
        
        matrix[x][y] = 2;
        
        int ans = -1;
        
        ans = max(ans, dfs(matrix, x+1, y, xd, yd));
        ans = max(ans, dfs(matrix, x, y+1, xd, yd));
        ans = max(ans, dfs(matrix, x-1, y, xd, yd));
        ans = max(ans, dfs(matrix, x, y-1, xd, yd));
        
        matrix[x][y] = 1;
        
        if(ans == -1)
            return -1;
        
        return ans+1;
    }

    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        if(matrix[xs][ys] == 0 || matrix[xd][yd] == 0)
            return -1;
            
        int ans = dfs(matrix, xs, ys, xd, yd);
        
        return ans;
    }
