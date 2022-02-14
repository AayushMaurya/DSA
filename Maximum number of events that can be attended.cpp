// Maximum number of events that can be attended

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
    for(int i=0; i<n; i++)
        cin>>start[i];
    for(int i=0; i<n; i++)
        cin>>end[i];

    vector<pair<int, int>> vec;
    for(int i=0; i<n; i++)
        vec.push_back({start[i], end[i]});

    sort(vec.begin(), vec.end());
    int curr=0;
    int i=0, ans=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(i<n || !pq.empty())
    {
        if(pq.size()==0)
            curr=vec[i].first;

        while(i<n && vec[i].first<=curr)
            pq.push(vec[i++].second);

        pq.pop();

        curr++;
        ans++;

        while(!pq.empty() && pq.top()<curr)
            pq.pop();
    }
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}