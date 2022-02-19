// Activity selection

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
    int n;
    cin>>n;

    int start[n], end[n];

    for (int i = 0; i < n; ++i)
        cin>>start[i];
    for(int i=0; i<n; i++)
        cin>>end[i];

    std::vector<pair<int, int>> v;

    for(int i=0; i<n; i++)
        v.push_back({end[i], start[i]});

    sort(v.begin(), v.end());
    int res=1;
    pair<int, int> temp=v[0];

    for(int i=1; i<n; i++)
    {
        if(v[i].second > temp.first)
        {
            res++;
            temp=v[i];
        }
    }

    cout<<res<<endl;

    return;
}

int main(){
    solve();
    return 0;
}