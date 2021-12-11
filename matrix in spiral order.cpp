// traverse given matrix in spiral order

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


void solve()
{
    int r, c;
    cin>>r>>c;

    vector<int> res;

    int a[r][c];

    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
            cin>>a[i][j];
    }

    int m=0, n=0, i;

    while(m<r && n<c)
    {
        for(i=n ; i<c ; i++)
            res.pb(a[m][i]);
        m++;

        for(i=m ; i<r ; i++)
            res.pb(a[i][c-1]);
        c--;

        if(m<r)
        {
            for(i=c-1 ; i>=n ; i--)
                res.pb(a[r-1][i]);
            r--;
        }

        if(n<c)
        {
            for(i=r-1 ; i>=m ; i--)
                res.pb(a[i][n]);
            n++;
        }

    }

    for(int it=0 ; it<res.size() ; it++)
        cout<<res[it]<<" ";
    cout<<endl;

    return;
}

int main()
{
	solve();
	return 0;
}