// Equillibrium point

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

int equilibriumPoint(long long a[], int n) {
        long long sum=0;
        for(int i=0; i<n; i++)
            sum+=a[i];
        int sum1=0;
        
        for(int i=0; i<n; i++)
        {
            sum-=a[i];
            if(sum==sum1)
                return i+1;
            sum1+=a[i];
        }
        return -1;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}