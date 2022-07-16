// Stones on the table

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define pii pair<int, int>
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

int main()
{
    ll n;
    cin>>n;
    string str;
    cin>>str;

    ll ans=0;
    for(int i=1; i<n; i++)
    {
        if(str[i] == str[i-1])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}