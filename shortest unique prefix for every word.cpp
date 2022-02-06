// Shortest unique prefix for every word

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
    string arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    vector<string> res;
    for(int i=0; i<n; i++)
    {
        int len=0;
        for(int j=0; j<n; j++)
        {
            if(i==j)
                continue;
            while(arr[i].substr(0, len) == arr[j].substr(0, len))
                len++;
        }
        res.pb(arr[i].substr(0, len));
    }

    for(int i=0; i<n; i++)
        cout<<res[i]<<" ";
    cout<<endl;

    return;
}

int main(){
    solve();
    return 0;
}