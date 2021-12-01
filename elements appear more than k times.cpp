// Given an array of size n and a number k, find all the numbers that appear more than n/k times

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
    unordered_map<int, int> m;
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
        m[arr[i]]++;
    }

    ll x = n/k;
    for(auto it: m)
    {
        if(it.second > x)
            cout<<it.first<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
	solve();
	return 0;
}