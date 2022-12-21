// Number of islands in each step

#include <bits/stdc++.h>
using namespace std;

 void dfs(int x, int y, vector<vector<int>> & matrix, vector<vector<bool>> &vis)
    {
        vis[x][y] = true;
        
        if(x+1<matrix.size() && matrix[x+1][y] == 1 && !vis[x+1][y])
            dfs(x+1, y, matrix, vis);
        if(y+1<matrix[0].size() && matrix[x][y+1] == 1 && !vis[x][y+1])
            dfs(x, y+1, matrix, vis);
        if(x-1>=0 && matrix[x-1][y] == 1 && !vis[x-1][y])
            dfs(x-1, y, matrix, vis);
        if(y-1>=0 && matrix[x][y-1] == 1 && !vis[x][y-1])
            dfs(x, y-1, matrix, vis);
    }
  
    int solve(vector<vector<int>> &matrix)
    {
        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == 1 && !vis[i][j])
                {
                    ans ++;
                    dfs(i, j, matrix, vis);
                }
            }
        }
        
        return ans;
    }
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &A) {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        int k = A.size();
        vector<int> ans(k);
        
        for(int i=0; i<k; i++)
        {
            int x = A[i][0], y = A[i][1];
            matrix[x][y] = 1;
            ans[i] = solve(matrix);
        }
        
        return ans;
    }