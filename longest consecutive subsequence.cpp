// find longest consecutive subsequence in given array
// this is done usind unordered set, therefore it will 
// work on array with large number of elememts

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
    ll arr[n], ans=0;
    for(ll i=0 ; i<n ; i++)
        cin>>arr[i];

    unordered_set<ll> s;
    // search, insertion and deletion is of constant time complexity in case of unordered_set

    for(ll i=0 ; i<n ; i++)
        s.insert(arr[i]);

    for(ll i=0 ; i<n ; i++)
    {
        if(s.find(arr[i]-1) == s.end())
        {
            ll j = arr[i];

            while(s.find(j) != s.end())
                j++;

            ans = max(ans, j-arr[i]);
        }
    }
    cout<<ans<<endl;
    return;
}

int main()
{
	solve();
	return 0;
}