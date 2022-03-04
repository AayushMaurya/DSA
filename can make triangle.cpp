// Can Make Triangle

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

    int A[N];
    for(int i=0; i<N; i++)
        cin>>A[i];

    vector<int> res;
        for(int i=1; i<N-1; i++)
        {
            if((A[i-1]+A[i])>A[i+1]&&(A[i+1]+A[i])>A[i-1]&& (A[i-1]+A[i+1])>A[i] )
                res.push_back(1);
            else res.push_back(0);
        }
    for(auto itr=res.begin(); itr!=res.end(); res++)
        cout<<res[i]<<" ";
    cout<<endl;

    return;
}

int main(){
    solve();
    return 0;
}