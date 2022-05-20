#include<bits/stdc++.h>
using namespace std;
# define ll long long int

ll max(ll x, ll y)
{
    return (x>y) ? x : y;
}

int main()
{
    int mat[26][26] = {0};
    for(int i=3 ; i<=22 ; i++)
    {
        for( int j=3 ; j<=22 ; j++)
            cin>>mat[i][j];
    }

    ll res = 0;
    for(int i=3 ; i<=22 ; i++)
    {
        for(int j=3 ; j<=22 ; j++)
        {
            ll temp = mat[i][j]*mat[i][j+1]*mat[i][j+2]*mat[i][j+3];
            res = max(res, temp);
            temp = mat[i][j]*mat[i+1][j]*mat[i+2][j]*mat[i+3][j];
            res = max(res, temp);
            temp = mat[i][j]*mat[i+1][j+1]*mat[i+2][j+2]*mat[i+3][j+3];
            res = max(res, temp);
            temp = mat[i][j]*mat[i-1][j-1]*mat[i-2][j-2]*mat[i-3][j-3];
             res = max(res, temp);
            temp = mat[i][j]*mat[i+1][j-1]*mat[i+2][j-2]*mat[i+3][j-3];
            res = max(res, temp);
            temp = mat[i][j]*mat[i-1][j+1]*mat[i-2][j+2]*mat[i-3][j+3];
            res = max(res, temp);
        }
    }

    cout<<res<<endl;
    return 0;
}
