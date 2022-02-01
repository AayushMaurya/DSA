// Minimum platform problem

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

    int arr[n], dep[n];

    for(int i=0 ; i<n ; i++)
        cin>>arr[i];

    for(int i=0 ; i<n ; i++)
        cin>>dep[i];

    sort(arr, arr+n);
    sort(dep, dep+n);

    int res=0, j=0, i=1;

    while(i<n)
    {
        if(arr[i]<=dep[j])
            res++;
        else
            j++;
        i++;
    }

    cout<<res<<endl;

    return;
}

int main(){
    solve();
    return 0;
}