// Minimum lines to represent a line chart

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

int minimumLines(vector<vector<int>>& sp) {
        int n=sp.size();
        if(n==1)
            return 0;
        if(n==2)
            return 1;
        
        int ans=1;
        sort(sp.begin(), sp.end());
        int dx = sp[1][0]-sp[0][0];
        int dy = sp[1][1]-sp[0][1];
        
        for(int i=2; i<n; i++)
        {
            int _dx = sp[i][0]-sp[i-1][0];
            int _dy = sp[i][1]-sp[i-1][1];
            if(_dx*1LL*dy == _dy*1LL*dx)
                continue;
            ans++;
            dx=_dx;
            dy=_dy;
        }
        
        return ans;
        
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}