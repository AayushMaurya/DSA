// Matrix Exponentiation

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

vector<vector<long long int>> multiply(vector<vector<long long int>>& a, vector<vector<long long int>> b)
    {
        int n=2;
        vector<vector<long long int>> ans(2, vector<long long int>(2, 0));
        
        for(long long int i=0; i<n; i++)
        {
            for(long long int j=0; j<n; j++)
            {
                for(long long int k=0; k<n; k++)
                    ans[i][j] += (a[i][k]%1000000007 * b[k][j]%1000000007)%1000000007;
            }
        }
        
        return ans;
    }

    vector<vector<long long int>> matrixExponentiate(vector<vector<long long int>>& a, long long int n)
    {
        if(n==0)
            return {{1, 0}, {0, 1}};
            
        if(n==1)
            return a;
            
        vector<vector<long long int>> temp = matrixExponentiate(a, n/2);
        vector<vector<long long int>> ans = multiply(temp, temp);
        
        if(n%2==1)
        {
            ans = multiply(ans, a);
        }
        
        return ans;
        
    }

    int FindNthTerm(long long int n) {
        vector<vector<long long int>> a = {{1, 1}, {1, 0}};
        
        vector<vector<long long int>> ans = matrixExponentiate(a, n);
        
        return ans[0][0]%1000000007;
    }