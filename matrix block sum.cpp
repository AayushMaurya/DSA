// Matrix Block Sum

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


int helper(int row1, int col1, int row2, int col2, vector<vector<int>> &mat)
    {
        if(row1 == 0 && col1 == 0) return mat[row2][col2];
    if(row1 > 0 && col1 > 0) return mat[row2][col2] + mat[row1-1][col1-1] - mat[row1-1][col2] - mat[row2][col1-1];
    if(row1 > 0 && col1 == 0) return mat[row2][col2] - mat[row1-1][col2];
    return mat[row2][col2] - mat[row2][col1-1];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
    int cols = mat[0].size();
    
    /* Computing the cummulative sum of the matrix */
    for(int row=1;row<mat.size();row++) mat[row][0] += mat[row-1][0];
    for(int col=1;col<mat[0].size();col++) mat[0][col] += mat[0][col-1];
    
    for(int row=1;row<mat.size();row++){
        for(int col=1;col<mat[0].size();col++){
            mat[row][col] += (mat[row-1][col] + mat[row][col-1] - mat[row-1][col-1]);
        }
    }
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        
        for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            int row1 = ((row-k) < 0) ? 0 : (row-k);
            int row2 = ((row+k) >= rows) ? rows-1 : (row+k);
            int col1 = ((col-k) < 0) ? 0 : (col-k);
            int col2 = ((col+k) >= cols) ? cols-1 : (col+k);
            
            ans[row][col] = helper(row1, col1, row2, col2, mat);
        }
    }
    return ans;
    }

int main(){
    
    int n;
    cin>>n;
vector<vector<int>> vec(n, vector<int>(n));
for(int i=0; i<n; i++)
    cin>>vec[i][0]>>vec[i][1];

cout<<solve(vec, n, n)<<endl;
    return 0;
}