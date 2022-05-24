// Maximal square

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


int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int ans=0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == '0')
                    dp[i][j] = 0;
                else if(i==0 || j==0)
                    dp[i][j] = matrix[i][j]-'0';
                else{
                    dp[i][j] =1+ min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
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