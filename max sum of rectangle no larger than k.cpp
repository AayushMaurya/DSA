// max sum of rectangle no larger than k
// TC = (m*n)^2

#include <bits/stdc++.h>
using namespace std;


int solve(int x, int y, vector<vector<int>>& matrix, int k)
    {
        
        int ans = INT_MIN;
        for(int i=x; i<matrix.size(); i++)
        {
            for(int j=y; j<matrix[0].size(); j++)
            {
                int a = (x>0 && y>0) ? matrix[x-1][y-1] : 0;
                int b = (x>0) ? matrix[x-1][j] : 0;
                int c = (y>0) ? matrix[i][y-1] : 0;
                
                int res = matrix[i][j] - b - c + a;
                if(res > ans && res <=k)
                    ans = res;
            }
        }
        
        return ans;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(j==0 && i==0)
                    continue;
                else if(i==0)
                    matrix[i][j] += matrix[i][j-1];
                else if(j==0)
                    matrix[i][j] += matrix[i-1][j];
                else
                    matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
            }
        }
        
        int ans = INT_MIN;
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                int temp = solve(i, j, matrix, k);
                if(temp > ans)
                    ans = temp;
            }
        }
        
        return ans;
    }