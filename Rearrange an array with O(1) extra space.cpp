// Rearrange the array with O(1) extra space

// rearrange tha array such that arr[i] = arr[arr[i]]

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
    for(int i=0; i<n; i++)
        cin>>arr[i];

    // storing arr[i] and arr[arr[i]] in same index by using divident = divisor*quotient + rem
    for(int i=0; i<n; i++)
        arr[i] = arr[i] + (arr[arr[i]]%n)*n;

    for(int i=0; i<n; i++)
        arr[i] = arr[i]/n;
    return;
}

int main(){
    solve();
    return 0;
}