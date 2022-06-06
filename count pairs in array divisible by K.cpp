// Count pairs in array dividible by K

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

long long countKdivPairs(int A[], int n, int K)
    {
        unordered_map<int, int> mp;
        
        long long ans=0;
        
        for(int i=0; i<n; i++)
        {
            int x=(K-A[i]%K)%K;
            if(mp[x])
                ans+=mp[x];
            mp[A[i]%K]++;
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