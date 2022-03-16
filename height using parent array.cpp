// Height using parent array

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
// ll max(ll x, ll y)
// {
//     return (x>y)?x:y;
// }
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
    int N;
    cin>>N;

    int arr[N];
    for(int i=0; i<N; i++)
        cin>>arr[i];

    height[N] = {0};
    height[0] = 1;

    for(int i=1; i<N; i++)
        height[i] = height[arr[i]]+1;

    cout<<height[N-1]<<endl;

    return;
}

int main(){
    solve();
    return 0;
}