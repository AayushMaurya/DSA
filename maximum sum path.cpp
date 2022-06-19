// Maximum sum path

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


int maximumPath(int n, vector<vector<int>> Matrix)
    {
        if(n==1)
            return Matrix[0][0];
            
        int ans = INT_MIN;
        for(int i=n-2; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(j==0)
                    Matrix[i][j] += max(Matrix[i+1][j+1], Matrix[i+1][j]);
                else if(j==n-1)
                    Matrix[i][j] += max(Matrix[i+1][j], Matrix[i+1][j-1]);
                else 
                    Matrix[i][j] += max(Matrix[i+1][j+1], max(Matrix[i+1][j], Matrix[i+1][j-1]));
                
                
            if(i==0)
                ans = max(ans, Matrix[i][j]);
            }
        }
        
        return ans;
    }
