// Trapping rain water problem

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
    ll n, sum=0;
    cin>>n;
    ll arr[n];
    for(ll i=0 ; i<n ; i++) cin>>arr[i];

    ll rightMax[n], leftMax[n];
    
    leftMax[0] = 0;
    rightMax[n-1] = 0;

    for(ll i=1 ; i<n ; i++)
        leftMax[i] = max(arr[i-1], leftMax[i-1]);

    for(ll i=n-2 ; i>=0 ; i--)
        rightMax[i] = max(arr[i+1], rightMax[i+1]);

    for(ll i=1 ; i<n-1 ; i++)
    {
        int temp = min(leftMax[i], rightMax[i])-arr[i];
        if(temp>=0)
            sum+=temp;
    }
    cout<<sum<<endl;
    return;
}

int main()
{
	solve();
	return 0;
}