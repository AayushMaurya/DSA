// Count number of subarrays with given XOR K


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

int solve(vector<int> &A, int B) {

    for(int i=1; i<A.size(); i++)
        A[i] = A[i]^A[i-1];
    
    int ans=0;
    map<int, int> mp;
    mp[0]++;
    for(int i=0; i<A.size(); i++)
    {
        ans += mp[B^A[i]];
        mp[A[i]]++;
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