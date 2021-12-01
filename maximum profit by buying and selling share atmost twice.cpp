// Maximum profit by buying and selling a share atmost twice

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
	ll n;
    cin>>n;
    ll arr[n];
    for(int i=0 ; i<n ; i++)
        cin>>arr[i];

    vector<ll> v;

    ll min=arr[0], ma=0;
    for(ll i=1 ; i<n ; i++)
    {
        if(arr[i] < min){
            min = arr[i];
            v.push_back(ma);
            ma=0;
        }
        else{
            ll temp = arr[i] - min;
            ma = max(temp, ma);
        }
    }
    v.push_back(ma);

    sort(v.begin(), v.end());

    // for(auto it: v)
    //     cout<<it<<" ";
    // cout<<endl;
    if(v.size() >=2)
        cout<<*(v.end()-1)+*(v.end()-2)<<endl;
    else
        cout<<*(v.end()-1)<<endl;
    return;
}

int main()
{
	solve();
	return 0;
}