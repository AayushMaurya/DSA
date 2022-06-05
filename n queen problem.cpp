// N Queen problem

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

void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDigonal,  vector<int>& lowerDigonal, int n)
    {
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++)
        {
            if(leftRow[row]==0 && lowerDigonal[row+col]==0 && upperDigonal[n-1 + col - row]==0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDigonal[row+col]=1;
                upperDigonal[n-1 + col - row]=1;
                solve(col+1, board, ans, leftRow, upperDigonal, lowerDigonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDigonal[row+col] = 0;
                upperDigonal[n-1 + col - row] = 0;
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        
        string s(n, '.');
        
        for(int i=0; i<n; i++)
            board[i] = s;
        
        vector<int> leftRow(n, 0), upperDigonal(2*n - 1, 0), lowerDigonal(2*n - 1, 0);
        
        solve(0, board, ans, leftRow, upperDigonal, lowerDigonal, n);
        
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}