// three way partitioning of an array around a given value

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
    ll n, a, b;
    cin>>n>>a>>b;

    ll arr[n];
    for(ll i=0 ; i<n ; i++)
        cin>>arr[i];

    ll l=0, r=n-1;

    for(ll i=0 ; i<=r ;)
    {
        if(arr[i] < a)
        {
            if(i==l)
            {
                l++;
                i++;
            }
            else
                swap(&arr[i++], &arr[l++]);
        }
        else if(arr[i]>b)
            swap(&arr[i], &arr[r--]);
        else
            i++;
    }

    for(ll i=0 ; i<n ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return;
}

int main()
{
	solve();
	return 0;
}