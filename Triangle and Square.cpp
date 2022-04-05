// Triangle and Square

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

int solve(int b)
{
    int res = b/2 - 1;
    res = res*(res+1)/2;
    return res;
}


int main(){
    int n;
    cin>>n;

    
    cout<<solve(n)<<endl;
    return 0;
}