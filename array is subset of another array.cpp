// Find whether an array is subset of another array

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
	int n, m;
    cin>>n>>m;

    int a1[n], a2[m];
    for (int i=0; i<n; ++i)
    {
        cin>>a1[i];
    }
    for(int i=0 ; i<m ; i++)
    {
        cin>>a2[i];
    }

    unordered_set<int> s;

    for (int i=0 ; i<n ; i++)
        s.insert(a1[i]);

    int p=s.size();

    for (int i=0 ; i<m ; i++)
        s.insert(a2[i]);

    if(s.size() == p)
        cout<<"Yes"<<endl;
    else 
        cout"No"<<endl;

    return;
}

int main()
{
	solve();
	return 0;
}