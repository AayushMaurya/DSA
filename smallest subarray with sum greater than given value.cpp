// find length of smallest sub array with sum greater than given value

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
    ll sum[n+1], s=0;
    sum[0]=0;
    for (int i=0 ; i<n ; i++){
        cin>>arr[i];
        s += arr[i];
        sum[i+1] = s;
    }

    ll i=0, j=1, mi=n+1;
    while(i<n+1 && j<n+1)
    {
        if(sum[j]-sum[i] < k)
            j++;
        else{
            mi = min(mi, j-i);
            i++;
        }
    }

    if(mi == n+1)
        mi = -1;
    cout<<mi<<endl;

    return;
}

int main()
{
	solve();
	return 0;
}