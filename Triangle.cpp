// Triangle

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


int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(i==0)    dp[i][j] = triangle[i][j];
                else{
                    if(j==0)
                        dp[i][j] = triangle[i][j] + dp[i-1][j];
                    else if(j==i)
                        dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                    else
                        dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<n; i++)
            ans=min(ans, dp[n-1][i]);
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