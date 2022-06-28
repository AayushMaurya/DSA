// Killing spree

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

long long int killinSpree(long long int n)
    {
        long long int l=1, r=sqrt(n);
        long long int  ans=0;
        while(l<=r)
        {
            long long int mid = (l+r)/2;
            
            if((mid*(mid+1)*(2*mid + 1))/6 <= n){
                ans = max(ans, mid);
                l=mid+1;
            }
            else
                r = mid-1;
        }
        return ans;
    }