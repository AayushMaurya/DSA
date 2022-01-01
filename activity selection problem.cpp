// N meeting in a room

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

void solve(){
    int n;
    cin>>n;
    int start[n], end[n];

    for(int i=0 ; i<n ; i++)
        cin>>start[i];

    for(int i=0 ; i<n ; i++)
        cin>>end[i];

    vector<pair<int, int>> period;

    for(int i=0 ; i<n ; i++)
    {
        period.push_back(make_pair(end[i], start[i]));
    }

    sort(period.begin(), period.end());

    int count=1, index=0;

    for(int i=1 ; i<n ; i++)
    {
        if(period[i].second > period[index].first)
        {
            count++;
            index=i;
        }
    }

    cout<<count<<endl;

    return;
}

int main(){
    solve();
    return 0;
}