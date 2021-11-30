// find sub array with maximum product in given array

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
    for(ll i=0 ; i<n ; i++)
        cin>>arr[i];

    ll ma=arr[0], mi=arr[0], ans=arr[0];

    for(ll i=1 ; i<n ; i++)
    {
        if(arr[i]<0)
            swap(&ma, &mi);

        ma = max(arr[i], arr[i]*ma);
        mi = min(arr[i], arr[i]*mi);

        ans=max(ma, ans);
    }
    cout<<ans<<endl;
    return;
}

int main()
{
	solve();
	return 0;
}