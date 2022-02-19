// Rearrange geek and his classmates

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

    int a[n];
    for(int i=0; i<n; i++)
        a[i] = a[i] + (a[a[i]]%n)*n;

    for(int i=0; i<n; i++)
        a[i] = a[i]/n;

    for (int i = 0; i < n; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return;
}

int main(){
    solve();
    return 0;
}