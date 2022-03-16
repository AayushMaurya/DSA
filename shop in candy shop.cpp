// Shop in Candy Store

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
    int N, K;
    cin>>N>>K;

    int candies[N];
    for(int i=0; i<N; i++)
        cin>>candies[i];

    sort(candies, candies+N);
        int res1 = 0, res2 = 0;
        int len = N;
        for(int i=0; i<len; i++)
        {
            res1+=candies[i];
            len -= K;
        }
        len = 0;
        for(int i=N-1; i>=len; i--)
        {
            res2+=candies[i];
            len += K;
        }
        cout<<res1<<" "<<res2<<endl;

    return;
}

int main(){
    solve();
    return 0;
}