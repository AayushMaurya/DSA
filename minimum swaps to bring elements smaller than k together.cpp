// minimum swaps required to bring the elements smaller than k together

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
    ll n, k;
    cin>>n>>k;
    ll arr[n];
    for(ll i=0 ; i<n ; i++)
        cin>>arr[i];

    ll count=0;

    for(int i=0 ; i<n ; i++)
    {
        if(arr[i]<=k)
            count++;
    }

    ll swap=0;

    for(int i=0 ; i<count ; i++)
    {
        if(arr[i]>k)
            swap++;
    }

    ll res=swap;

    for(ll i=count ; i<n ; i++)
    {
        if(arr[i]<=k && arr[i-count]>k)
            swap--;
        else if(arr[i]>k && arr[i-count]<=k)
            swap++;
        res=min(res, swap);
    }

    cout<<res<<endl;

    return;
}

int main()
{
	solve();
	return 0;
}