// Stickler Thief

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

    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }

    int dpinc[n], dpex[n];
    dpinc[0] = arr[0];
    dpex[0] = 0;

    for(int i=1; i<n; i++)
    {
        dpinc[i] = dpex[i-1] + arr[i];
        dpex[i] = max(dpex[i-1], dpinc[i-1]);
    }

    cout<<max(dpinc[n-1], dpex[n-1]);

    return;
}

int main(){
    solve();
    return 0;
}