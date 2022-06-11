// help a theif

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

int maxCoins(int A[], int B[], int T, int N) {
        int ans=0;
        vector<pair<int, int>> p;
        
        for(int i=0; i<N; i++)
        {
            p.push_back({B[i], A[i]});
        }
        sort(p.rbegin(), p.rend());
        
        int i=0;
        while(T && i<N)
        {
            if(p[i].second>=T){
                ans += T * p[i].first;
                T=0;
            }
            else
            {
                T -= p[i].second;
                ans += p[i].second * p[i].first;
            }
            i++;
        }
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}