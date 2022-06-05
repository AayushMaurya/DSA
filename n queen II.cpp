// N queens II

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

 int solve(int col, vector<int>& leftrow, vector<int>& upperd, vector<int>& lowerd, int n)
    {
        if(col==n)
            return 1;
        
        int ans=0;
        for(int row=0; row<n; row++)
        {
            if(leftrow[row]==0 && lowerd[row+col]==0 && upperd[n-1+col-row]==0)
            {
                leftrow[row]=1;
                upperd[n-1+col-row]=1;
                lowerd[col+row]=1;
                ans+=solve(col+1, leftrow, upperd, lowerd, n);
                leftrow[row]=0;
                upperd[n-1+col-row]=0;
                lowerd[col+row]=0;
            }
        }
        return ans;
    }
    
    int totalNQueens(int n) {
        vector<int> lowerd(2*n-1, 0);
        vector<int> upperd(2*n-1, 0);
        vector<int> leftrow(n, 0);
        
        return solve(0, leftrow, upperd, lowerd, n);
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}