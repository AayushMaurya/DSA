// Maximum trains for which stoppage can be provided

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

struct Train{
    int arrival;
    int departure;
    int platform;
};

int maxStop(int n, Train arr[], int m)
{
    map<int, vector<pair<int, int>>> plat;

    for(int i=0 ; i<n ; i++)
    {
        plat[arr[i].platform].push_back({arr[i].departure, arr[i].arrival});
    }

    int res=0;

    for(auto itr = plat.begin() ; itr != plat.end() ; itr++)
    {
        sort(itr->second.begin(), itr->second.end());

        int count = 1, index=0;
         for(int i=1 ; i<itr->second.size() ; i++)
         {
            if(itr->second[i].second > itr->second[index].first)
            {
                count++;
                index = i;
            }
         }
        res+=count;
    }

    return res;
}

void solve()
{
    int m, n;
    cin>>n>>m;

    Train arr[n];

    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i].arrival>>arr[i].departure>>arr[i].platform;
    }

    cout<<maxStop(n, arr, m)<<endl;

    return;
}

int main(){
    solve();
    return 0;
}