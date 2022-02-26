// Return two prime numbers
// Sieve of Eratosthenes

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

    vector<bool> sieve(n+1, true);

    sieve[0]=false;
    sieve[1]=false;

    for(int i=2; i*i<=n; i++)
    {
        if(sieve[i])
        {
            for(int j=i*i; j<=n; j+=i)
                sieve[j]=false;
        }
    }
    
    for(int i=2; i<=n; i++)
    {
        if(sieve[i] && sieve[n-i])
        {
            cout<<i<<" "<<n-i<<endl;
            return;
        }
    }

    return;
}

int main(){
    solve();
    return 0;
}