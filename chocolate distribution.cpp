// Chocolate Distribution Problem

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
    ll n, m;
    cin>>n>>m;
    vector<ll> a;

    for(ll i=0 ; i<n ; i++)
    {
        ll temp;
        cin>>temp;
        a.pb(temp);
    }

    // sort(a.begin(), a.end());
    //     long long start=0, end=n-1;
        
    //     while(end-start+1 > m)
    //     {
    //         if(a[start+1]-a[start] > a[end]-a[end-1])
    //             start++;
    //         else
    //             end--;
    //     }

    // cout<<a[end]-a[start]<<endl;

    // the above solution will not work for {2, 26, 26, 26, 27, 97, 98, 99, 100} m=5
        
    sort(a.begin(), a.end());
        
        long long min_diff = INT_MAX;
        
        for (int i = 0; i + m - 1 < n; i++) {
            long long diff = a[i + m - 1] - a[i];
            if (diff < min_diff)
                min_diff = diff;
        }
        
        cout<<min_diff<<endl;

    return;
    
}

int main()
{
	solve();
	return 0;
}